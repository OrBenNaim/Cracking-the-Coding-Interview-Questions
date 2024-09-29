#include <iostream>
#include "../Linked Lists/Linked_List.h" // Include your Linked List header

using namespace std;

int main() {
    // Create a single linked list of integers
    Single_Linked_List<int> linkedList;

    // Insert some elements into the list
    linkedList.InsertAtEnd(10);
    linkedList.InsertAtEnd(20);
    linkedList.InsertAtEnd(30);
    linkedList.InsertAtEnd(40);
    
    // Print the list to verify insertion
    cout << "\nLinked List after inserting elements: ";
    linkedList.Print();

    // Use the iterator to traverse and print the list elements
    cout << "\nTraversing the list using the iterator: \n";

    Single_Linked_List<int>::Iterator it = linkedList.begin();

    cout << *it << " ";
    ++it;
    cout << *it << " ";
    // it++;
    // cout << *it << " ";

    // for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
    //     cout << *it << " ";
    // }
    cout << endl;

    // // Delete an element
    // linkedList.deleteNode(20);
    
    // // Print the list to verify deletion
    // cout << "Linked List after deleting 20: ";
    // linkedList.Print();

    // // Testing copy constructor
    // Single_Linked_List<int> copiedList = linkedList;
    // cout << "Copied list: ";
    // copiedList.Print();

    // Clean up (optional since we are returning from main, but good practice)
    return 0;
}
