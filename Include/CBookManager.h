// File: Include/CBookManager.h
#ifndef C_BOOK_MANAGER_H  // Include Guard chuẩn
#define C_BOOK_MANAGER_H

#include "CBook.h"
#include "CGenericList.h"

// Class quản lý các nghiệp vụ liên quan đến sách
class CBookManager {
private:
    CGenericList<CBook> m_listBooks; // Biến private có tiền tố m_

public:
    CBookManager();
    ~CBookManager();

    /**
     * @Description: Thêm sách mới vào hệ thống và lưu file
     * @return: true nếu thêm thành công, false nếu mã sách trùng
     * @attention: Cần check trùng ID trước khi thêm
     */
    bool addBook(const CBook& book); 
};

#endif // C_BOOK_MANAGER_H