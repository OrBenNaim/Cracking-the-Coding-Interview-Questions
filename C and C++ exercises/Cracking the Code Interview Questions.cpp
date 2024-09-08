#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

// (1.1) Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
int isUnique(char* s);
void test_isUnique();

// (1.2) Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. 
bool checkPermutation(const string& s1, const string& s2); 
void test_checkPermutation();

/* (1.3) URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. For example:
Input: "Mr John Smith    ", 13
Output: "Mr%20John%20Smith" 	*/
char* replaceSpaces(char* str, int length);
void test_replaceSpaces();

// (1.4) 


int main()
{
	test_isUnique();	
	test_checkPermutation();
	test_replaceSpaces();

	cout << "\n" << endl;

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
	cout << "\n" << endl;
}


bool checkPermutation(const string &s1, const string &s2)
{
    int sum1 = 0, sum2 = 0;

	if (s1.length() != s2.length())
	{
		return false;
	}

	for (int i = 0; i < s1.length(); i++)
	{
		sum1 += s1[i];	// In C++, char values are automatically promoted to int when used in expressions where an integer is expected.
		sum2 += s2[i];
	}

	return (sum1 == sum2) ? true : false;
}


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


char* replaceSpaces(char *str, int length)
{
    int cnt = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ') cnt++;
	}

	if (cnt == 0) return str;
	
	int i = length - 1;

	while (cnt > 0)
	{
		if (str[i] != ' ')
		{
			str[i + 2*cnt] = str[i];
		}
		else
		{
			cnt--;
			str[i + 2*cnt] = '%';
			str[(i+1) + 2*cnt] = '2';
			str[(i+2) + 2*cnt] = '0';
		}
		i--;
	}

	return str;
}


