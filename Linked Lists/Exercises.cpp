#include <iostream>
#include <stdlib.h>
#include "../Linked Lists/Linked_List.h"
#include <unordered_map>

using namespace std;

/* (2.1) Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? */ 
void removeDupsWithBuffer(Single_Linked_List<int>& L);	// Using temporary buffer
//void removeDupsWithoutBuffer(Single_Linked_List<int>& L);	// Without using temporary buffer
void test_removeDups();


int main()
{
    // When you declare a function pointer in C++, you can use the following syntax: void (*funcPtr)();
	// void is what the functions returns in this case, () is the functions parameters which is empty in this case.
	// When you want to create an array of such function pointers, you extend the syntax: void (*funcList[])();

	void (*funcList[])() = {test_removeDups};

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
	
	int arr[] = {10, 20, 20, 3, 3, 4};
	size_t arr_len = sizeof(arr)/sizeof(arr[0]);

	Single_Linked_List<int> L1(arr, arr_len);

	cout << "\nThe Linked List before removing duplicates: ";
	L1.Print();

	removeDupsWithBuffer(L1);
	cout << "\nThe Linked List after removing duplicates: ";
	L1.Print();
}


void removeDupsWithBuffer(Single_Linked_List<int> &L)	// Using temporary buffer
{
	Single_Linked_List<int>::Iterator it = L.begin();
	
	if (it.current_ptr == nullptr) return;	// Return if linked list is empty

	unordered_map<int, int> hashTable;

	
	for (it = L.begin(); it != L.end(); ++it)
	{
		// If value already exist -> delete it
		if (hashTable.find(it->m_data) != hashTable.end())	
		{
			L.deleteNode(it.current_ptr);
			//L.deleteNode(it->m_data);	// Delete node by its value
		}
		else	// Add to the hashTable
		{
			hashTable[it->m_data] = 1;
		}
	}
}

// void removeDupsWithoutBuffer(Single_Linked_List<int> &L)	// Without using temporary buffer
// {
	
// }
