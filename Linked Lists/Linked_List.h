#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T m_data;
    Node* m_next;     // Pointer to the next node

    // Constructor to initialize node data
    Node(T data=NULL) : m_data(data), m_next(nullptr) {}
};


template <class T>
class Single_Linked_List
{
    private:   
        Node<T>* m_head;    // Head of the Linked List

        Node<T>* m_tail;    // The end of the Linked List

    public:
        Single_Linked_List() : m_head{nullptr} {};   // Default constructor

        Single_Linked_List(const Single_Linked_List& other);   // CC
        
        ~Single_Linked_List();  // Destructor

        void InsertAtHead(T data);

        void InsertAtEnd(T data);
        
        void Print() const;
};

#endif // LINKEDLIST_H