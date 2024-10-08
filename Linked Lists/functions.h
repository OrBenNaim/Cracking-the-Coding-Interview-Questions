#ifndef FUNCTIONS_H
#define FUNCTIONS_H
 
 #include <iostream>
 #include <string>
 #include <unordered_map>

 #include "Linked_List.h"

 using namespace std;


 /* (2.1) remove dups: write code to remove duplicates from an unsorted linked list.
 follow up
 how would you solve this problem if a temporary buffer is not allowed? */

 template <class T>
 void removeDupsWithBuffer(Node<T>* head)	// using temporary buffer
 {
 	if (head == nullptr) return;	// return if linked list is empty

 	Node<T>* current = head;
 	Node<T>* prev = nullptr;

 	unordered_map<T, bool> hashtable;

 	while (current != nullptr)
 	{
 		if (hashtable.find(current->m_data) != hashtable.end())	// if data already exist in hashtable
 		{
 			prev->m_next = current->m_next;		// skip the duplicate Node
 			delete current;						// free the memory of the duplicate Node
 			current = prev->m_next;				// move to the next Node
 		}
 		else	// add to the hashtable
 		{
 			hashtable[current->m_data] = true;
 			prev = current;
 			current = current->m_next;
 		}
 	}
 }


 template <class t>
 void removeDupsWithoutBuffer(Node<t>* head)	// without using temporary buffer
 {
 	if (head == nullptr) return;	// return if linked list is empty

 	Node<t>* current = head;
 	Node<t>* prev = nullptr;
 	Node<t>* runner = current->m_next;

 	while (current != nullptr)
 	{
 		prev = current;				// set 'prev' to current Node
 		runner = current->m_next;	// set 'runner' to the Node after current

 		while (runner != nullptr)
 		{
 			if (runner->m_data == current->m_data)	// duplicate found
 			{
 				prev->m_next = runner->m_next;	// skip the duplicate Node
 				delete runner;					// free the memory of the duplicate Node
 				runner = prev->m_next;			// move to the next Node
 			}
 			else
 			{
 				prev = runner;		// move to the next Node
 				runner = runner->m_next;	// move to the next Node
 			}
 		}
 		current = current->m_next;			// move to the next Node
 	}
 }
 //----------------------------------------------------------------------------------------------------


 /* (2.2) return kth to last: implement an algorithm to find the kth to last element of a singly linked list. */

 template <class t>
 Node<t>* find_Kth_element(Node<t>* head, unsigned int k)
 {
     if (head == nullptr) return nullptr;	// linked list is empty

 	Node<t>* n1 = head;
 	Node<t>* n2 = head;

 	// move n2 to the kth Node from head or (size - k) from last:
 	for (unsigned int i = 0; i <= k; i++)
 	{
 		if (n2 == nullptr) return n2;	// out of bounds
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


 /* (2.3) delete middle Node: implement an algorithm to delete a Node in the middle (i.e., any Node but
 the first and last Node, not necessarily the exact middle) of a singly linked list, given only access to
 that Node. example:
 lnput:the Node c from the linked lista->b->c->d->e->f
 result: nothing is returned, but the new linked list looks like a->b->d->e->f 	*/

 template <class t>
 void deleteMiddle(Node<t> *Node)
 {
 	if (Node == nullptr || Node->m_next == nullptr) return;

 	Node->m_data = (Node->m_next)->m_data;
 	Node->m_next = (Node->m_next)->m_next;
 	//delete Node->m_next;	// free the memory
 }
 //----------------------------------------------------------------------------------------------------


 /* (2.4) partition: write code to partition a linked list around a value x, such that all Nodes less than x come
 before all Nodes greater than or equal to x. if x is contained within the list, the values of x only need
 to be after the elements less than x (see below). the partition element x can appear anywhere in the
 "right partition"; it does not need to appear between the left and right partitions. example:
 input:
 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
 output:
 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8  	*/

 template <class T>
 Node<T>* partition(Node<T>* originalhead, int x)
 {
 	if (originalhead == nullptr || originalhead->m_next == nullptr) return originalhead;

 	Node<T>* newhead = originalhead;
 	Node<T>* newtail = originalhead;
 	Node<T>* next = nullptr;

 	while (originalhead != nullptr)
 	{
 		next = originalhead->m_next;	// save the next Node in the original linked list

 		if (originalhead->m_data < x)	// insert at head
 		{
 			originalhead->m_next = newhead;
 			newhead = originalhead;
 		}
 		else	// insert at tail
 		{
 			newtail->m_next = originalhead;
 			newtail = originalhead;
 		}
 		originalhead = next;	// move to the next Node in the original linked list
 	}

 	newtail->m_next = nullptr;
 	return newhead;
 }
 //----------------------------------------------------------------------------------------------------


 /* (2.5) sum lists: you have two numbers represented by a linked list, where each Node contains a single
 digit. the digits are stored in reverse order, such that the 1 's digit is at the head of the list. write a
 function that adds the two numbers and returns the sum as a linked list. example:
 input: (7-> 1 -> 6) + (5 -> 9 -> 2).that is,617 + 295.
 output: 2 -> 1 -> 9. that is, 912.
 follow up
 suppose the digits are stored in forward order. repeat the above problem.
 example
 lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).that is,617 + 295.
 output: 9 -> 1 -> 2. that is, 912.	*/

 Node<int>* sumList(Node<int>* curr1, Node<int>* curr2, int carry=0)
 {
    if (curr1 == nullptr && curr2 == nullptr && carry == 0) return nullptr;

 	Node<int>* result = new Node<int>();	// allocate memory for the new Node
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
 		result->m_next = sumList(curr1->m_next, curr2->m_next, carry);	// recursive call
 	}

 	return result;
 }
 //----------------------------------------------------------------------------------------------------


 /* (2.6) palindrome: implement a function to check if a linked list is a palindrome */

 template <class T>
 bool isPalindrome(Node<T>* head)
 {
     if (head == nullptr || head->m_next == nullptr) return true;
	
 	// part 1: find the middle Node
 	Node<T>* slow = head; 
 	Node<T>* fast = head;

 	while (fast != nullptr && fast->m_next != nullptr)	// move slow by 1 step and fast by 2, so slow reaches the middle
 	{
 		slow = slow->m_next;
 		fast = (fast->m_next)->m_next;
 	}

 	// part 2: reverse the second half of the linked list
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

 	// step 3: compare the first half with the reverse second half
 	Node<T>* firsthalf = head;
 	Node<T>* secondhalf = prev;

 	while (firsthalf != slow)	// slow is the middle Node
 	{
 		if (firsthalf->m_data != secondhalf->m_data) return false;

 		firsthalf = firsthalf->m_next;
 		secondhalf = secondhalf->m_next;
 	}
 	return true;
 }
 //----------------------------------------------------------------------------------------------------


 /* (2.7) intersection: given two (singly) linked lists, determine if the two lists intersect. return the intersecting Node. note that the intersection is defined based on reference, not value. that is, if the kth
 Node of the first linked list is the exact same Node (by reference) as the jth Node of the second
 linked list, then they are intersecting. 	*/

 template <class T>
 Node<T>* intersection(Node<T>* head1, Node<T>* head2)
 {
 	if (head1 == nullptr || head2 == nullptr) return nullptr;

 	// part1: find the last tail of each list and their sizes
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
	
 	// otherwise, both list have the same size.

 	// part 2: check the last tail of each list to know if the lists are intersected or not
 	if (curr1 != curr2) return nullptr;

	
 	// part 3: move the pointer of the shorter list to his head, and the pointer of the longer list to his head + (abs(size1-size2)))
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
	

 	// part 4: find the first common Node
 	while (curr1 != curr2)
 	{
 		curr1 = curr1->m_next;
 		curr2 = curr2->m_next;
 	}

 	return curr1;
 }
 //----------------------------------------------------------------------------------------------------
 
 #endif // !FUNCTIONS_H