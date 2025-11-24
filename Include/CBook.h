#ifndef CBOOK_H
#define CBOOK_H

#include <string>
using namespace std;

class CBook {
private:
    string m_strBookID;      // Mã sách (duy nhất)
    string m_strTitle;       // Tên sách
    string m_strAuthor;      // Tác giả
    string m_strPublisher;   // Nhà xuất bản
    float m_fPrice;          // Giá bán
    int m_iYearPublished;    // Năm phát hành
    int m_iPages;            // Số trang
    string m_strDateAdded;   // Ngày nhập kho
    int m_iStatus;           // Tình trạng sách (0: đã mượn, >0: còn sách)

public:
    // Constructor
    CBook();
    CBook(string bookID, string title, string author, string publisher, 
          float price, int year, int pages, string dateAdded, int status);
    
    // Destructor
    ~CBook();
    
    // Getters
    string getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getPublisher() const;
    float getPrice() const;
    int getYearPublished() const;
    int getPages() const;
    string getDateAdded() const;
    int getStatus() const;
    
    // Setters
    void setBookID(string bookID);
    void setTitle(string title);
    void setAuthor(string author);
    void setPublisher(string publisher);
    void setPrice(float price);
    void setYearPublished(int year);
    void setPages(int pages);
    void setDateAdded(string dateAdded);
    void setStatus(int status);
    
    // Methods
    void displayInfo() const;
    bool isAvailable() const;
};

#endif