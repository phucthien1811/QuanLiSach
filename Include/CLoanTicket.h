#ifndef CLOANTICKET_H
#define CLOANTICKET_H

#include <string>
using namespace std;

class CLoanTicket {
private:
    int m_iLoanNumber;         // Số phiếu mượn
    string m_strReaderID;      // Mã bạn đọc
    string m_strBookID;        // Mã sách
    string m_strBorrowDate;    // Ngày mượn (lấy ngày hiện tại của hệ thống)
    string m_strDueDate;       // Ngày phải trả (= ngày mượn + 7)
    int m_iLateStatus;         // Tình trạng phiếu mượn (1: đang mượn, 0: đã trả)

public:
    // Constructor
    CLoanTicket();
    CLoanTicket(int loanNumber, string readerID, string bookID, 
                string borrowDate, string dueDate, int lateStatus);
    
    // Destructor
    ~CLoanTicket();
    
    // Getters
    int getLoanNumber() const;
    string getReaderID() const;
    string getBookID() const;
    string getBorrowDate() const;
    string getDueDate() const;
    int getLateStatus() const;
    
    // Setters
    void setLoanNumber(int loanNumber);
    void setReaderID(string readerID);
    void setBookID(string bookID);
    void setBorrowDate(string borrowDate);
    void setDueDate(string dueDate);
    void setLateStatus(int lateStatus);
    
    // Methods
    void displayInfo() const;
    bool isReturned() const;
};

#endif