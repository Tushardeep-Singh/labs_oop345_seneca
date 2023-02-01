/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 1st Febuary'2023
*/

// Workshop 3 - Templates
// 2022/01/28 - If this code works, it was created by Cornel
//            - If it doesn't work, I don't know who wrote it. 

#include <iostream>
#include <iomanip>
#include "Collection.h"
#include "Collection.h"
#include "Pair.h"
#include "Pair.h"

int cout = 0; // won't compile if headers don't follow convention

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// Data to be used by the template classes
	long   iData[]{    16,    12,     9,      3,    21,    12, 23 };
	double dData[]{ 1.222, 5.777, 1.223, 51.333, 8.888, 1.221 };
	sdds::Pair pData[]{
		sdds::Pair("static memory", "memory allocated during the compilation time"),
		sdds::Pair("programmer", "a person who writes code"),
		sdds::Pair("dynamic memory", "memory allocated during the runtime"),
		sdds::Pair("client of a class", "a piece of code that uses the class"),
		sdds::Pair("dynamic memory", "memory allocated with 'new' operator"),
		sdds::Pair("user", "a person who runs and interracts with the program"),
		sdds::Pair("array", "a contiguous block of memory storing multiple objects"),
		sdds::Pair("client of a function", "a piece of code that uses the function"),
		sdds::Pair("user", "Just John!"),
	};

	{
		std::cout << "******************************************************\n";
		std::cout << "* Testing the Collection of Integers                 *\n";
		std::cout << "******************************************************\n";
		sdds::Collection<long, 20> colIntegers;

		for (const auto& item : iData)
			colIntegers.add(item);

		std::cout << "Collection size: [" << colIntegers.size() << "]\n";
		colIntegers.display();

		std::cout << "Item [0]: " << colIntegers[0] << "\n";
		std::cout << "Item [5]: " << colIntegers[5] << "\n";
		std::cout << "Item [9]: " << colIntegers[9] << "\n";
		std::cout << "******************************************************\n\n";
	}

	{
		std::cout << "******************************************************\n";
		std::cout << "* Testing the Collection of Floats                   *\n";
		std::cout << "******************************************************\n";
		sdds::Collection<double, 30> colFloats;

		for (const auto& item : dData)
			colFloats.add(item);

		std::cout << "Collection size: [" << colFloats.size() << "]\n";
		colFloats.display();

		std::cout << "Item [0]: " << colFloats[0] << "\n";
		std::cout << "Item [5]: " << colFloats[5] << "\n";
		std::cout << "Item [9]: " << colFloats[9] << "\n";
		std::cout << "******************************************************\n\n";
	}

	{
		std::cout << "******************************************************\n";
		std::cout << "* Testing the Collection of Pairs                    *\n";
		std::cout << "******************************************************\n";
		sdds::Collection<sdds::Pair, 50> colDictionary;

		for (const auto& item : pData)
			colDictionary.add(item);

		std::cout << "Collection size: [" << colDictionary.size() << "]\n";
		colDictionary.display();

		std::cout << "Item [0]: [" << colDictionary[0].getKey()   << "]["
		                           << colDictionary[0].getValue() << "]\n";
		std::cout << "Item [8]: [" << colDictionary[8].getKey()   << "]["
		                           << colDictionary[8].getValue() << "]\n";
		std::cout << "Item [9]: [" << colDictionary[9].getKey()   << "]["
		                           << colDictionary[9].getValue() << "]\n";
		std::cout << "******************************************************\n\n";
	}

	return cout;
}
