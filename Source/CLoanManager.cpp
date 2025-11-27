#include "../Include/CLoanManager.h"

// Helper method to get next ticket ID
int CLoanManager::getNextTicketID() {
    int iMaxID = 0;
    Node<CLoanTicket>* pCurrent = m_listTickets.getHead();
    
    while (pCurrent != NULL) {
        if (pCurrent->data.getTicketID() > iMaxID) {
            iMaxID = pCurrent->data.getTicketID();
        }
        pCurrent = pCurrent->pNext;
    }
    
    return iMaxID + 1;
}

// Constructor: Load data and set dependencies
CLoanManager::CLoanManager(CBookManager* pBookManager)
    : m_pBookManager(pBookManager), 
      m_strTicketFilePath("Data/PhieuMuon.txt"),
      m_strReaderFilePath("Data/BanDoc.txt"),
      m_iNextTicketID(1) {
    
    // Load tickets and readers from files
    CFileHandler::loadTickets(m_strTicketFilePath, m_listTickets);
    CFileHandler::loadReaders(m_strReaderFilePath, m_listReaders);
    
    // Initialize next ticket ID
    m_iNextTicketID = getNextTicketID();
}

// Parameterized constructor
CLoanManager::CLoanManager(CBookManager* pBookManager, const string& strTicketFilePath, const string& strReaderFilePath)
    : m_pBookManager(pBookManager),
      m_strTicketFilePath(strTicketFilePath),
      m_strReaderFilePath(strReaderFilePath),
      m_iNextTicketID(1) {
    
    // Load tickets and readers from files
    CFileHandler::loadTickets(m_strTicketFilePath, m_listTickets);
    CFileHandler::loadReaders(m_strReaderFilePath, m_listReaders);
    
    // Initialize next ticket ID
    m_iNextTicketID = getNextTicketID();
}

// Destructor: Save data
CLoanManager::~CLoanManager() {
    CFileHandler::saveTickets(m_strTicketFilePath, m_listTickets);
    CFileHandler::saveReaders(m_strReaderFilePath, m_listReaders);
}

// Borrow a book
bool CLoanManager::borrowBook(const string& strReaderID, const string& strBookID, const string& strBorrowDate, const string& strReturnDate) {
    // Check 1: Reader ID must exist
    CReader tempReader;
    tempReader.setID(strReaderID);
    CReader* pReader = m_listReaders.find(tempReader);
    
    if (pReader == NULL) {
        return false; // Reader not found
    }
    
    // Check 2: Book must exist AND Status must be 0 (Available)
    if (m_pBookManager == NULL) {
        return false; // Book manager not set
    }
    
    CBook* pBook = m_pBookManager->findBook(strBookID);
    
    if (pBook == NULL) {
        return false; // Book not found
    }
    
    if (pBook->getStatus() != BOOK_AVAILABLE) {
        return false; // Book is already borrowed
    }
    
    // Action 1: Create new CLoanTicket with auto-incremented ID
    int iNewTicketID = m_iNextTicketID;
    CLoanTicket newTicket(iNewTicketID, strReaderID, strBookID, strBorrowDate, strReturnDate, TICKET_BORROWING);
    
    // Action 2: Add ticket to list
    m_listTickets.add(newTicket);
    m_iNextTicketID++;
    
    // Action 3: Update Book Status to new TicketID
    m_pBookManager->updateBookStatus(strBookID, iNewTicketID);
    
    // Action 4: Save ticket file (book file is saved by CBookManager)
    CFileHandler::saveTickets(m_strTicketFilePath, m_listTickets);
    
    return true;
}

// Return a book
bool CLoanManager::returnBook(int iTicketID) {
    // Find the ticket
    CLoanTicket tempTicket;
    tempTicket.setTicketID(iTicketID);
    CLoanTicket* pTicket = m_listTickets.find(tempTicket);
    
    if (pTicket == NULL) {
        return false; // Ticket not found
    }
    
    // Check if already returned
    if (pTicket->getStatus() == TICKET_RETURNED) {
        return false; // Already returned
    }
    
    // Get book ID from ticket
    string strBookID = pTicket->getBookID();
    
    // Update Ticket Status to 0 (Returned)
    pTicket->setStatus(TICKET_RETURNED);
    
    // Update Book Status back to 0 (Available)
    if (m_pBookManager != NULL) {
        m_pBookManager->updateBookStatus(strBookID, BOOK_AVAILABLE);
    }
    
    // Save ticket file (book file is saved by CBookManager)
    CFileHandler::saveTickets(m_strTicketFilePath, m_listTickets);
    
    return true;
}

// Find a ticket by ID
CLoanTicket* CLoanManager::findTicket(int iTicketID) {
    CLoanTicket tempTicket;
    tempTicket.setTicketID(iTicketID);
    return m_listTickets.find(tempTicket);
}

// Find a reader by ID
CReader* CLoanManager::findReader(const string& strReaderID) {
    CReader tempReader;
    tempReader.setID(strReaderID);
    return m_listReaders.find(tempReader);
}

// Add a new reader
bool CLoanManager::addReader(const CReader& reader) {
    // Check for duplicate ID
    CReader tempReader;
    tempReader.setID(reader.getID());
    CReader* pExistingReader = m_listReaders.find(tempReader);
    
    if (pExistingReader != NULL) {
        return false; // ID already exists
    }
    
    // Add reader to list
    m_listReaders.add(reader);
    
    // Save to file immediately
    CFileHandler::saveReaders(m_strReaderFilePath, m_listReaders);
    
    return true;
}

// Delete a reader by ID
bool CLoanManager::deleteReader(const string& strReaderID) {
    // Create a temporary reader to search
    CReader tempReader;
    tempReader.setID(strReaderID);
    
    // Check if reader has any active loans
    Node<CLoanTicket>* pCurrent = m_listTickets.getHead();
    while (pCurrent != NULL) {
        if (pCurrent->data.getReaderID() == strReaderID && 
            pCurrent->data.getStatus() == TICKET_BORROWING) {
            return false; // Cannot delete reader with active loans
        }
        pCurrent = pCurrent->pNext;
    }
    
    // Remove reader from list
    bool bResult = m_listReaders.remove(tempReader);
    
    if (bResult) {
        // Save to file immediately
        CFileHandler::saveReaders(m_strReaderFilePath, m_listReaders);
    }
    
    return bResult;
}

// Get ticket list for display purposes
CGenericList<CLoanTicket>& CLoanManager::getTicketList() {
    return m_listTickets;
}

// Get reader list for display purposes
CGenericList<CReader>& CLoanManager::getReaderList() {
    return m_listReaders;
}

// Get ticket count
int CLoanManager::getTicketCount() const {
    return m_listTickets.getCount();
}

// Get reader count
int CLoanManager::getReaderCount() const {
    return m_listReaders.getCount();
}