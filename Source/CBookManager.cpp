#include "../Include/CBookManager.h"

// Default constructor: Load books from default file path
CBookManager::CBookManager() : m_strFilePath("Data/Sach.txt") {
    CFileHandler::loadBooks(m_strFilePath, m_listBooks);
}

// Parameterized constructor: Load books from specified file path
CBookManager::CBookManager(const string& strFilePath) : m_strFilePath(strFilePath) {
    CFileHandler::loadBooks(m_strFilePath, m_listBooks);
}

// Destructor: Save books to file
CBookManager::~CBookManager() {
    CFileHandler::saveBooks(m_strFilePath, m_listBooks);
}

// Add a new book (checks for duplicate ISBN)
bool CBookManager::addBook(const CBook& book) {
    // Create a temporary book with the same ISBN to search
    CBook tempBook;
    tempBook.setISBN(book.getISBN());
    
    // Check if book with this ISBN already exists
    CBook* pExistingBook = m_listBooks.find(tempBook);
    if (pExistingBook != NULL) {
        return false; // ISBN already exists
    }
    
    // Add book to list
    m_listBooks.add(book);
    
    // Save to file immediately
    CFileHandler::saveBooks(m_strFilePath, m_listBooks);
    
    return true;
}

// Delete a book by ISBN (only if Status == 0/Available)
bool CBookManager::deleteBook(const string& strISBN) {
    // Create a temporary book to search
    CBook tempBook;
    tempBook.setISBN(strISBN);
    
    // Find the book
    CBook* pBook = m_listBooks.find(tempBook);
    if (pBook == NULL) {
        return false; // Book not found
    }
    
    // CRITICAL CHECK: Only delete if book is available (Status == 0)
    if (pBook->getStatus() != BOOK_AVAILABLE) {
        return false; // Cannot delete borrowed book
    }
    
    // Remove book from list
    bool bResult = m_listBooks.remove(tempBook);
    
    if (bResult) {
        // Save to file immediately
        CFileHandler::saveBooks(m_strFilePath, m_listBooks);
    }
    
    return bResult;
}

// Update book status (for loan operations)
bool CBookManager::updateBookStatus(const string& strISBN, int iNewStatus) {
    // Create a temporary book to search
    CBook tempBook;
    tempBook.setISBN(strISBN);
    
    // Find the book
    CBook* pBook = m_listBooks.find(tempBook);
    if (pBook == NULL) {
        return false; // Book not found
    }
    
    // Update status
    pBook->setStatus(iNewStatus);
    
    // Save to file immediately
    CFileHandler::saveBooks(m_strFilePath, m_listBooks);
    
    return true;
}

// Find a book by ISBN
CBook* CBookManager::findBook(const string& strISBN) {
    // Create a temporary book to search
    CBook tempBook;
    tempBook.setISBN(strISBN);
    
    return m_listBooks.find(tempBook);
}

// Get the book list for display purposes
CGenericList<CBook>& CBookManager::getBookList() {
    return m_listBooks;
}

// Get book count
int CBookManager::getBookCount() const {
    return m_listBooks.getCount();
}
