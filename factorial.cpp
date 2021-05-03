// Computing the factorial of a given input
// Structure of Programming Languages Project
// Written by Colby Reinhart
// 4-23-2021

#include <iostream>
#include <list>

/*
OBJECT-ORIENTED:
Object-oriented means using objects and message passing to achieve a goal.
Object-oriented programming is a type of imperative programming paradigm.
This factorial program using object-oriented programming by implementing a
Factorial class. The class computes a factorial and remembers the result,
such that it does not recompute the result if compute() is called on the
same value.

MANUAL GARBAGE COLLECTION:
Dynamic data and data structures in C++ are always manually allocated and
deleted. Any dynamic memory that is not explicitly deleted by the programmer
after the data leaves its scope is leaked.

STATIC TYPING
C++ is statically typed, meaning that every named datum requires an explicit
type at declaration. This somewhat restricts the programmer in some ways but
overall allows for better error detection and understandability of code.
*/

// This is the factorial class used to compute factorials. Object-oriented
// programming uses classes with data and its related methods to achieve
// a certain task. The data in the factorial class is the value to be computed,
// the result of the computation, and whether or not the current value has been
// computed already. The methods set the value to be computed and compute
// the factorial
class Factorial
{
public:
	// Constructor
	Factorial(): value_(0), result_(0), isComputed_(false) {}
	// Sets the value to be computed
	void setValue(long value)
	{
		if (value_ != value)
		{
			isComputed_ = false;
			value_ = value;
		}
	}
	// Computes the result of the given value
	long compute()
	{
		// If we already know the answer, don't waste time computing
		if (isComputed_)
			return result_;

		long number = value_;
		result_ = 1;
		while (number > 1)
		{
			result_ *= number;
			--number;
		}

		isComputed_ = true;
		return result_;
	}

private:
	// member variables of the class
	long value_; // the value to be computed
	long result_; // the remembered result of the last computation
	bool isComputed_; // has the current value been computed yet?
};

int main()
{
	// C++ list implements dynamic linked nodes which are stored on the heap.
	// This container implements a destructor, which is called when the object
	// leaves scope and codes how each linked node should be deleted using the
	// delete keyword
	std::list<int> factorialList;

	std::cout << "Please enter values to find factorial of [-1 to stop]" << std::endl;

	// All variables in C++ are statically typed. Some types, such as integer and double,
	// can be casted to be assigned to this variable, but one cannot assign, for example,
	// a string, character, or user defined type to this variable
	// long input = "Hello world!" would cause an error
	// std::string input = "Hello world!" successfully stores the string literal as type string.
	// This variable must be declared with a given type or an error will be thrown. It is
	// impossible to cast this variable to a different type, but its r-value data may be
	// casted and assigned to another variable of the casted type
	long input;

	std::cin >> input;
	while (input != -1)
	{
		factorialList.push_back(input);
		std::cin >> input;
	}

	Factorial f; // Object of the factorial class, used to compute factorial
	for (auto e: factorialList)
	{
		std::cout << "Factorial of " << e << " is ";
		f.setValue(e);
		std::cout << f.compute() << std::endl;
	}
}