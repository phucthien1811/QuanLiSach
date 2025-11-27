#ifndef CUIMANAGER_H
#define CUIMANAGER_H

#include <string>
using namespace std;

class CUIManager {
public:
    // Display methods
    static void showLoginScreen();
    static void showMainMenu();
    static void showBookMenu();
    static void showReaderMenu();
    static void showLoanMenu();
    
    // Input methods
    static string getPassword();
    static void clearScreen();
    static void pauseScreen();
    
    // Display header/footer
    static void showHeader(const string& strTitle);
    static void showSeparator();
};

#endif // CUIMANAGER_H
