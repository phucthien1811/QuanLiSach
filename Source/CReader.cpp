#include "../Include/CReader.h"

// Default constructor
CReader::CReader() : m_strID(""), m_strName(""), m_strJoinDate("") {
}

// Parameterized constructor
CReader::CReader(const string& strID, const string& strName, const string& strJoinDate)
    : m_strID(strID), m_strName(strName), m_strJoinDate(strJoinDate) {
}

// Getters
string CReader::getID() const {
    return m_strID;
}

string CReader::getName() const {
    return m_strName;
}

string CReader::getJoinDate() const {
    return m_strJoinDate;
}

// Setters
void CReader::setID(const string& strID) {
    m_strID = strID;
}

void CReader::setName(const string& strName) {
    m_strName = strName;
}

void CReader::setJoinDate(const string& strJoinDate) {
    m_strJoinDate = strJoinDate;
}

// Operator overload for comparison by ID
bool CReader::operator==(const CReader& other) const {
    return m_strID == other.m_strID;
}
