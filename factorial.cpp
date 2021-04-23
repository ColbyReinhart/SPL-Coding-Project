// Computing the factorial of a given input
// Structure of Programming Languages Project
// Written by Colby Reinhart
// 4-23-2021

#include <iostream>
#include <list>

/*
OBJECT-ORIENTED:
Object-oriented means using objects and message passing to achieve a goal.
This factorial program using object-oriented programming by implementing a
Factorial class. The class computes a factorial and remembers to result,
such that it does not recompute the result if compute() is called on the
same value.

MANUAL GARBAGE COLLECTION:
Dynamic data and data structures in C++ are always manually allocated and
deleted. Any dynamic memory that is not explicitly deleted by the programmer
after the data leaves its scope is leaked.
*/

// Factorial class used to compute factorials: object-oriented
class Factorial
{
public:
	// Constructor
	Factorial(): value_(0), isComputed_(false) {}
	// Sets the value to be computed
	void setValue(int value)
	{
		if (value_ != value)
		{
			isComputed_ = false;
			value_ = value;
		}
	}
	// Computes the result of the given value
	int compute()
	{
		// If we already know the answer, don't waste time computing
		if (isComputed_)
		{
			std::cout << "the same as last time, ";
			return result_;
		}

		int number = value_;
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
	int value_; // the value to be computed
	int result_; // the remembered result of the last computation
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
	int input;
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