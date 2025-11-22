class CBook {
private:
    // STANDARD II.3: Hungarian Notation + m_ prefix
    string m_strISBN;    // Ma sach
    string m_strName;    // Ten sach
    int    m_iStatus;    // 0: Available, 1: Borrowed

public:
    CBook();
    // STANDARD II.6: Dùng const reference cho string
    void setISBN(const string& strISBN); 
    string getISBN() const;
};