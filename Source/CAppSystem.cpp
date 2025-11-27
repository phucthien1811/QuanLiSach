#include "../Include/CAppSystem.h"
#include <iostream>

using namespace std;

// Constructor
CAppSystem::CAppSystem() : m_loanManager(&m_bookManager), m_bIsRunning(false) {
}

// Perform login with 3 attempts
bool CAppSystem::performLogin() {
    int iAttempts = 0;
    string strUsername, strPassword;
    
    while (iAttempts < MAX_LOGIN_ATTEMPTS) {
        CUIManager::showLoginScreen();
        
        cout << "Username: ";
        cin >> strUsername;
        
        cout << "Password: ";
        strPassword = CUIManager::getPassword();
        
        // Check credentials using CFileHandler
        if (CFileHandler::checkLogin(ADMIN_FILE_PATH, strUsername, strPassword)) {
            cout << "\nDang nhap thanh cong!" << endl;
            CUIManager::pauseScreen();
            return true;
        }
        else {
            iAttempts++;
            cout << "\nSai ten dang nhap hoac mat khau!" << endl;
            cout << "Con lai " << (MAX_LOGIN_ATTEMPTS - iAttempts) << " lan thu." << endl;
            
            if (iAttempts < MAX_LOGIN_ATTEMPTS) {
                CUIManager::pauseScreen();
            }
        }
    }
    
    cout << "\nDa het so lan dang nhap. Thoat chuong trinh..." << endl;
    CUIManager::pauseScreen();
    return false;
}

// Main application loop
void CAppSystem::run() {
    // Step 1: Login
    if (!performLogin()) {
        return;  // Exit if login fails
    }
    
    // Step 2: Main menu loop
    m_bIsRunning = true;
    int iChoice = 0;
    
    while (m_bIsRunning) {
        CUIManager::showMainMenu();
        cin >> iChoice;
        
        // Step 3: Handle user choice
        switch (iChoice) {
            case 1:
                handleBookMenu();
                break;
            case 2:
                handleReaderMenu();
                break;
            case 3:
                handleLoanMenu();
                break;
            case 4:
                handleReports();
                break;
            case 0:
                cout << "\nCam on ban da su dung he thong!" << endl;
                m_bIsRunning = false;
                break;
            default:
                cout << "\nLua chon khong hop le!" << endl;
                CUIManager::pauseScreen();
                break;
        }
    }
}

// Handle book management menu
void CAppSystem::handleBookMenu() {
    int iChoice = 0;
    
    do {
        CUIManager::showBookMenu();
        cin >> iChoice;
        
        switch (iChoice) {
            case 1:
                addNewBook();
                break;
            case 2:
                deleteExistingBook();
                break;
            case 3:
                displayAllBooks();
                break;
            case 4:
                searchBook();
                break;
            case 0:
                break;
            default:
                cout << "\nLua chon khong hop le!" << endl;
                CUIManager::pauseScreen();
                break;
        }
    } while (iChoice != 0);
}

// Handle reader management menu
void CAppSystem::handleReaderMenu() {
    int iChoice = 0;
    
    do {
        CUIManager::showReaderMenu();
        cin >> iChoice;
        
        switch (iChoice) {
            case 1:
                addNewReader();
                break;
            case 2:
                deleteExistingReader();
                break;
            case 3:
                displayAllReaders();
                break;
            case 4:
                searchReader();
                break;
            case 0:
                break;
            default:
                cout << "\nLua chon khong hop le!" << endl;
                CUIManager::pauseScreen();
                break;
        }
    } while (iChoice != 0);
}

// Handle loan management menu
void CAppSystem::handleLoanMenu() {
    int iChoice = 0;
    
    do {
        CUIManager::showLoanMenu();
        cin >> iChoice;
        
        switch (iChoice) {
            case 1:
                borrowBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                displayAllTickets();
                break;
            case 4:
                searchTicket();
                break;
            case 0:
                break;
            default:
                cout << "\nLua chon khong hop le!" << endl;
                CUIManager::pauseScreen();
                break;
        }
    } while (iChoice != 0);
}

