#ifndef CREADER_H
#define CREADER_H

#include <string>
using namespace std;

class CReader {
private:
    string m_strReaderID;    // Mã bạn đọc (duy nhất)
    string m_strName;        // Tên bạn đọc
    string m_strRegistrationDate;  // Ngày đăng ký tham gia

public:
    // Constructor
    CReader();
    CReader(string readerID, string name, string registrationDate);
    
    // Destructor
    ~CReader();
    
    // Getters
    string getReaderID() const;
    string getName() const;
    string getRegistrationDate() const;
    
    // Setters
    void setReaderID(string readerID);
    void setName(string name);
    void setRegistrationDate(string registrationDate);
    
    // Methods
    void displayInfo() const;
};

#endif