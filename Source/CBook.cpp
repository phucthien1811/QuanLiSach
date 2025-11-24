#include "../Include/CBook.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor mặc định
CBook::CBook() {
    m_strBookID = "";
    m_strTitle = "";
    m_strAuthor = "";
    m_strPublisher = "";
    m_fPrice = 0.0f;
    m_iYearPublished = 0;
    m_iPages = 0;
    m_strDateAdded = "";
    m_iStatus = 1;
}

// Constructor có tham số
CBook::CBook(string bookID, string title, string author, string publisher, 
             float price, int year, int pages, string dateAdded, int status) {
    m_strBookID = bookID;
    m_strTitle = title;
    m_strAuthor = author;
    m_strPublisher = publisher;
    m_fPrice = price;
    m_iYearPublished = year;
    m_iPages = pages;
    m_strDateAdded = dateAdded;
    m_iStatus = status;
}

// Destructor
CBook::~CBook() {
    // Không có con trỏ nên không cần delete
}

// Getters
string CBook::getBookID() const { return m_strBookID; }
string CBook::getTitle() const { return m_strTitle; }
string CBook::getAuthor() const { return m_strAuthor; }
string CBook::getPublisher() const { return m_strPublisher; }
float CBook::getPrice() const { return m_fPrice; }
int CBook::getYearPublished() const { return m_iYearPublished; }
int CBook::getPages() const { return m_iPages; }
string CBook::getDateAdded() const { return m_strDateAdded; }
int CBook::getStatus() const { return m_iStatus; }

// Setters
void CBook::setBookID(string bookID) { m_strBookID = bookID; }
void CBook::setTitle(string title) { m_strTitle = title; }
void CBook::setAuthor(string author) { m_strAuthor = author; }
void CBook::setPublisher(string publisher) { m_strPublisher = publisher; }
void CBook::setPrice(float price) { m_fPrice = price; }
void CBook::setYearPublished(int year) { m_iYearPublished = year; }
void CBook::setPages(int pages) { m_iPages = pages; }
void CBook::setDateAdded(string dateAdded) { m_strDateAdded = dateAdded; }
void CBook::setStatus(int status) { m_iStatus = status; }

// Hiển thị thông tin sách
void CBook::displayInfo() const {
    cout << left;
    cout << setw(15) << m_strBookID 
         << setw(30) << m_strTitle 
         << setw(20) << m_strAuthor 
         << setw(20) << m_strPublisher 
         << setw(10) << m_fPrice 
         << setw(10) << m_iYearPublished 
         << setw(10) << m_iPages 
         << setw(15) << m_strDateAdded 
         << setw(10) << m_iStatus << endl;
}

// Kiểm tra sách còn khả dụng
bool CBook::isAvailable() const {
    return m_iStatus > 0;
}