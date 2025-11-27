#ifndef CFILEHANDLER_H
#define CFILEHANDLER_H

#include <string>
#include "CGenericList.h"
#include "CBook.h"
#include "CReader.h"
#include "CLoanTicket.h"

using namespace std;

class CFileHandler {
public:
    // Book operations
    static bool loadBooks(const string& strPath, CGenericList<CBook>& list);
    static bool saveBooks(const string& strPath, CGenericList<CBook>& list);

    // Reader operations
    static bool loadReaders(const string& strPath, CGenericList<CReader>& list);
    static bool saveReaders(const string& strPath, CGenericList<CReader>& list);

    // Loan Ticket operations
    static bool loadTickets(const string& strPath, CGenericList<CLoanTicket>& list);
    static bool saveTickets(const string& strPath, CGenericList<CLoanTicket>& list);

    // Admin login check
    static bool checkLogin(const string& strPath, const string& strUsername, const string& strPassword);

private:
    // Helper method to split string by delimiter
    static void split(const string& strLine, char cDelimiter, string arrResult[], int& iCount);
};

#endif // CFILEHANDLER_H