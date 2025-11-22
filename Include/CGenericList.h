template <class T>
struct Node {
    T data;
    Node<T>* pNext; // STANDARD II.3: Pointer prefix 'p'
};

template <class T>
class CGenericList {
private:
    Node<T>* m_pHead;
    int      m_iCount;

public:
    CGenericList() {
        m_pHead = NULL; // STANDARD II.22: Khoi tao bien
        m_iCount = 0;
    }

    void add(T item) {
        // Logic them node vao danh sach
    }
    
    // Nho viet ham huy (Destructor) de xoa bo nho!
    ~CGenericList(); 
};