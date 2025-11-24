#ifndef CGENERICLIST_H
#define CGENERICLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class CGenericList {
private:
    T* m_pData;           // Con trỏ mảng động chứa dữ liệu
    int m_iCount;         // Số phần tử hiện tại
    int m_iCapacity;      // Dung lượng của mảng

    // Tăng kích thước mảng khi cần
    void resize() {
        m_iCapacity *= 2;
        T* newData = new T[m_iCapacity];
        for (int i = 0; i < m_iCount; i++) {
            newData[i] = m_pData[i];
        }
        delete[] m_pData;
        m_pData = newData;
    }

public:
    // Constructor
    CGenericList() {
        m_iCapacity = 10;
        m_iCount = 0;
        m_pData = new T[m_iCapacity];
    }

    // Destructor
    ~CGenericList() {
        delete[] m_pData;
    }

    // Thêm phần tử vào cuối danh sách
    void add(const T& item) {
        if (m_iCount >= m_iCapacity) {
            resize();
        }
        m_pData[m_iCount] = item;
        m_iCount++;
    }

    // Xóa phần tử tại vị trí index
    bool removeAt(int index) {
        if (index < 0 || index >= m_iCount) {
            return false;
        }
        for (int i = index; i < m_iCount - 1; i++) {
            m_pData[i] = m_pData[i + 1];
        }
        m_iCount--;
        return true;
    }

    // Lấy phần tử tại vị trí index
    T& getAt(int index) {
        return m_pData[index];
    }

    // Lấy phần tử tại vị trí index (const)
    const T& getAt(int index) const {
        return m_pData[index];
    }

    // Lấy số lượng phần tử
    int getCount() const {
        return m_iCount;
    }

    // Kiểm tra danh sách rỗng
    bool isEmpty() const {
        return m_iCount == 0;
    }

    // Xóa tất cả phần tử
    void clear() {
        m_iCount = 0;
    }

    // Tìm kiếm phần tử theo ID (cho CBook)
    int findBookByID(const string& bookID) const {
        for (int i = 0; i < m_iCount; i++) {
            if (m_pData[i].getBookID() == bookID) {
                return i;
            }
        }
        return -1;
    }

    // Tìm kiếm phần tử theo ID (cho CReader)
    int findReaderByID(const string& readerID) const {
        for (int i = 0; i < m_iCount; i++) {
            if (m_pData[i].getReaderID() == readerID) {
                return i;
            }
        }
        return -1;
    }

    // Tìm kiếm phiếu mượn theo số phiếu
    int findLoanByNumber(int loanNumber) const {
        for (int i = 0; i < m_iCount; i++) {
            if (m_pData[i].getLoanNumber() == loanNumber) {
                return i;
            }
        }
        return -1;
    }

    // Hiển thị tất cả phần tử
    void displayAll() const {
        for (int i = 0; i < m_iCount; i++) {
            m_pData[i].displayInfo();
        }
    }

    // Toán tử []
    T& operator[](int index) {
        return m_pData[index];
    }

    const T& operator[](int index) const {
        return m_pData[index];
    }
};

#endif