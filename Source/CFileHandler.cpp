#include "../Include/CFileHandler.h"
#include <fstream>
#include <sstream>

using namespace std;

// Helper method to split string by delimiter
void CFileHandler::split(const string& strLine, char cDelimiter, string arrResult[], int& iCount) {
    iCount = 0;
    stringstream ss(strLine);
    string strToken;
    
    while (getline(ss, strToken, cDelimiter)) {
        arrResult[iCount++] = strToken;
    }
}

// Load books from file
bool CFileHandler::loadBooks(const string& strPath, CGenericList<CBook>& list) {
    ifstream fileInput;
    fileInput.open(strPath.c_str());
    
    if (!fileInput.is_open()) {
        return false;
    }
    
    list.clear(); // Clear existing data
    
    string strLine;
    while (getline(fileInput, strLine)) {
        if (strLine.empty()) continue;
        
        string arrFields[9];
        int iCount = 0;
        split(strLine, '|', arrFields, iCount);
        
        if (iCount >= 9) {
            // Format: ISBN|Name|Author|Publisher|Price|Year|Pages|ImportDate|Status
            CBook book(
                arrFields[0],                    // ISBN
                arrFields[1],                    // Name
                arrFields[2],                    // Author
                arrFields[3],                    // Publisher
                atoi(arrFields[4].c_str()),      // Price
                atoi(arrFields[5].c_str()),      // Year
                atoi(arrFields[6].c_str()),      // Pages
                arrFields[7],                    // ImportDate
                atoi(arrFields[8].c_str())       // Status
            );
            list.add(book);
        }
    }
    
    fileInput.close();
    return true;
}

// Save books to file
bool CFileHandler::saveBooks(const string& strPath, CGenericList<CBook>& list) {
    ofstream fileOutput;
    fileOutput.open(strPath.c_str());
    
    if (!fileOutput.is_open()) {
        return false;
    }
    
    Node<CBook>* pCurrent = list.getHead();
    while (pCurrent != NULL) {
        CBook& book = pCurrent->data;
        // Format: ISBN|Name|Author|Publisher|Price|Year|Pages|ImportDate|Status
        fileOutput << book.getISBN() << "|"
                   << book.getName() << "|"
                   << book.getAuthor() << "|"
                   << book.getPublisher() << "|"
                   << book.getPrice() << "|"
                   << book.getYear() << "|"
                   << book.getPages() << "|"
                   << book.getImportDate() << "|"
                   << book.getStatus() << "\n";
        pCurrent = pCurrent->pNext;
    }
    
    fileOutput.close();
    return true;
}

// Load readers from file
bool CFileHandler::loadReaders(const string& strPath, CGenericList<CReader>& list) {
    ifstream fileInput;
    fileInput.open(strPath.c_str());
    
    if (!fileInput.is_open()) {
        return false;
    }
    
    list.clear(); // Clear existing data
    
    string strLine;
    while (getline(fileInput, strLine)) {
        if (strLine.empty()) continue;
        
        string arrFields[3];
        int iCount = 0;
        split(strLine, '|', arrFields, iCount);
        
        if (iCount >= 3) {
            // Format: ID|Name|JoinDate
            CReader reader(
                arrFields[0],  // ID
                arrFields[1],  // Name
                arrFields[2]   // JoinDate
            );
            list.add(reader);
        }
    }
    
    fileInput.close();
    return true;
}

// Save readers to file
bool CFileHandler::saveReaders(const string& strPath, CGenericList<CReader>& list) {
    ofstream fileOutput;
    fileOutput.open(strPath.c_str());
    
    if (!fileOutput.is_open()) {
        return false;
    }
    
    Node<CReader>* pCurrent = list.getHead();
    while (pCurrent != NULL) {
        CReader& reader = pCurrent->data;
        // Format: ID|Name|JoinDate
        fileOutput << reader.getID() << "|"
                   << reader.getName() << "|"
                   << reader.getJoinDate() << "\n";
        pCurrent = pCurrent->pNext;
    }
    
    fileOutput.close();
    return true;
}

// Load loan tickets from file
bool CFileHandler::loadTickets(const string& strPath, CGenericList<CLoanTicket>& list) {
    ifstream fileInput;
    fileInput.open(strPath.c_str());
    
    if (!fileInput.is_open()) {
        return false;
    }
    
    list.clear(); // Clear existing data
    
    string strLine;
    while (getline(fileInput, strLine)) {
        if (strLine.empty()) continue;
        
        string arrFields[6];
        int iCount = 0;
        split(strLine, '|', arrFields, iCount);
        
        if (iCount >= 6) {
            // Format: TicketID|ReaderID|BookID|BorrowDate|ReturnDate|Status
            CLoanTicket ticket(
                atoi(arrFields[0].c_str()),  // TicketID (int)
                arrFields[1],                // ReaderID
                arrFields[2],                // BookID
                arrFields[3],                // BorrowDate
                arrFields[4],                // ReturnDate
                atoi(arrFields[5].c_str())   // Status
            );
            list.add(ticket);
        }
    }
    
    fileInput.close();
    return true;
}

// Save loan tickets to file
bool CFileHandler::saveTickets(const string& strPath, CGenericList<CLoanTicket>& list) {
    ofstream fileOutput;
    fileOutput.open(strPath.c_str());
    
    if (!fileOutput.is_open()) {
        return false;
    }
    
    Node<CLoanTicket>* pCurrent = list.getHead();
    while (pCurrent != NULL) {
        CLoanTicket& ticket = pCurrent->data;
        // Format: TicketID|ReaderID|BookID|BorrowDate|ReturnDate|Status
        fileOutput << ticket.getTicketID() << "|"
                   << ticket.getReaderID() << "|"
                   << ticket.getBookID() << "|"
                   << ticket.getBorrowDate() << "|"
                   << ticket.getReturnDate() << "|"
                   << ticket.getStatus() << "\n";
        pCurrent = pCurrent->pNext;
    }
    
    fileOutput.close();
    return true;
}

// Check admin login credentials
bool CFileHandler::checkLogin(const string& strPath, const string& strUsername, const string& strPassword) {
    ifstream fileInput;
    fileInput.open(strPath.c_str());
    
    if (!fileInput.is_open()) {
        return false;
    }
    
    string strLine;
    while (getline(fileInput, strLine)) {
        if (strLine.empty()) continue;
        
        string arrFields[2];
        int iCount = 0;
        split(strLine, '|', arrFields, iCount);
        
        if (iCount >= 2) {
            // Format: Username|Password
            if (arrFields[0] == strUsername && arrFields[1] == strPassword) {
                fileInput.close();
                return true;
            }
        }
    }
    
    fileInput.close();
    return false;
}
