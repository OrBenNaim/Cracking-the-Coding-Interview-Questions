#include <iostream>
#include <string>
#include <unordered_map>

#include "functions.h"
#include "tests.h"

using namespace std;

//-------------------- Test for 2.1 problem --------------------
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
//-------------------------------------------------------------------------


//-------------------- Test for 2.2 problem --------------------
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
//-------------------------------------------------------------------------


//-------------------- Test for 2.3 problem --------------------
void test_deleteMiddle()
{
	cout << "Output of Question 2.3:" << endl;

	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int arr_len = sizeof(arr)/sizeof(arr[0]);
	Single_Linked_List<char> L(arr, arr_len);
	cout << "The original Linked List is: ";

	L.Print();

	Node<char>* node_to_be_deleted = L.GetNode('c');

	deleteMiddle(node_to_be_deleted);
	
	cout << "\nThe Linked List after deletion of 'c'" << " is: ";
	L.Print();
}
//-------------------------------------------------------------------------


//-------------------- Test for 2.4 problem --------------------
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
	cout << "nullptr" << endl;
}
//-------------------------------------------------------------------------


//-------------------- Test for 2.5 problem --------------------
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
//-------------------------------------------------------------------------


//-------------------- Test for 2.6 problem --------------------
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
				cout << "False" << endl;
			}
		}
	}
}
//-------------------------------------------------------------------------


//-------------------- Test for 2.7 problem --------------------
void test_intersection()
{
	cout << "\nOutput of Question 2.7:" << endl;

    Node<int>* n1 = new Node<int>(1); 
	Node<int>* n2 = new Node<int>(2); 
	n1->m_next = n2;

	Node<int>* n3 = new Node<int>(3); 
	Node<int>* n4 = new Node<int>(4);
	Node<int>* n5 = new Node<int>(5);
	n3->m_next = n4;
	n4->m_next = n5;

	Node<int>* intersectionNode = new Node<int>(100); 
	n2->m_next = intersectionNode;
	n5->m_next = intersectionNode;
	
	Node<int>* n6 = new Node<int>(6);
	Node<int>* n7 = new Node<int>(7);

	intersectionNode->m_next = n6;
	n6->m_next = n7;

    // Print both lists:
    cout << "List 1: ";

	Node<int>* curr1 = n1;
	Node<int>* curr2 = n3;

	while (curr1 != nullptr)
	{
		cout << curr1->m_data << " -> ";
		curr1 = curr1->m_next;
	}
	cout << "nullptr";

    cout << "\nList 2: ";
    while (curr2 != nullptr)
	{
		cout << curr2->m_data << " -> ";
		curr2 = curr2->m_next;
	}
	cout << "nullptr\n";

    // Find intersection
    Node<int>* intersectNode = intersection(n1, n3);

    // Display the result
    if (intersectNode != nullptr) 
	{
        cout << "\nIntersection found at node with value: " << intersectNode->m_data << "\n";
    } 
	else 
	{
        cout << "\nNo intersection found.\n";
    }
}
//-------------------------------------------------------------------------


//-------------------- Test for 2.8 problem --------------------
