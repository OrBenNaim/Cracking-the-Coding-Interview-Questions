#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <list>

#include "functions.h"

using namespace std;


//-------------------- Test for 1.1 problem --------------------
void test_isUnique()
{
	char str[] = "abcdd";

	printf("\nOutput of Question 1.1:");

	if (isUnique(str))
	{
		printf("\n'%s' has all unique characters\n", str);
	}
	else
	{
		printf("\n'%s' hasn't all unique characters\n", str);
	}
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.2 problem --------------------
void test_checkPermutation()
{
	string str1 = "abc", str2 = "cba";

	cout << "\nOutput of Question 1.2:" << endl ;

	if (checkPermutation(str1, str2))
	{
		cout << "The strings '" + str1 + "' and '" + str2 + "' are permutations of each other" << endl;
	}
	else
	{
		cout << "The strings '" + str1 + "' and '" + str2 + "' are not permutations of each other" << endl;
	}
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.3 problem --------------------
void test_replaceSpaces()
{
	char s[] = "Mr John Smith    ";
	int i = strlen(s) - 1, real_length = 0;

	while (s[i] == ' ')
	{
		i--;
	}
	
	for (; i >= 0; i--)
	{
		real_length++;
	}

	printf("Output of Question 1.3:");
	printf("\nThe real length of '%s' is: %d\n", s, real_length);

	printf("The updated string is: '%s'", replaceSpaces(s, real_length));
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.4 problem --------------------
void test_permutationPalindrome()
{
    string str = "Tact Coa";

	cout << "\nOutput of Question 1.4:" << endl;
	
	if (permutationPalindrome(str))
	{
		cout << "'" + str + "' is a permutation of a palindrome" << endl;
	}
	else
	{
		cout << "'" + str + "' is not a permutation of a palindrome" << endl;
	}
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.5 problem --------------------
void test_checkOneAway()
{	
	printf("Output of Question 1.4:\n");

	const char* optional_strings[5] = {"pale", "pales", "ple", "bale", "bake"}; 
	
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if(checkOneAway(optional_strings[i], optional_strings[j]))
			{
			printf("'%s', '%s' -> true\n", optional_strings[i], optional_strings[j]);
			}
			else
			{
				printf("'%s', '%s' -> false\n", optional_strings[i], optional_strings[j]);
			}
		}
		
	}
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.6 problem --------------------
void test_compression()
{
	cout << "Output of Question 1.6:" << endl;
	
	string str = "aabcccccaaa";
	
	cout << "Original string: '" + str + "'";
	cout << ", Compressd string: '" + compression(str) + "'\n" << endl;
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.7 problem --------------------
void test_rotate()
{
	cout << "Output of Question 1.7:" << endl;

	int size;

	cout << "Enter the size of your 2d array (NxN matrix): ";	// Matrix of NxN 
	cin >> size;

	int** image = nullptr;

	try
	{
		// Dynamically allocate a 2D array:
		image = new int*[size];		// Array of pointers

		for (int i = 0; i < size; i++) 
		{
			image[i] = new int[size];  // Dynamically allocate each row
		}
		
		int i = 1;
		cout << "\n The image values before 90 degrees rotation:" << endl;

		// Initialize the array:
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				image[row][col] = i;
				i++;

				cout << image[row][col] << " ";		// Print the array values before rotation of 90 degrees
			}
			cout << endl;
		}

		rotate(image, size);
		cout << "\n The image values after 90 degrees rotation:" << endl;

		
		// Print the array values after rotation of 90 degrees:
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				cout << image[row][col] << " ";		
			}
			cout << endl;
		}
	}

	catch (const bad_alloc& e)
	{
		cerr << "Memory allocation failed: " << e.what() << endl;
		
		// Clean up memory in case of allocation failure
        if (image) 
		{
            for (int i = 0; i < size; i++)
			{
				delete[] image[i];  // Deallocate each row
			}
			delete[] image;  // Deallocate the array of pointers
		}
		return;
    }


	// Deallocate memory if Memory allocation succeeded:
    for (int i = 0; i < size; i++) 
	{
        delete[] image[i];  // Deallocate each row
    }

    delete[] image;  // Deallocate the array of pointers
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.8 problem --------------------
void test_zeroMat()
{
	cout << "Output of Question 1.8:" << endl;

	int M, N;

	cout << "Enter the size of your 2d array (MxN matrix): ";	// Matrix of MxN 
	cin >> M >> N;

	int** matrix = nullptr;

	try
	{
		// Dynamically allocate a 2D array:
		matrix = new int*[M];		// Array of pointers
	
		for (int i = 0; i < M; i++)
		{
			matrix[i] = new int[N];		// Dynamically allocate each row
		}

		// Initialize the array:
		for (int row = 0; row < M; row++)
		{
			for (int col = 0; col < N; col++)
			{
				matrix[row][col] = rand() % 11;	// get a value from the range 0 to 11-1 (0-10)

				cout << matrix[row][col] << " ";		// Print the array values before rotation of 90 degrees
			}
			cout << endl;
		}

		zeroMat(matrix, M, N);

		cout << "\n The matrix values after Reset:" << endl;

		for (int row = 0; row < M; row++)
		{
			for (int col = 0; col < N; col++)
			{
				cout << matrix[row][col] << " ";	// Print the matrix values after reset:
			}
			cout << endl;
		}
	}

	catch(const bad_alloc& e)
	{
		cerr << "Memory allocation failed: " << e.what() << endl;

		// Clean up memory in case of allocation failure
        if (matrix) 
		{
            for (int i = 0; i < M; i++)
			{
				delete[] matrix[i];  // Deallocate each row
			}
			delete[] matrix;  // Deallocate the array of pointers
		}
		return;
	}
	
	// Deallocate memory if Memory allocation succeeded:
	for (int i = 0; i < M; i++)
	{
		delete[] matrix[i]; // Deallocate each row
	}
	delete[] matrix;	// Deallocate the array of pointers
}
//----------------------------------------------------------------------------------------------------



//-------------------- Test for 1.9 problem --------------------
void test_isRotation()
{
	cout << "Output of Question 1.9:" << endl;
	
	string str1 = "waterbottle", str2 = "erbottlewat";

	if (isRotation(str1, str2))
	{
		cout << str1 << " is rotation of: " << str2 << endl;

	}
	else
	{
		cout << str1 << " is not rotation of: " << str2 << endl;
	}
}
//----------------------------------------------------------------------------------------------------


#endif  // !TESTS_H