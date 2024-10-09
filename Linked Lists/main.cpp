#include "tests.h"

int main()
{
    test_removeDups();          // Test problem 2.1

    cout << "----------------------------------------------------------";

    test_find_Kth_element();    // Test problem 2.2

    cout << "----------------------------------------------------------";

    test_deleteMiddle();        // Test problem 2.3

    cout << "----------------------------------------------------------";

    test_partition();           // Test problem 2.4

    cout << "----------------------------------------------------------";

    test_sumList();             // Test problem 2.5

    cout << "----------------------------------------------------------";

    test_isPalindrome();        // Test problem 2.6

    cout << "----------------------------------------------------------";

    test_intersection();        // Test problem 2.7

    cout << "----------------------------------------------------------";

    test_loopDetection();       // Test problem 2.8
    
    return 0;
}