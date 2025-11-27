#ifndef CAPPSYSTEM_H
#define CAPPSYSTEM_H

#include "CBookManager.h"
#include "CLoanManager.h"
#include "CUIManager.h"
#include "CFileHandler.h"

// Login constants
const int MAX_LOGIN_ATTEMPTS = 3;
const string ADMIN_FILE_PATH = "Data/Admin.txt";

class CAppSystem {
private:
    CBookManager m_bookManager;
    CLoanManager m_loanManager;
    bool m_bIsRunning;
    
    // Login functionality
    bool performLogin();
    
    // Main menu handlers
    void handleBookMenu();
    void handleReaderMenu();
    void handleLoanMenu();
    void handleReports();
    
    // Book operations
    void addNewBook();
    void deleteExistingBook();
    void displayAllBooks();
    void searchBook();
    
    // Reader operations
    void addNewReader();
    void deleteExistingReader();
    void displayAllReaders();
    void searchReader();
    
    // Loan operations
    void borrowBook();
    void returnBook();
    void displayAllTickets();
    void searchTicket();

public:
    // Constructor
    CAppSystem();
    
    // Main application loop
    void run();
};

#endif // CAPPSYSTEM_H
