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
T& find_Kth_element();
void test_find_Kth_element();

int main()
{
    // When you declare a function pointer in C++, you can use the following syntax: void (*funcPtr)();
	// void is what the functions returns in this case, () is the functions parameters which is empty in this case.
	// When you want to create an array of such function pointers, you extend the syntax: void (*funcList[])();

	void (*funcList[])() = {test_removeDups, test_find_Kth_elemen};

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
	size_t arr1_len = sizeof(arr1)/sizeof(arr1[0]);
	Single_Linked_List<string> L1(arr1, arr1_len);

	int arr2[] = {10, 20, 30, 20, 30, 40};
	size_t arr2_len = sizeof(arr2)/sizeof(arr2[0]);
	Single_Linked_List<int> L2(arr2, arr2_len);

	for(int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			cout << "\nLinked List 1 before removing duplicates: ";
			L1.Print();
			removeDupsWithBuffer(L1.GetHead());
			cout << "\nLinked List 1 after removing duplicates with buffer: ";
			L1.Print();
			cout << "\n" << endl;
		}
		else
		{
			cout << "\nLinked List 2 before removing duplicates: ";
			L2.Print();
			removeDupsWithoutBuffer(L2.GetHead());
			cout << "\nLinked List 2 after removing duplicates without buffer: ";
			L2.Print();
		}
	}
	
}


void test_find_Kth_element()
{

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




template <class T>
T &find_Kth_element()
{
    // TODO: insert return statement here
}
