// File: Include/AppCommon.h (Dung chung)
const int BOOK_AVAILABLE = 0; // STANDARD II.19: Tranh Magic Number
const int BOOK_BORROWED = 1;

// File: Source/CBookManager.cpp
bool CBookManager::deleteBook(const string& strID) {
    // 1. Tim sach trong list
    CBook* pBook = m_listBooks.find(strID);

    // STANDARD III.1: Check pointer null
    if (pBook == NULL) {
        return false; // Khong tim thay
    }

    // 2. Check rang buoc du lieu
    if (pBook->getStatus() != BOOK_AVAILABLE) {
        return false; // Sach dang ban, khong xoa duoc
    }

    // 3. Thuc hien xoa va luu file
    m_listBooks.remove(strID);
    CFileHandler::saveBooks("Data/Sach.txt", m_listBooks);
    
    return true;
}