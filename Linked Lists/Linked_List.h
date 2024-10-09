#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
 
using namespace std;


template <class T>
struct Node
{
    T m_data;
    Node* m_next;     // Pointer to the next node

    // Constructor to initialize node data
    Node(T data=T()) : m_data(data), m_next(nullptr) {}

    friend ostream& operator<<(ostream& os, const Node<T>* node)
    {
        os << node->m_data;
        return os;
    }

    friend istream& operator>>(istream& is, const Node<T>* node)
    {
        is >> node->m_data;     // Input into the current element
        
        return is;
    }
};


template <class T>
class Single_Linked_List
{
    private:   
        Node<T>* m_head;    // Head of the Linked List

        Node<T>* m_tail;    // The end of the Linked List

        unsigned int m_size;      // Count how many items exist

    public:
        Single_Linked_List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}   // Default constructor


        Single_Linked_List(const T* arr, size_t size) : m_head(nullptr), m_tail(nullptr), m_size(0)  // Constructor 
        {
            for (size_t i = 0; i < size; i++)
            {
                InsertAtEnd(arr[i]);
            }   
        }


        Single_Linked_List(const Single_Linked_List& other)   // CC
        {
            m_head = nullptr;
            m_tail = nullptr;

            m_size = other.m_size;

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

        Node<T>* GetHead() const {return m_head;}

        
        Node<T>* GetTail() const
        {
            if (m_head == nullptr) return nullptr;
            
            Node<T>* curr = m_head;

            while (curr->m_next != nullptr)
            {
                curr = curr->m_next;
            }
            return curr;
        }

        unsigned int GetSize() const {return m_size;} 


        Node<T>* GetNode(const T& val) const // Return the first node occurrence with the same value or nullptr if the value does not exits
        {
            Node <T>* current = m_head;
            while (current != nullptr)
            {
                if (current->m_data == val)
                {
                    return current;
                }
                current = current->m_next;
            }
            return nullptr;
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

            m_size++;
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

            m_size++;
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

#endif // !LINKED_LIST_H