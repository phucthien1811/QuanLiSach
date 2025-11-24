#include "../Include/CLoanTicket.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor mặc định
CLoanTicket::CLoanTicket() {
    m_iLoanNumber = 0;
    m_strReaderID = "";
    m_strBookID = "";
    m_strBorrowDate = "";
    m_strDueDate = "";
    m_iLateStatus = 1;
}

// Constructor có tham số
CLoanTicket::CLoanTicket(int loanNumber, string readerID, string bookID, 
                         string borrowDate, string dueDate, int lateStatus) {
    m_iLoanNumber = loanNumber;
    m_strReaderID = readerID;
    m_strBookID = bookID;
    m_strBorrowDate = borrowDate;
    m_strDueDate = dueDate;
    m_iLateStatus = lateStatus;
}

// Destructor
CLoanTicket::~CLoanTicket() {
    // Không có con trỏ nên không cần delete
}

// Getters
int CLoanTicket::getLoanNumber() const { return m_iLoanNumber; }
string CLoanTicket::getReaderID() const { return m_strReaderID; }
string CLoanTicket::getBookID() const { return m_strBookID; }
string CLoanTicket::getBorrowDate() const { return m_strBorrowDate; }
string CLoanTicket::getDueDate() const { return m_strDueDate; }
int CLoanTicket::getLateStatus() const { return m_iLateStatus; }

// Setters
void CLoanTicket::setLoanNumber(int loanNumber) { m_iLoanNumber = loanNumber; }
void CLoanTicket::setReaderID(string readerID) { m_strReaderID = readerID; }
void CLoanTicket::setBookID(string bookID) { m_strBookID = bookID; }
void CLoanTicket::setBorrowDate(string borrowDate) { m_strBorrowDate = borrowDate; }
void CLoanTicket::setDueDate(string dueDate) { m_strDueDate = dueDate; }
void CLoanTicket::setLateStatus(int lateStatus) { m_iLateStatus = lateStatus; }

// Hiển thị thông tin phiếu mượn
void CLoanTicket::displayInfo() const {
    cout << left;
    cout << setw(15) << m_iLoanNumber 
         << setw(15) << m_strReaderID 
         << setw(15) << m_strBookID 
         << setw(15) << m_strBorrowDate 
         << setw(15) << m_strDueDate 
         << setw(10) << (m_iLateStatus == 1 ? "Dang muon" : "Da tra") << endl;
}

// Kiểm tra đã trả sách chưa
bool CLoanTicket::isReturned() const {
    return m_iLateStatus == 0;
}