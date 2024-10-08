#include "tests.h"


int main()
{
    test_isUnique();          // Test problem 1.1

    cout << "----------------------------------------------------------\n";

    test_checkPermutation();    // Test problem 1.2

    cout << "----------------------------------------------------------\n";

    test_replaceSpaces();        // Test problem 1.3

    cout << "----------------------------------------------------------\n";

    test_permutationPalindrome();           // Test problem 1.4

    cout << "----------------------------------------------------------\n";

    test_checkOneAway();             // Test problem 1.5

    cout << "----------------------------------------------------------\n";

    test_compression();        // Test problem 1.6

    cout << "----------------------------------------------------------\n";

    test_rotate();        // Test problem 1.7

    cout << "----------------------------------------------------------\n";

    test_zeroMat();        // Test problem 1.8

    cout << "----------------------------------------------------------\n";

    test_isRotation();        // Test problem 1.9

    cout << "----------------------------------------------------------\n";
    
    return 0;
}