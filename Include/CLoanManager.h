#ifndef CLOANMANAGER_H
#define CLOANMANAGER_H

#include "CLoanTicket.h"
#include "CReader.h"
#include "CGenericList.h"
#include "CFileHandler.h"
#include "CBookManager.h"

// Status constants for Loan Ticket
const int TICKET_RETURNED = 0;    // Book has been returned
const int TICKET_BORROWING = 1;   // Book is currently borrowed

class CLoanManager {
private:
    CGenericList<CLoanTicket> m_listTickets;  // List of loan tickets
    CGenericList<CReader> m_listReaders;      // List of readers
    CBookManager* m_pBookManager;             // Pointer to book manager
    string m_strTicketFilePath;               // Path to ticket data file
    string m_strReaderFilePath;               // Path to reader data file
    int m_iNextTicketID;                      // Next available ticket ID

    // Helper method to get next ticket ID
    int getNextTicketID();

public:
    // Constructor: Load data and set dependencies
    CLoanManager(CBookManager* pBookManager);
    CLoanManager(CBookManager* pBookManager, const string& strTicketFilePath, const string& strReaderFilePath);
    
    // Destructor: Save data
    ~CLoanManager();

    // Borrow a book
    bool borrowBook(const string& strReaderID, const string& strBookID, const string& strBorrowDate, const string& strReturnDate);
    
    // Return a book
    bool returnBook(int iTicketID);
    
    // Find a ticket by ID
    CLoanTicket* findTicket(int iTicketID);
    
    // Find a reader by ID
    CReader* findReader(const string& strReaderID);
    
    // Add a new reader
    bool addReader(const CReader& reader);
    
    // Delete a reader by ID
    bool deleteReader(const string& strReaderID);
    
    // Get ticket list for display purposes
    CGenericList<CLoanTicket>& getTicketList();
    
    // Get reader list for display purposes
    CGenericList<CReader>& getReaderList();
    
    // Get ticket count
    int getTicketCount() const;
    
    // Get reader count
    int getReaderCount() const;
};

#endif // CLOANMANAGER_H
