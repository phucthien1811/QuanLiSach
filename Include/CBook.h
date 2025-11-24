#ifndef CBOOK_H
#define CBOOK_H

#include <string>
using namespace std;

class CBook {
private:
    // Member variables with Hungarian notation and m_ prefix
    string m_strISBN;         // Book ISBN (Unique ID)
    string m_strName;         // Book name
    string m_strAuthor;       // Author name
    string m_strPublisher;    // Publisher name
    int m_iPrice;             // Price
    int m_iYear;              // Publication year
    int m_iPages;             // Number of pages
    string m_strImportDate;   // Import date
    int m_iStatus;            // 0: Available, >0: LoanTicketID (borrowed)

public:
    // Constructor
    CBook();
    CBook(const string& strISBN, const string& strName, const string& strAuthor,
          const string& strPublisher, int iPrice, int iYear, int iPages,
          const string& strImportDate, int iStatus = 0);

    // Getters
    string getISBN() const;
    string getName() const;
    string getAuthor() const;
    string getPublisher() const;
    int getPrice() const;
    int getYear() const;
    int getPages() const;
    string getImportDate() const;
    int getStatus() const;

    // Setters
    void setISBN(const string& strISBN);
    void setName(const string& strName);
    void setAuthor(const string& strAuthor);
    void setPublisher(const string& strPublisher);
    void setPrice(int iPrice);
    void setYear(int iYear);
    void setPages(int iPages);
    void setImportDate(const string& strImportDate);
    void setStatus(int iStatus);

    // Operator overload for comparison by ISBN (required for CGenericList)
    bool operator==(const CBook& other) const;
};

#endif // CBOOK_H