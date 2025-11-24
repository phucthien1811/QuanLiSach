#include "../Include/CLoanTicket.h"

// Default constructor
CLoanTicket::CLoanTicket() 
    : m_iTicketID(0), m_strReaderID(""), m_strBookID(""),
      m_strBorrowDate(""), m_strReturnDate(""), m_iStatus(1) {
}

// Parameterized constructor
CLoanTicket::CLoanTicket(int iTicketID, const string& strReaderID,
                         const string& strBookID, const string& strBorrowDate,
                         const string& strReturnDate, int iStatus)
    : m_iTicketID(iTicketID), m_strReaderID(strReaderID), m_strBookID(strBookID),
      m_strBorrowDate(strBorrowDate), m_strReturnDate(strReturnDate), m_iStatus(iStatus) {
}

// Getters
int CLoanTicket::getTicketID() const {
    return m_iTicketID;
}

string CLoanTicket::getReaderID() const {
    return m_strReaderID;
}

string CLoanTicket::getBookID() const {
    return m_strBookID;
}

string CLoanTicket::getBorrowDate() const {
    return m_strBorrowDate;
}

string CLoanTicket::getReturnDate() const {
    return m_strReturnDate;
}

int CLoanTicket::getStatus() const {
    return m_iStatus;
}

// Setters
void CLoanTicket::setTicketID(int iTicketID) {
    m_iTicketID = iTicketID;
}

void CLoanTicket::setReaderID(const string& strReaderID) {
    m_strReaderID = strReaderID;
}

void CLoanTicket::setBookID(const string& strBookID) {
    m_strBookID = strBookID;
}

void CLoanTicket::setBorrowDate(const string& strBorrowDate) {
    m_strBorrowDate = strBorrowDate;
}

void CLoanTicket::setReturnDate(const string& strReturnDate) {
    m_strReturnDate = strReturnDate;
}

void CLoanTicket::setStatus(int iStatus) {
    m_iStatus = iStatus;
}

// Operator overload for comparison by TicketID
bool CLoanTicket::operator==(const CLoanTicket& other) const {
    return m_iTicketID == other.m_iTicketID;
}
