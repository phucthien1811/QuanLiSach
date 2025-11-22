// File: Source/CLoanManager.cpp

/**
 * @Description: Xu ly muon sach cho ban doc
 * @return: true neu muon thanh cong
 * @attention: Can check sach co ton tai va trang thai co san sang khong
 */
bool CLoanManager::borrowBook(string strReaderID, string strBookID) {
    // 1. Goi T4 de lay sach
    CBook* pBook = m_bookManager->findBook(strBookID);

    // STANDARD III.1: Check NULL pointer ngay lap tuc
    if (pBook == NULL) {
        cout << "Loi: Khong tim thay ma sach!";
        return false;
    }

    // 2. Check trang thai
    if (pBook->getStatus() == BOOK_BORROWED) {
        cout << "Loi: Sach da co nguoi muon!";
        return false;
    }

    // 3. Tao phieu muon moi
    CLoanTicket ticket(strReaderID, strBookID);
    m_listTickets.add(ticket);

    // 4. Cap nhat trang thai sach thanh BAN (1)
    pBook->setStatus(BOOK_BORROWED); 
    
    return true;
}