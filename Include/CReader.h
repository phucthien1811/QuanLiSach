#ifndef CREADER_H
#define CREADER_H

#include <string>
using namespace std;

class CReader {
private:
    // Member variables with Hungarian notation and m_ prefix
    string m_strID;         // Reader ID
    string m_strName;       // Reader name
    string m_strJoinDate;   // Join date

public:
    // Constructor
    CReader();
    CReader(const string& strID, const string& strName, const string& strJoinDate);

    // Getters
    string getID() const;
    string getName() const;
    string getJoinDate() const;

    // Setters
    void setID(const string& strID);
    void setName(const string& strName);
    void setJoinDate(const string& strJoinDate);

    // Operator overload for comparison by ID (required for CGenericList)
    bool operator==(const CReader& other) const;
};

#endif // CREADER_H
