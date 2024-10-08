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
//----------------------------------------------------------------------------------------------------


/* (2.2) Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. */

template <class T>
Node<T>* find_Kth_element(Node<T>* head, unsigned int k)
{
    if (head == nullptr) return nullptr;	// Linked List is empty

	Node<T>* n1 = head;
	Node<T>* n2 = head;

	// Move n2 to the Kth node from head or (size - k) from last:
	for (unsigned int i = 0; i <= k; i++)
	{
		if (n2 == nullptr) return n2;	// Out of bounds
		n2 = n2->m_next;
	}

	while (n2 != nullptr)
	{
		n1 = n1->m_next;
		n2 = n2->m_next;
	}
	return n1;
}
//----------------------------------------------------------------------------------------------------


/* (2.3) Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node. EXAMPLE:
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f 	*/

template <class T>
void DeleteMiddle(Node<T> *node)
{
	if (node == nullptr || node->m_next == nullptr) return;

	node->m_data = (node->m_next)->m_data;
	node->m_next = (node->m_next)->m_next;
	//delete node->m_next;	// Free the memory
}
//----------------------------------------------------------------------------------------------------


/* (2.4) Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions. EXAMPLE:
Input:
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
Output:
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8  	*/

template <class T>
Node<T>* partition(Node<T>* originalHead, int x)
{
	if (originalHead == nullptr || originalHead->m_next == nullptr) return originalHead;

	Node<T>* newHead = originalHead;
	Node<T>* newTail = originalHead;
	Node<T>* next = nullptr;

	while (originalHead != nullptr)
	{
		next = originalHead->m_next;	// Save the next node in the original Linked List

		if (originalHead->m_data < x)	// Insert at Head
		{
			originalHead->m_next = newHead;
			newHead = originalHead;
		}
		else	// Insert at Tail
		{
			newTail->m_next = originalHead;
			newTail = originalHead;
		}
		originalHead = next;	// Move to the next node in the original linked list
	}

	newTail->m_next = nullptr;
	return newHead;
}
//----------------------------------------------------------------------------------------------------


/* (2.5) Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list. EXAMPLE:
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2. That is, 912.	*/

Node<int>* sumList(Node<int>* curr1, Node<int>* curr2, int carry)
{
    if (curr1 == nullptr && curr2 == nullptr && carry == 0) return nullptr;

	Node<int>* result = new Node<int>();	// Allocate memory for the new node
	result->m_data = carry;
	result->m_next = nullptr;

	if (curr1 != nullptr)
	{
		result->m_data += curr1->m_data;
	}

	if (curr2 != nullptr)
	{
		result->m_data += curr2->m_data;
	}
	
	carry = result->m_data / 10;

	result->m_data = (result->m_data) % 10;

	if (curr1->m_next != nullptr || curr2->m_next != nullptr)
	{
		result->m_next = sumList(curr1->m_next, curr2->m_next, carry);	// Recursive call
	}

	return result;
}
//----------------------------------------------------------------------------------------------------


/* (2.6) Palindrome: Implement a function to check if a linked list is a palindrome */

template <class T>
bool isPalindrome(Node<T>* head)
{
    if (head == nullptr || head->m_next == nullptr) return true;
	
	// Part 1: Find the middle node
	Node<T>* slow = head; 
	Node<T>* fast = head;

	while (fast != nullptr && fast->m_next != nullptr)	// Move slow by 1 step and fast by 2, so slow reaches the middle
	{
		slow = slow->m_next;
		fast = (fast->m_next)->m_next;
	}

	// Part 2: Reverse the second half of the linked list
	Node<T>* prev = nullptr;
	Node<T>* curr = slow; 
	Node<T>* next = nullptr;

	while (curr != nullptr)
	{
		next = curr->m_next;	
		curr->m_next = prev;
		prev = curr;
		curr = next;
	}

	// Step 3: Compare the first half with the reverse second half
	Node<T>* firstHalf = head;
	Node<T>* secondHalf = prev;

	while (firstHalf != slow)	// slow is the middle node
	{
		if (firstHalf->m_data != secondHalf->m_data) return false;

		firstHalf = firstHalf->m_next;
		secondHalf = secondHalf->m_next;
	}
	return true;
}
//----------------------------------------------------------------------------------------------------


/* (2.7) Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting. 	*/

template <class T>
Node<T>* Intersection(Node<T>* head1, Node<T>* head2)
{
	if (head1 == nullptr || head2 == nullptr) return nullptr;

	// Part1: Find the last tail of each List and their sizes
	unsigned int size1 = 1, size2 = 1;

	Node<T>* curr1 = head1;
	Node<T>* curr2 = head2;

	while (curr1->m_next != nullptr) {
        curr1 = curr1->m_next;
        size1++;
    }

    while (curr2->m_next != nullptr) {
        curr2 = curr2->m_next;
        size2++;
    }
	
	// Otherwise, Both list have the same size.

	// Part 2: Check the last tail of each List to know if the lists are intersected or not
	if (curr1 != curr2) return nullptr;

	
	// Part 3: Move the pointer of the shorter list to his head, and the pointer of the longer list to his head + (abs(size1-size2)))
	curr1 = head1;
	curr2 = head2;
	
	if (size1 > size2)
	{
		for (unsigned int i = 0; i < size1 - size2; i++)
		{
			curr1 = curr1->m_next;
		}
	} 
	else if (size2 > size1)
	{
		for (unsigned int i = 0; i < size2 - size1; i++)
		{
			curr2 = curr2->m_next;
		}
	}
	

	// Part 4: find the first common node
	while (curr1 != curr2)
	{
		curr1 = curr1->m_next;
		curr2 = curr2->m_next;
	}

	return curr1;
}
//----------------------------------------------------------------------------------------------------