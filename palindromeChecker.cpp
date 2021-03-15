// Palindrome Checker - C++
// Structure of Programming Languages - Coding Project
// Written by Colby Reinhart
// 3-15-2021

#include <iostream>
#include <string>

int main()
{

	// Take input from user
	std::cout << "Enter word to check: ";
	std::string userInput;
	std::cin >> userInput;

	// Check if palindrome
	bool isPalindrome = true;
	int start = 0, end = userInput.size() - 1;

	while (start < end)
	{
		if (userInput[start] != userInput[end])
		{
			isPalindrome = false;
			break;
		}
		++start; --end;
	}

	std::cout << userInput << " is " << (!isPalindrome ? "not " : "") << "a palindrome." << std::endl;

}
