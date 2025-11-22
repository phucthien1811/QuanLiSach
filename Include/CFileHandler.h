// File: Source/CFileHandler.cpp
bool CFileHandler::loadBooks(const string& strPath, CGenericList<CBook>& list) {
    ifstream fileInput;
    fileInput.open(strPath.c_str());

    // Check file ton tai
    if (!fileInput.is_open()) {
        return false; 
    }

    string strLine;
    while (getline(fileInput, strLine)) {
        // Parse chuoi: BK001|Ten Sach|...
        // Tao doi tuong CBook moi
        CBook book; 
        // ... logic tach chuoi va set data cho book ...
        
        list.add(book);
    }

    fileInput.close(); // STANDARD II.18: BAT BUOC PHAI CO
    return true;
}