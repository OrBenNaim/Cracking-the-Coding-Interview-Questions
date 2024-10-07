#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "../Iterator Class/Generic_Iterator.h"

using namespace std;


template <class T>
struct Node
{
    T m_data;
    Node* m_next;     // Pointer to the next node

    // Constructor to initialize node data
    Node(T data=T()) : m_data(data), m_next(nullptr) {}

    friend ostream& operator<<(ostream& os, const Node<T>& node)
    {
        os << node.m_data;
        return os;
    }

    friend istream& operator>>(istream& is, const Node<T>& node)
    {
        is >> node.m_data; // Input into the current element
        
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


        void deleteNode(Node<T>* node)
        {
            if (m_head == nullptr || node == nullptr) return;   // Linked List is empty or invalid node

            // If the node to be deleted is the head:
            if (m_head == node) 
            {
                m_size--;
                
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

            Iterator it = this->begin();
            Iterator prev = it;     // Iterator to keep track of the previous node

            while (it != this->end() && it->m_next != node)
            {
                prev = it;      // Store the previous iterator
                ++it;           // Move to the next node
            }
            
            // If we have found the node:
            if (it != this->end())
            {
                prev->m_next = node->m_next;  // Bypass the node to be deleted

                if (node == m_tail)           // If node is the tail, update m_tail
                {
                    m_tail = prev.current_ptr;  // Update the tail
                }

                delete node;    // Free memory
                m_size--;
            }
        }


        void deleteNode(const T& val)      // Delete the first node with the given value
        {
            if (m_head == nullptr) return;  // Linked List is empty

            else if (m_head->m_data == val)     // If the head node is the one to be deleted
            {
                m_size--;
                
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
            
            Iterator it = this->begin();
            Iterator prev = it;

            while (it != this->end() && it->m_next->m_data != val)
            {
                prev = it;      // Store the previous iterator
                ++it;           // Move to the next node
            }

            // If we have found the node:
            if (it != this->end())
            {
                prev->m_next = it->m_next->m_next;  // Bypass the node to be deleted

                if (it->m_next == nullptr)  // If the node to be deleted is tail
                {
                    m_tail = prev.current_ptr;  // Update the tail
                }
                m_size--;
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


        class Iterator : public Generic_Iterator<Node<T>>
        {
            public:
                
                Iterator(Node<T>* ptr=nullptr) : Generic_Iterator<Node<T>>(ptr) {}
                
                // Prefix increment operator (++current_ptr) to move the iterator to the next element:
                Iterator& operator++() 
                {
                   if (this->current_ptr) 
                    {
                        this->current_ptr = this->current_ptr->m_next; // Move to next node
                    }
                    return *this;
                }

                
                /*The language design convention is to use int as the dummy argument. 
                It has no functional meaning in the post-increment operator itself, but using int follows the standard C++ convention,
                ensuring consistency across all custom iterator implementations.
                */
                Iterator operator++(int)      // Postfix increment operator (current_ptr++) to move the iterator to the next element:   
                {
                    Iterator temp = *this;
                    ++(*this);
                    return temp;
                }


                Node<T>* operator->() const
                {
                    return this->current_ptr;   // Allow access to node's members (like m_next)
                }
        };

        Iterator begin() const {return Iterator(m_head);}   // Iterator to the beginning of the Linked List


        Iterator end() const {return Iterator(nullptr);}
};

#endif // LINKEDLIST_H