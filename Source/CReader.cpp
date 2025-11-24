#include "../Include/CReader.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor mặc định
CReader::CReader() {
    m_strReaderID = "";
    m_strName = "";
    m_strRegistrationDate = "";
}

// Constructor có tham số
CReader::CReader(string readerID, string name, string registrationDate) {
    m_strReaderID = readerID;
    m_strName = name;
    m_strRegistrationDate = registrationDate;
}

// Destructor
CReader::~CReader() {
    // Không có con trỏ nên không cần delete
}

// Getters
string CReader::getReaderID() const { return m_strReaderID; }
string CReader::getName() const { return m_strName; }
string CReader::getRegistrationDate() const { return m_strRegistrationDate; }

// Setters
void CReader::setReaderID(string readerID) { m_strReaderID = readerID; }
void CReader::setName(string name) { m_strName = name; }
void CReader::setRegistrationDate(string registrationDate) { m_strRegistrationDate = registrationDate; }

// Hiển thị thông tin bạn đọc
void CReader::displayInfo() const {
    cout << left;
    cout << setw(15) << m_strReaderID 
         << setw(30) << m_strName 
         << setw(15) << m_strRegistrationDate << endl;
}