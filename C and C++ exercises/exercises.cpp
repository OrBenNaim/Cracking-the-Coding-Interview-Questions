#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int isUnique(char* s);	// (1.1) Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?


int main()
{
	char str[] = "abbbcd";
	if (isUnique(str))
	{
		printf("\n%s has all unique characters\n", str);
	}
	else
	{
		printf("\n%s hasn't all unique characters\n", str);
	}
	return 0;
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