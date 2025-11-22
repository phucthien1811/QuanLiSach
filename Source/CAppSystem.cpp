// File: Source/CAppSystem.cpp
void CAppSystem::run() {
    int iChoice = 0;
    do {
        // Hien thi menu
        m_uiManager.showMainMenu(); 
        cout << "Nhap lua chon: ";
        cin >> iChoice;

        // STANDARD II.13: Dùng switch cho menu
        switch (iChoice) {
            case 1:
                m_bookManager.showAllBooks();
                break;
            case 2:
                // Logic muon sach
                break;
            case 0:
                cout << "Ket thuc chuong trinh.";
                break;
            default:
                m_uiManager.printError("Lua chon khong hop le!");
                break;
        }
    } while (iChoice != 0);
}