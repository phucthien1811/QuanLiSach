#include "../Include/CBook.h"

// Default constructor
CBook::CBook() : m_strISBN(""), m_strName(""), m_strAuthor(""),
                 m_strPublisher(""), m_iPrice(0), m_iYear(0), m_iPages(0),
                 m_strImportDate(""), m_iStatus(0) {
}

// Parameterized constructor
CBook::CBook(const string& strISBN, const string& strName, const string& strAuthor,
             const string& strPublisher, int iPrice, int iYear, int iPages,
             const string& strImportDate, int iStatus)
    : m_strISBN(strISBN), m_strName(strName), m_strAuthor(strAuthor),
      m_strPublisher(strPublisher), m_iPrice(iPrice), m_iYear(iYear),
      m_iPages(iPages), m_strImportDate(strImportDate), m_iStatus(iStatus) {
}

// Getters
string CBook::getISBN() const {
    return m_strISBN;
}

string CBook::getName() const {
    return m_strName;
}

string CBook::getAuthor() const {
    return m_strAuthor;
}

string CBook::getPublisher() const {
    return m_strPublisher;
}

int CBook::getPrice() const {
    return m_iPrice;
}

int CBook::getYear() const {
    return m_iYear;
}

int CBook::getPages() const {
    return m_iPages;
}

string CBook::getImportDate() const {
    return m_strImportDate;
}

int CBook::getStatus() const {
    return m_iStatus;
}

// Setters
void CBook::setISBN(const string& strISBN) {
    m_strISBN = strISBN;
}

void CBook::setName(const string& strName) {
    m_strName = strName;
}

void CBook::setAuthor(const string& strAuthor) {
    m_strAuthor = strAuthor;
}

void CBook::setPublisher(const string& strPublisher) {
    m_strPublisher = strPublisher;
}

void CBook::setPrice(int iPrice) {
    m_iPrice = iPrice;
}

void CBook::setYear(int iYear) {
    m_iYear = iYear;
}

void CBook::setPages(int iPages) {
    m_iPages = iPages;
}

void CBook::setImportDate(const string& strImportDate) {
    m_strImportDate = strImportDate;
}

void CBook::setStatus(int iStatus) {
    m_iStatus = iStatus;
}

// Operator overload for comparison by ISBN
bool CBook::operator==(const CBook& other) const {
    return m_strISBN == other.m_strISBN;
}
