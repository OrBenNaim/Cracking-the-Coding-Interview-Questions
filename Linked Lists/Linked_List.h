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
        Single_Linked_List() : m_head(nullptr), m_tail(nullptr) {};   // Default constructor

        Single_Linked_List(const Single_Linked_List& other)   // CC
        {
            m_head = nullptr;
            m_tail = nullptr;

            Node<T>* current = other.m_head;  

            while (current != nullptr)
            {
                InsertAtEnd(current->m_data);

                current = current->m_next;  // Move to the next node in the original linked list   
            }
        }
        
        ~Single_Linked_List()  // Destructor
        {
            Node<T>* current = m_head;

            Node<T>* nextNode;

            while (current != nullptr)
            {
                nextNode = current->m_next;   // Store the next node
                delete current;             // Delete the current node
                current = nextNode;         // Move to the next node
            }
        }

        void InsertAtHead(T data)
        {
            Node<T>* newNode = new Node<T>(data);
    
            newNode->m_next = m_head;

            m_head = newNode;

            if (m_tail == nullptr)  // Update tail as well
            {
                m_tail = newNode;   // Update tail as well
            }
        }

        void InsertAtEnd(T data)
        {
            Node<T>* newNode = new Node<T>(data);
    
            if (m_head == nullptr)
            {
                m_head = newNode;

                m_tail = m_head;    // Initialize tail if list is empty
            }
            else
            {
                m_tail->m_next = newNode;

                m_tail = newNode;   // Move tail to the new node
            }
        }
        
        void Print() const
        {
            Node<T>* current = m_head;
            while (current != nullptr)
            {
                cout << current->m_data << " -> ";
                current = current->m_next;
            }
            cout << "nullptr" << endl; // Indicate the end of the linked list
        }
};

#endif // LINKEDLIST_H