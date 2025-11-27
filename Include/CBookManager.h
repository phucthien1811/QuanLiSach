#ifndef CBOOKMANAGER_H
#define CBOOKMANAGER_H

#include "CBook.h"
#include "CGenericList.h"
#include "CFileHandler.h"

// Status constants for Book
const int BOOK_AVAILABLE = 0;  // Book is available for borrowing

class CBookManager {
private:
    CGenericList<CBook> m_listBooks;  // List of books
    string m_strFilePath;              // Path to data file

public:
    // Constructor: Load books from file
    CBookManager();
    CBookManager(const string& strFilePath);
    
    // Destructor: Save books to file
    ~CBookManager();

    // Add a new book (checks for duplicate ISBN)
    bool addBook(const CBook& book);
    
    // Delete a book by ISBN (only if Status == 0/Available)
    bool deleteBook(const string& strISBN);
    
    // Update book status (for loan operations)
    bool updateBookStatus(const string& strISBN, int iNewStatus);
    
    // Find a book by ISBN
    CBook* findBook(const string& strISBN);
    
    // Get the book list for display purposes
    CGenericList<CBook>& getBookList();
    
    // Get book count
    int getBookCount() const;
};

#endif // CBOOKMANAGER_H