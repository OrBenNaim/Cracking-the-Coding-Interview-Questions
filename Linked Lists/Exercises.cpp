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



int main()
{
    // When you declare a function pointer in C++, you can use the following syntax: void (*funcPtr)();
	// void is what the functions returns in this case, () is the functions parameters which is empty in this case.
	// When you want to create an array of such function pointers, you extend the syntax: void (*funcList[])();

	void (*funcList[])() = {test_removeDups, test_find_Kth_element, test_DeleteMiddle};

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


