#ifndef CLOANTICKET_H
#define CLOANTICKET_H

#include <string>
using namespace std;

class CLoanTicket {
private:
    // Member variables with Hungarian notation and m_ prefix
    int m_iTicketID;           // Ticket ID (auto-increment, starts from 1)
    string m_strReaderID;      // Reader ID
    string m_strBookID;        // Book ID (ISBN)
    string m_strBorrowDate;    // Borrow date
    string m_strReturnDate;    // Return date
    int m_iStatus;             // 1: Borrowing, 0: Returned

public:
    // Constructor
    CLoanTicket();
    CLoanTicket(int iTicketID, const string& strReaderID, const string& strBookID,
                const string& strBorrowDate, const string& strReturnDate, int iStatus = 1);

    // Getters
    int getTicketID() const;
    string getReaderID() const;
    string getBookID() const;
    string getBorrowDate() const;
    string getReturnDate() const;
    int getStatus() const;

    // Setters
    void setTicketID(int iTicketID);
    void setReaderID(const string& strReaderID);
    void setBookID(const string& strBookID);
    void setBorrowDate(const string& strBorrowDate);
    void setReturnDate(const string& strReturnDate);
    void setStatus(int iStatus);

    // Operator overload for comparison by TicketID (required for CGenericList)
    bool operator==(const CLoanTicket& other) const;
};

#endif // CLOANTICKET_H