// Handle reports menu
void CAppSystem::handleReports() {
    CUIManager::clearScreen();
    CUIManager::showHeader("THONG KE & BAO CAO");
    
    cout << "\nTong so sach: " << m_bookManager.getBookCount() << endl;
    cout << "Tong so ban doc: " << m_loanManager.getReaderCount() << endl;
    cout << "Tong so phieu muon: " << m_loanManager.getTicketCount() << endl;
    
    // Count available books
    int iAvailableBooks = 0;
    Node<CBook>* pCurrent = m_bookManager.getBookList().getHead();
    while (pCurrent != NULL) {
        if (pCurrent->data.getStatus() == BOOK_AVAILABLE) {
            iAvailableBooks++;
        }
        pCurrent = pCurrent->pNext;
    }
    
    cout << "So sach co san: " << iAvailableBooks << endl;
    cout << "So sach dang muon: " << (m_bookManager.getBookCount() - iAvailableBooks) << endl;
    
    CUIManager::pauseScreen();
}

// Add new book
void CAppSystem::addNewBook() {
    CUIManager::clearScreen();
    CUIManager::showHeader("THEM SACH MOI");
    
    string strISBN, strName, strAuthor, strPublisher, strImportDate;
    int iPrice, iYear, iPages;
    
    cin.ignore();  // Clear input buffer
    cout << "\nNhap ISBN: ";
    getline(cin, strISBN);
    cout << "Nhap ten sach: ";
    getline(cin, strName);
    cout << "Nhap tac gia: ";
    getline(cin, strAuthor);
    cout << "Nhap nha xuat ban: ";
    getline(cin, strPublisher);
    cout << "Nhap gia: ";
    cin >> iPrice;
    cout << "Nhap nam xuat ban: ";
    cin >> iYear;
    cout << "Nhap so trang: ";
    cin >> iPages;
    cin.ignore();
    cout << "Nhap ngay nhap (dd/mm/yyyy): ";
    getline(cin, strImportDate);
    
    CBook newBook(strISBN, strName, strAuthor, strPublisher, iPrice, iYear, iPages, strImportDate, BOOK_AVAILABLE);
    
    if (m_bookManager.addBook(newBook)) {
        cout << "\nThem sach thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Ma ISBN da ton tai!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Delete existing book
void CAppSystem::deleteExistingBook() {
    CUIManager::clearScreen();
    CUIManager::showHeader("XOA SACH");
    
    string strISBN;
    cin.ignore();
    cout << "\nNhap ISBN can xoa: ";
    getline(cin, strISBN);
    
    if (m_bookManager.deleteBook(strISBN)) {
        cout << "\nXoa sach thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Khong the xoa sach (khong ton tai hoac dang duoc muon)!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Display all books
void CAppSystem::displayAllBooks() {
    CUIManager::clearScreen();
    CUIManager::showHeader("DANH SACH SACH");
    
    Node<CBook>* pCurrent = m_bookManager.getBookList().getHead();
    int iCount = 1;
    
    if (pCurrent == NULL) {
        cout << "\nKhong co sach nao trong he thong!" << endl;
    }
    else {
        cout << "\n";
        while (pCurrent != NULL) {
            CBook& book = pCurrent->data;
            cout << iCount++ << ". " << book.getISBN() << " - " << book.getName() << endl;
            cout << "   Tac gia: " << book.getAuthor() << " | NXB: " << book.getPublisher() << endl;
            cout << "   Gia: " << book.getPrice() << " | Nam: " << book.getYear() << " | Trang: " << book.getPages() << endl;
            cout << "   Ngay nhap: " << book.getImportDate() << endl;
            cout << "   Trang thai: " << (book.getStatus() == BOOK_AVAILABLE ? "Co san" : "Dang muon") << endl;
            cout << endl;
            pCurrent = pCurrent->pNext;
        }
    }
    
    CUIManager::pauseScreen();
}

// Search book
void CAppSystem::searchBook() {
    CUIManager::clearScreen();
    CUIManager::showHeader("TIM KIEM SACH");
    
    string strISBN;
    cin.ignore();
    cout << "\nNhap ISBN can tim: ";
    getline(cin, strISBN);
    
    CBook* pBook = m_bookManager.findBook(strISBN);
    
    if (pBook != NULL) {
        cout << "\nThong tin sach:" << endl;
        cout << "ISBN: " << pBook->getISBN() << endl;
        cout << "Ten sach: " << pBook->getName() << endl;
        cout << "Tac gia: " << pBook->getAuthor() << endl;
        cout << "NXB: " << pBook->getPublisher() << endl;
        cout << "Gia: " << pBook->getPrice() << endl;
        cout << "Nam: " << pBook->getYear() << endl;
        cout << "So trang: " << pBook->getPages() << endl;
        cout << "Ngay nhap: " << pBook->getImportDate() << endl;
        cout << "Trang thai: " << (pBook->getStatus() == BOOK_AVAILABLE ? "Co san" : "Dang muon") << endl;
    }
    else {
        cout << "\nKhong tim thay sach!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Add new reader
void CAppSystem::addNewReader() {
    CUIManager::clearScreen();
    CUIManager::showHeader("THEM BAN DOC MOI");
    
    string strID, strName, strJoinDate;
    
    cin.ignore();
    cout << "\nNhap ma ban doc: ";
    getline(cin, strID);
    cout << "Nhap ten ban doc: ";
    getline(cin, strName);
    cout << "Nhap ngay dang ky (dd/mm/yyyy): ";
    getline(cin, strJoinDate);
    
    CReader newReader(strID, strName, strJoinDate);
    
    if (m_loanManager.addReader(newReader)) {
        cout << "\nThem ban doc thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Ma ban doc da ton tai!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Delete existing reader
void CAppSystem::deleteExistingReader() {
    CUIManager::clearScreen();
    CUIManager::showHeader("XOA BAN DOC");
    
    string strID;
    cin.ignore();
    cout << "\nNhap ma ban doc can xoa: ";
    getline(cin, strID);
    
    if (m_loanManager.deleteReader(strID)) {
        cout << "\nXoa ban doc thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Khong the xoa ban doc (khong ton tai hoac dang co sach muon)!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Display all readers
void CAppSystem::displayAllReaders() {
    CUIManager::clearScreen();
    CUIManager::showHeader("DANH SACH BAN DOC");
    
    Node<CReader>* pCurrent = m_loanManager.getReaderList().getHead();
    int iCount = 1;
    
    if (pCurrent == NULL) {
        cout << "\nKhong co ban doc nao trong he thong!" << endl;
    }
    else {
        cout << "\n";
        while (pCurrent != NULL) {
            CReader& reader = pCurrent->data;
            cout << iCount++ << ". " << reader.getID() << " - " << reader.getName() << endl;
            cout << "   Ngay dang ky: " << reader.getJoinDate() << endl;
            cout << endl;
            pCurrent = pCurrent->pNext;
        }
    }
    
    CUIManager::pauseScreen();
}

// Search reader
void CAppSystem::searchReader() {
    CUIManager::clearScreen();
    CUIManager::showHeader("TIM KIEM BAN DOC");
    
    string strID;
    cin.ignore();
    cout << "\nNhap ma ban doc can tim: ";
    getline(cin, strID);
    
    CReader* pReader = m_loanManager.findReader(strID);
    
    if (pReader != NULL) {
        cout << "\nThong tin ban doc:" << endl;
        cout << "Ma ban doc: " << pReader->getID() << endl;
        cout << "Ten ban doc: " << pReader->getName() << endl;
        cout << "Ngay dang ky: " << pReader->getJoinDate() << endl;
    }
    else {
        cout << "\nKhong tim thay ban doc!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Borrow book
void CAppSystem::borrowBook() {
    CUIManager::clearScreen();
    CUIManager::showHeader("MUON SACH");
    
    string strReaderID, strBookID, strBorrowDate, strReturnDate;
    
    cin.ignore();
    cout << "\nNhap ma ban doc: ";
    getline(cin, strReaderID);
    cout << "Nhap ISBN sach: ";
    getline(cin, strBookID);
    cout << "Nhap ngay muon (dd/mm/yyyy): ";
    getline(cin, strBorrowDate);
    cout << "Nhap ngay tra du kien (dd/mm/yyyy): ";
    getline(cin, strReturnDate);
    
    if (m_loanManager.borrowBook(strReaderID, strBookID, strBorrowDate, strReturnDate)) {
        cout << "\nMuon sach thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Khong the muon sach (ban doc/sach khong ton tai hoac sach da duoc muon)!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Return book
void CAppSystem::returnBook() {
    CUIManager::clearScreen();
    CUIManager::showHeader("TRA SACH");
    
    int iTicketID;
    
    cout << "\nNhap ma phieu muon: ";
    cin >> iTicketID;
    
    if (m_loanManager.returnBook(iTicketID)) {
        cout << "\nTra sach thanh cong!" << endl;
    }
    else {
        cout << "\nLoi: Khong the tra sach (phieu muon khong ton tai hoac da tra)!" << endl;
    }
    
    CUIManager::pauseScreen();
}

// Display all loan tickets
void CAppSystem::displayAllTickets() {
    CUIManager::clearScreen();
    CUIManager::showHeader("DANH SACH PHIEU MUON");
    
    Node<CLoanTicket>* pCurrent = m_loanManager.getTicketList().getHead();
    int iCount = 1;
    
    if (pCurrent == NULL) {
        cout << "\nKhong co phieu muon nao trong he thong!" << endl;
    }
    else {
        cout << "\n";
        while (pCurrent != NULL) {
            CLoanTicket& ticket = pCurrent->data;
            cout << iCount++ << ". Ma phieu: " << ticket.getTicketID() << endl;
            cout << "   Ban doc: " << ticket.getReaderID() << " | Sach: " << ticket.getBookID() << endl;
            cout << "   Ngay muon: " << ticket.getBorrowDate() << " | Ngay tra: " << ticket.getReturnDate() << endl;
            cout << "   Trang thai: " << (ticket.getStatus() == TICKET_BORROWING ? "Dang muon" : "Da tra") << endl;
            cout << endl;
            pCurrent = pCurrent->pNext;
        }
    }
    
    CUIManager::pauseScreen();
}

// Search ticket
void CAppSystem::searchTicket() {
    CUIManager::clearScreen();
    CUIManager::showHeader("TIM KIEM PHIEU MUON");
    
    int iTicketID;
    cout << "\nNhap ma phieu muon: ";
    cin >> iTicketID;
    
    CLoanTicket* pTicket = m_loanManager.findTicket(iTicketID);
    
    if (pTicket != NULL) {
        cout << "\nThong tin phieu muon:" << endl;
        cout << "Ma phieu: " << pTicket->getTicketID() << endl;
        cout << "Ma ban doc: " << pTicket->getReaderID() << endl;
        cout << "Ma sach: " << pTicket->getBookID() << endl;
        cout << "Ngay muon: " << pTicket->getBorrowDate() << endl;
        cout << "Ngay tra: " << pTicket->getReturnDate() << endl;
        cout << "Trang thai: " << (pTicket->getStatus() == TICKET_BORROWING ? "Dang muon" : "Da tra") << endl;
    }
    else {
        cout << "\nKhong tim thay phieu muon!" << endl;
    }
    
    CUIManager::pauseScreen();
}