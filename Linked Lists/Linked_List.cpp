// #include <iostream>
// #include "Linked_List.h"

// using namespace std;

// template <class T>
// Single_Linked_List<T>::~Single_Linked_List()    // Destructor
// {
//     Node<T>* current = m_head;

//     Node<T>* nextNode;

//     while (current != nullptr)
//     {
//         nextNode = current->m_next;   // Store the next node
//         delete current;             // Delete the current node
//         current = nextNode;         // Move to the next node
//     }
// }


// template <class T>
// Single_Linked_List<T>::Single_Linked_List(const Single_Linked_List& other)   // CC
// {
//     Node<T>* current = other.m_head;
//     Node<T>* lastNode = nullptr;    

//     while (current != nullptr)
//     {
//         Node<T>* newNode = new Node<T>(current->m_data); // Create a new node

//         if (m_head == nullptr)
//         {
//             m_head = newNode;   // Set the head of the new Linked List
//         }
//         else
//         {
//             lastNode->m_next = current;
//         }

//         lastNode = newNode;         // Update lastNode to the new node

//         current = current->m_next;  // Move to the next node in the original linked list
//     }

//     m_tail = lastNode;      // Set tail to the last node added
// }


// template <class T>
// void Single_Linked_List<T>::InsertAtHead(T data)
// {   
//     Node<T>* newNode = new Node<T>(data);
    
//     newNode->m_next = m_head;

//     m_head = newNode;
// }

// template <class T>
// void Single_Linked_List<T>::InsertAtEnd(T data)
// {
//     Node<T>* newNode = new Node<T>(data);
    
//     if (m_head == nullptr)
//     {
//         m_head = newNode;

//         m_tail = m_head;    // Initialize tail if list is empty
//     }
//     else
//     {
//         m_tail->m_next = newNode;

//         m_tail = newNode;   // Move tail to the new node
//     }
// }


// template <class T>
// void Single_Linked_List<T>::Print() const
// {
//     Node<T>* current = m_head;
//     while (current != nullptr)
//     {
//         cout << current->m_data << " -> ";
//         current = current->m_next;
//     }
//     cout << "nullptr" << endl; // Indicate the end of the linked list
// }
