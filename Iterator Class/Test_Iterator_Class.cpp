#include <iostream>
#include "../Linked Lists/Linked_List.h" // Include your Linked List header

using namespace std;

int main() {
    // Create a single linked list of integers
    Single_Linked_List<int> linkedList;

    // Insert some elements into the list directly
    linkedList.InsertAtEnd(10);
    linkedList.InsertAtEnd(20);
    linkedList.InsertAtEnd(30);
    linkedList.InsertAtEnd(40);
    
    // Print the list to verify insertion
    cout << "\nLinked List after inserting elements: ";
    linkedList.Print();

    // Use the iterator to traverse and print the list elements
    cout << "\nTraversing the list using the iterator: ";

    cout << "\n";

    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << it->m_data << " -> ";
    }
    cout << nullptr << endl;


    // Delete Node 20 by Node object
    Node<int>* nodeToDelete = linkedList.begin().current_ptr->m_next;  // Access the node with value 20
    linkedList.deleteNode(nodeToDelete);
    
    linkedList.deleteNode(nodeToDelete);

    // Print the list to verify deletion
    cout << "\nLinked List after deleting " << nodeToDelete->m_data << ": ";
    linkedList.Print();


    // Delete Node 30 by value
    linkedList.deleteNode(30);

    cout << "\nLinked List after deleting 30: ";
    linkedList.Print();


    // Testing copy constructor
    Single_Linked_List<int> copiedList = linkedList;
    cout << "\nCopied list: \n";

    copiedList.Print();

    // Clean up (optional since we are returning from main, but good practice)
    return 0;
}
