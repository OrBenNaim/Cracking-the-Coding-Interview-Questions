#include <iostream>
#include "Linked_List.h"

int main() {
    Single_Linked_List<int> list;

    // Insert elements at the head
    list.InsertAtHead(10);
    list.InsertAtHead(20);

    // Insert elements at the end
    list.InsertAtEnd(30);
    list.InsertAtEnd(40);

    // Print the list
    cout << "Current List: ";
    list.Print();

    return 0;
}