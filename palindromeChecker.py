# Palindrome Checker - Python
# Structure of Programming Languages - Coding Project
# Written by Colby Reinhart
# 3-15-2021

# Take input from user
userInput = input("Enter word to check: ")

# Check if palindrome
start = 0
end = len(userInput) - 1
isPalindrome = True

while start < end:
	if userInput[start] != userInput[end]:
		isPalindrome = False
		break
	start += 1
	end -= 1

print(userInput + " is " + ("not " if (not isPalindrome) else "") + "a palindrome.")