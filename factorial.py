# Computing the factorial of a given input
# Structure of Programming Languages Project
# Written by Colby Reinhart
# 4-23-2021

"""
PROCEDURAL:
Procedural means using simple user-defined functions, or procedures,
to accomplish a task. It is an impetarative paradigm. This program
uses procedural programming to accomplish the task of finding the
factorial of a given input by calling user-defined sub-procedures.
The compute() procedure takes in an integer, finds the factorial,
and returns the result.

GENERATIONAL GARBAGE COLLECTION:
In python, dynamically allocated data is automatically collected
and disposed of using generational garbage collection. In this form
of garbage collection, the heap is organized into multiple different
'generations'. Each generation has an age, which denotes how old the
data structures it holds are. The idea behind this collection method
is centered around the concept that newer objects usually have smaller
lifespans. By separating the data structures into generations, the
overhead of constantly copying older data strucuters when the newer
structures fill the generation is removed.

DYNAMIC TYPING:
Python is a dynamically typed language. This means that a programmer
can assign any kind of value to any variable at any time. While dynamic
typing allows for more freedom and more efficient variable usage,
dynamically typed languages are often harder to debug and decrease
readability.

"""

# This funciton will take in a value, compute the factorial, and return the output
# This program uses the procedural program paradigm by using this function/procedure
# to accomplish the task of finding the factorial of a number
def compute(value):
	result = 1
	while (value > 1):
		result = result * value
		value = value - 1
	return result

# All variables in python are stored on the heap. Generational garbage collection
# automatically deletes all dynamic data structures at the appropriate time and
# ensures that the programmer does not need to manually delete them. In a language
# with no garbage collection like C++, this data structure would need to be deleted
# manually.
factorialList = []
# Take in user input
userInput = input("Please enter values to find factorial of [-1 to stop]\n")
while (userInput != "-1"):
	factorialList.append(userInput)
	userInput = input("")

# Compute factorial of all inputs
for x in factorialList:
	
	# Python uses dynamic typing. This userInput variable was declared without
	# a type and originally held a string value when taking in user input.
	# Now, it's holding an integer value. Dynamically typed languages have no
	# notion of explicit type and allow this sort of assignment.
	userInput = int(x)

	print("Factorial of " + x + " is " + str(compute(userInput)))