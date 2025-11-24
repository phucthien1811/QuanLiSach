#ifndef CGENERICLIST_H
#define CGENERICLIST_H

// Template Node structure for singly linked list
template<typename T>
struct Node {
    T data;
    Node<T>* pNext;

    // Constructor
    Node(const T& item) : data(item), pNext(NULL) {}
};

// Template class for Generic Singly Linked List
template<typename T>
class CGenericList {
private:
    Node<T>* m_pHead;
    int m_iCount;

public:
    // Constructor
    CGenericList() : m_pHead(NULL), m_iCount(0) {}

    // Destructor
    ~CGenericList() {
        clear();
    }

    // Add item to the end of the list
    void add(T item) {
        Node<T>* pNewNode = new Node<T>(item);

        if (m_pHead == NULL) {
            m_pHead = pNewNode;
        }
        else {
            Node<T>* pCurrent = m_pHead;
            while (pCurrent->pNext != NULL) {
                pCurrent = pCurrent->pNext;
            }
            pCurrent->pNext = pNewNode;
        }
        m_iCount++;
    }

    // Remove node matching the item (uses operator==)
    bool remove(T item) {
        if (m_pHead == NULL) {
            return false;
        }

        // Check if head node matches
        if (m_pHead->data == item) {
            Node<T>* pTemp = m_pHead;
            m_pHead = m_pHead->pNext;
            delete pTemp;
            m_iCount--;
            return true;
        }

        // Search for the node
        Node<T>* pCurrent = m_pHead;
        while (pCurrent->pNext != NULL) {
            if (pCurrent->pNext->data == item) {
                Node<T>* pTemp = pCurrent->pNext;
                pCurrent->pNext = pCurrent->pNext->pNext;
                delete pTemp;
                m_iCount--;
                return true;
            }
            pCurrent = pCurrent->pNext;
        }
        return false;
    }

    // Find and return pointer to data if found, else NULL
    T* find(T item) {
        Node<T>* pCurrent = m_pHead;
        while (pCurrent != NULL) {
            if (pCurrent->data == item) {
                return &(pCurrent->data);
            }
            pCurrent = pCurrent->pNext;
        }
        return NULL;
    }

    // Clear all nodes and free memory
    void clear() {
        Node<T>* pCurrent = m_pHead;
        while (pCurrent != NULL) {
            Node<T>* pTemp = pCurrent;
            pCurrent = pCurrent->pNext;
            delete pTemp;
        }
        m_pHead = NULL;
        m_iCount = 0;
    }

    // Get count of items
    int getCount() const {
        return m_iCount;
    }

    // Get head node (for traversal)
    Node<T>* getHead() const {
        return m_pHead;
    }
};

#endif // CGENERICLIST_H