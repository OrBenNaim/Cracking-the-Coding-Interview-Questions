#include <iostream>
#include <string>
#include <unordered_map>

#include "../Linked Lists/Linked_List.h"
#include "functions_signature.h"

using namespace std;


/* (2.1) Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? */

template <class T>
void removeDupsWithBuffer(Node<T>* head)	// Using temporary buffer
{
	if (head == nullptr) return;	// Return if linked list is empty

	Node<T>* current = head;
	Node<T>* prev = nullptr;

	unordered_map<T, bool> hashTable;

	while (current != nullptr)
	{
		if (hashTable.find(current->m_data) != hashTable.end())	// If Data already exist in hashTable
		{
			prev->m_next = current->m_next;		// Skip the duplicate node
			delete current;						// Free the memory of the duplicate node
			current = prev->m_next;				// Move to the next node
		}
		else	// Add to the hashTable
		{
			hashTable[current->m_data] = true;
			prev = current;
			current = current->m_next;
		}
	}
}


template <class T>
void removeDupsWithoutBuffer(Node<T>* head)	// Without using temporary buffer
{
	if (head == nullptr) return;	// Return if linked list is empty

	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* runner = current->m_next;

	while (current != nullptr)
	{
		prev = current;				// Set 'prev' to current node
		runner = current->m_next;	// Set 'runner' to the node after current

		while (runner != nullptr)
		{
			if (runner->m_data == current->m_data)	// Duplicate found
			{
				prev->m_next = runner->m_next;	// Skip the duplicate node
				delete runner;					// Free the memory of the duplicate node
				runner = prev->m_next;			// Move to the next node
			}
			else
			{
				prev = runner;		// Move to the next node
				runner = runner->m_next;	// Move to the next node
			}
		}
		current = current->m_next;			// Move to the next node
	}
}
