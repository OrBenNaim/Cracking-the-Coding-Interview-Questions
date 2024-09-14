#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <list>

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


/* (1.4) Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE:
Input: 'Tact Coa'
Output: True (permutations: "taco cat", "atco eta", etc.) */
bool permutationPalindrome(const string& s);
void test_permutationPalindrome();


/* (1.5) One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false 
*/
int checkOneAway(const char* s1, const char* s2);
void test_checkOneAway();


/* (1.6) String Compression: Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string,
your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z). 
*/
string compression(string& s);
void test_compression();


int main()
{
	// When you declare a function pointer in C++, you use a syntax like this: void (*funcPtr)();
	// void is what the functions returns in this case, () is the functions parameters which is empty in this case.
	// When you want to create an array of such function pointers, you extend the syntax: void (*funcList[])();

	void (*funcList[])() = {test_isUnique, test_checkPermutation, test_replaceSpaces, test_permutationPalindrome,
		test_checkOneAway, test_compression};

	for (auto& func : funcList) // auto allows the compiler to automatically deduce the type of func based on the type of elements in funcList.
	{
    	func();  // Calls the function pointed to by func
		cout << "\n" << endl;
	}
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


bool permutationPalindrome(const string& s)
{
    int checker = 0, shift = 0;
	
	for (int i = 0; s[i] != '\0'; i++)
	{
		shift = s[i] - 'a';
		
		if ((checker & (1 << shift)) == 0)	// bit i is '0'
		{
			checker |= 1 << shift;	// toggle '0'
		}
		else
		{
			checker &= ~(1 << shift);	// toggle '1'
		}
	}
	
	if (checker == 0) return true;

	int temp = checker - 1;

	if ((checker & temp) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


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


int checkOneAway(const char *s1, const char *s2)
{
    int difference_flag = 0, n1 = strlen(s1), n2 = strlen(s2);

	if (abs(n1 - n2) > 1) return 0;

	const char* smaller_s = (n1 < n2) ? s1:s2;
	const char* larger_s = (n1 < n2) ? s2:s1;

	int i = 0, j = 0;

	while ((smaller_s[i] != '\0') && (larger_s[j] != '\0'))
	{
		if (smaller_s[i] != larger_s[j])
		{
			if (difference_flag) return 0;

			difference_flag = 1;

			if (n1 == n2)
			{
				i++;	// On Replace, increament the smaller_s index too.
			}
		}
		else
		{
			i++;	// On Replace, increament the smaller_s index too.
		}
		j++; // Always increament the larger_s index.
	}
	
	return 1;
}


void test_compression()
{
	cout << "Output of Question 1.6:" << endl;
	
	string str = "aabcccccaaa";
	
	cout << "Original string: '" + str + "'";
	cout << ", Compressd string: '" + compression(str) + "'\n" << endl;
}


string compression(string& s)
{
	if (s[0] == '\0')
	{
		return s;
	}

	bool repeated = false;	// Indicates if there are sequence of repeated characters in s

	list<char> compressed_list;

	int ref_idx = 0, curr_idx = 1;

	for (; s[curr_idx] != '\0'; curr_idx++)
	{
		if (s[ref_idx] == s[curr_idx])	// There is sequence of repeated characters
		{
			repeated = true;
			continue;
		}

		if (repeated) repeated = false;		// The sequence of repeated characters is over

		compressed_list.push_back(s[ref_idx]);		// Copy the reference char to the list
		compressed_list.push_back((curr_idx - ref_idx) + '0');	// write the number of repetitions of the char

		ref_idx = curr_idx;		// If s[ref_idx] != s[curr_idx], update ref_idx
	}

	// Add the last character of s and its number of repetitions:
	compressed_list.push_back(s[ref_idx]);
	compressed_list.push_back((curr_idx - ref_idx) + '0');

	string compressed_str(compressed_list.begin(), compressed_list.end());	// Use constructor to convert list object to string object

	return (s.length() > compressed_str.length()) ? compressed_str : s; // return the shorter string
}