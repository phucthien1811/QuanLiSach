#include "../Include/CUIManager.h"
#include <iostream>
#include <conio.h>  // For _getch() on Windows

using namespace std;

// Clear screen
void CUIManager::clearScreen() {
    system("cls");  // Windows command
}

// Pause screen
void CUIManager::pauseScreen() {
    cout << "\n\nNhan phim bat ky de tiep tuc...";
    _getch();
}

// Show header
void CUIManager::showHeader(const string& strTitle) {
    showSeparator();
    cout << "      " << strTitle << endl;
    showSeparator();
}

// Show separator
void CUIManager::showSeparator() {
    cout << "========================================" << endl;
}

// Show login screen
void CUIManager::showLoginScreen() {
    clearScreen();
    showHeader("HE THONG QUAN LY THU VIEN");
    cout << "\n      DANG NHAP HE THONG\n" << endl;
}

// Show main menu
void CUIManager::showMainMenu() {
    clearScreen();
    showHeader("MENU CHINH");
    cout << "\n1. Quan ly Sach" << endl;
    cout << "2. Quan ly Ban Doc" << endl;
    cout << "3. Quan ly Muon Tra Sach" << endl;
    cout << "4. Thong Ke & Bao Cao" << endl;
    cout << "0. Thoat" << endl;
    showSeparator();
    cout << "Nhap lua chon: ";
}

// Show book management menu
void CUIManager::showBookMenu() {
    clearScreen();
    showHeader("QUAN LY SACH");
    cout << "\n1. Them Sach Moi" << endl;
    cout << "2. Xoa Sach" << endl;
    cout << "3. Hien Thi Danh Sach Sach" << endl;
    cout << "4. Tim Kiem Sach" << endl;
    cout << "0. Quay Lai" << endl;
    showSeparator();
    cout << "Nhap lua chon: ";
}

// Show reader management menu
void CUIManager::showReaderMenu() {
    clearScreen();
    showHeader("QUAN LY BAN DOC");
    cout << "\n1. Them Ban Doc Moi" << endl;
    cout << "2. Xoa Ban Doc" << endl;
    cout << "3. Hien Thi Danh Sach Ban Doc" << endl;
    cout << "4. Tim Kiem Ban Doc" << endl;
    cout << "0. Quay Lai" << endl;
    showSeparator();
    cout << "Nhap lua chon: ";
}

// Show loan management menu
void CUIManager::showLoanMenu() {
    clearScreen();
    showHeader("QUAN LY MUON TRA SACH");
    cout << "\n1. Muon Sach" << endl;
    cout << "2. Tra Sach" << endl;
    cout << "3. Hien Thi Danh Sach Phieu Muon" << endl;
    cout << "4. Tim Kiem Phieu Muon" << endl;
    cout << "0. Quay Lai" << endl;
    showSeparator();
    cout << "Nhap lua chon: ";
}

// Get password with masking (using *)
string CUIManager::getPassword() {
    string strPassword = "";
    char ch;
    
    while (true) {
        ch = _getch();  // Get character without echo
        
        if (ch == 13) {  // Enter key
            break;
        }
        else if (ch == 8) {  // Backspace
            if (strPassword.length() > 0) {
                strPassword.pop_back();
                cout << "\b \b";  // Erase last character on screen
            }
        }
        else {
            strPassword += ch;
            cout << '*';  // Display asterisk
        }
    }
    
    cout << endl;
    return strPassword;
}
