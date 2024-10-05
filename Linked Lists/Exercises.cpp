#include <iostream>
#include <string>
#include "../Linked Lists/Linked_List.h"
#include <unordered_map>

using namespace std;

/* (2.1) Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? */ 
template <class T>
void removeDupsWithBuffer(Node<T>* head);	// Using temporary buffer

template <class T>
void removeDupsWithoutBuffer(Node<T>* head);	// Without using temporary buffer

void test_removeDups();


/* (2.2) Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. */
template <class T>
Node<T>* find_Kth_element(Node<T>* head, unsigned int k);
void test_find_Kth_element();


/* (2.3) Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node. EXAMPLE:
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f */
template <class T>
void DeleteMiddle(Node<T>* node);
void test_DeleteMiddle();


/* (2.4) Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions. EXAMPLE:
Input:
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
Output:
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8  */
template <class T>
Node<T>* partition(Node<T>* originalHead, int x);
void test_partition();


/* (2.5) Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list. EXAMPLE:
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
*/
Node<int>* sumList(Node<int>* curr1, Node<int>* curr2, int carry=0);
void test_sumList();


/* (2.6) Palindrome: Implement a function to check if a linked list is a palindrome */
template <class T>
bool isPalindrome(Node<T>* head);
void test_isPalindrome();


int main()
{
    // When you declare a function pointer in C++, you can use the following syntax: void (*funcPtr)();
	// void is what the functions returns in this case, () is the functions parameters which is empty in this case.
	// When you want to create an array of such function pointers, you extend the syntax: void (*funcList[])();

	void (*funcList[])() = {test_removeDups, test_find_Kth_element, test_DeleteMiddle, test_partition,
							test_sumList, test_isPalindrome};

	for (auto& func : funcList) // auto allows the compiler to automatically deduce the type of func based on the type of elements in funcList.
	{
    	func();  // Calls the function pointed to by func
		cout << "\n" << endl;
	}

    return 0;
}


void test_removeDups()
{
    cout << "\nOutput of Question 2.1:" << endl;
	
	string arr1[] = {"Or", "Avi", "Or", "Dor", "Dor", "bar"};
	unsigned int arr1_len = sizeof(arr1)/sizeof(arr1[0]);
	Single_Linked_List<string> L1(arr1, arr1_len);

	int arr2[] = {10, 20, 30, 20, 30, 40};
	unsigned int arr2_len = sizeof(arr2)/sizeof(arr2[0]);
	Single_Linked_List<int> L2(arr2, arr2_len);

	for(int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			cout << "Linked List 1 before removing duplicates: ";
			L1.Print();
			removeDupsWithBuffer(L1.GetHead());
			cout << "\nLinked List 1 after removing duplicates with buffer: ";
			L1.Print();
			cout << "\n" << endl;
		}
		else
		{
			cout << "Linked List 2 before removing duplicates: ";
			L2.Print();
			removeDupsWithoutBuffer(L2.GetHead());
			cout << "\nLinked List 2 after removing duplicates without buffer: ";
			L2.Print();
		}
	}
	
}


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


void test_find_Kth_element()
{
	cout << "Output of Question 2.2:" << endl;
	
	Single_Linked_List<int> L;

	for (int i = 0; i < 7; i++)
	{
		L.InsertAtEnd(i+1);
	}
	cout << "The Linked List is: ";
	L.Print();

	Node<int>* node = find_Kth_element(L.GetHead(), 5);

	if (node != nullptr)
	{
		cout << "\nThe " << 5 << "th to last element is: " << node->m_data << endl;
	}
	else
	{
		cout << "\nThe " << 5 << "th to last element not exist" << endl;
	}
}



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



void test_DeleteMiddle()
{
	cout << "Output of Question 2.3:" << endl;

	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int arr_len = sizeof(arr)/sizeof(arr[0]);
	Single_Linked_List<char> L(arr, arr_len);
	cout << "The original Linked List is: ";

	L.Print();

	Node<char>* node_to_be_deleted = L.GetNode('c');

	DeleteMiddle(node_to_be_deleted);
	
	cout << "\nThe Linked List after deletion of 'c'" << " is: ";
	L.Print();
}



template <class T>
void DeleteMiddle(Node<T> *node)
{
	if (node == nullptr || node->m_next == nullptr) return;

	node->m_data = (node->m_next)->m_data;
	node->m_next = (node->m_next)->m_next;
	//delete node->m_next;	// Free the memory
}



void test_partition()
{
	cout << "Output of Question 2.4:" << endl;

	int arr[] = {3, 5, 8, 5, 10, 2, 1};
	unsigned int arr_len = sizeof(arr)/sizeof(arr[0]);
	Single_Linked_List<int> L(arr, arr_len);
	cout << "The original Linked List is: ";

	L.Print();

	Node<int>* newHead = partition(L.GetHead(), 5);

	cout << "The Linked List after partition is: ";
	
	while (newHead != nullptr)
	{
		cout << newHead->m_data << "-> ";
		newHead = newHead->m_next;
	}
	cout << "nullptr";
}



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



void test_sumList()
{
    cout << "\nOutput of Question 2.5:" << endl;

    int arr1[] = {7, 1, 6};
    unsigned int arr1_len = sizeof(arr1)/sizeof(arr1[0]);
    Single_Linked_List<int> L1(arr1, arr1_len);

    cout << "L1 Linked List is: ";
    L1.Print();

    int arr2[] = {5, 9, 2};
    unsigned int arr2_len = sizeof(arr2)/sizeof(arr2[0]);
    Single_Linked_List<int> L2(arr2, arr2_len);

    cout << "L2 Linked List is: ";
    L2.Print();

    Node<int>* newHead = sumList(L1.GetHead(), L2.GetHead());

    cout << "\nThe sum List is: ";
    
    // Store the head of the sum list in a separate pointer for deletion later
    Node<int>* tempHead = newHead;
    
    while(newHead != nullptr)
    {
        cout << newHead->m_data << " -> ";	// Read output from tail to head (reverase direction)
        newHead = newHead->m_next;
    }

    cout << "nullptr" << endl;

    // Reset newHead to tempHead for deletion
    newHead = tempHead;
    
    // Free the sumList memory after use:
    while (newHead != nullptr) 
    {
        Node<int>* temp = newHead;
        newHead = newHead->m_next;
        delete temp;  // Free each node
    }
}


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


void test_isPalindrome()
{
	cout << "\nOutput of Question 2.6:" << endl;

	char arr1[] = {'a', 'b', 'c', 'b', 'a'};
    unsigned int arr1_len = sizeof(arr1)/sizeof(arr1[0]);
    Single_Linked_List<char> L1(arr1, arr1_len);

    char arr2[] = {'a', 'b', 'c'};
    unsigned int arr2_len = sizeof(arr2)/sizeof(arr2[0]);
    Single_Linked_List<char> L2(arr2, arr2_len);

	for(int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			cout << "Is L1 Linked List palindrome?" << endl;
    		L1.Print();
			if (isPalindrome(L1.GetHead()))
			{
				cout << "True\n" << endl;
			}
			else
			{
				cout << "False\n" << endl;
			}
		}
		else
		{
			cout << "Is L2 Linked List palindrome?" << endl;
    		L2.Print();
			
			if (isPalindrome(L1.GetHead()))
			{
				cout << "True\n" << endl;
			}
			else
			{
				cout << "False\n" << endl;
			}
		}
	}
}


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