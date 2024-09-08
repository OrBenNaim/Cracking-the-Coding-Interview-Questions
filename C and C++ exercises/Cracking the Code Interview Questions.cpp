#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// (1.1) Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
int isUnique(char* s);
void test_isUnique();

// (1.2) Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. 
bool CheckPermutation(const string& s1, const string& s2); 
void test_CheckPermutation();


int main()
{
	test_isUnique();	
	test_CheckPermutation();


	return 0;
}


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
	printf("\n");
}


int isUnique(char* s)
{
	int checker = 0, step = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		step = s[i] - 'a';

		if ((checker & (1 << step)) > 0) 
		{
			return 0;
		}
		else
		{
			checker |= (1 << step);
		}
	}
	return 1;
}


void test_CheckPermutation()
{
	string str1 = "abc", str2 = "cba";

	cout << "\nOutput of Question 1.2:" << endl ;

	if (CheckPermutation(str1, str2))
	{
		cout << "The strings '" + str1 + "' and '" + str2 + "' are permutations of each other" << endl;
	}
	else
	{
		cout << "The strings '" + str1 + "' and '" + str2 + "' are not permutations of each other" << endl;
	}

	cout << "\n" << endl ;
}


bool CheckPermutation(const string &s1, const string &s2)
{
    int sum1 = 0, sum2 = 0;

	if (s1.length() != s2.length())
	{
		return false;
	}

	for (int i = 0; i < s1.length(); i++)
	{
		sum1 += s1[i];
		sum2 += s2[i];
	}

	return (sum1 == sum2) ? true : false;
}


