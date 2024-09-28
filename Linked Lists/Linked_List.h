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


        void deleteByNode(Node<T>* node)
        {
            if (m_head == nullptr || node == nullptr) return;   // Linked List is empty or invalid node

            // If the node to be deleted is the head:
            if (m_head == node) 
            {
                Node<T>* temp = m_head;      // Store current head

                m_head = m_head->m_next;     // Move the head to the next node

                delete temp;                 // Delete the old head

                // If the list is now empty, update the tail
                if (m_head == nullptr) 
                {
                    m_tail = nullptr;
                }
                return;
            }

            Node<T>* current = m_head;

            // Find the node preceding the one to be deleted:
            while (current->m_next != nullptr && current->m_next != node)
            {
                current = current->m_next;
            }
            
            if (current->m_next == nullptr) return;     // The node doesn't exists in the linked list

            if (m_tail == node)
            {
                m_tail = current;     // Update tail to point to the previous node
            }
            
            current->m_next = node->m_next;     // Bypass the node

            delete node;    // Free memory
        }


        void deleteByVal(T val)
        {
            if (m_head == nullptr) return;  // Linked List is empty

            else if (m_head->m_data == val)
            {
                Node<T>* temp = m_head;

                m_head = m_head->m_next;

                delete temp;

                // If the list is now empty, update the tail:
                if (m_head == nullptr)
                {
                    m_tail = nullptr;
                }

                return;
            }
            
            Node<T>* current = m_head;

            // Find the node preceding the one to be deleted:
            while (current->m_next != nullptr && current->m_next->m_data != val)
            {
                current = current->m_next;
            }

            // If the node doesn't exist in the linked list, return:
            if (current->m_next == nullptr) return; 

            // If the node to be deleted is the tail:
            if (current->m_next == m_tail)
            {
                m_tail = current;   // Update tail to point to the previous node
            }

            Node<T>* nodeToDelete = current->m_next;  // Store the node to delete

            current->m_next = nodeToDelete->m_next;   // Bypass the node

            delete nodeToDelete;  // Free memory
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