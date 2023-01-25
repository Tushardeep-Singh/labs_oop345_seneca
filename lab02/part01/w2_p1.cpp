// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
NOTE TO READERS:
    1. I have tried to keep variable names as descriptive as possible.
    2. I have tried to summarize the code logic in the comments.
*/

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 24th January'2023
*/

// Workshop 2 - Copy and Move Semantics
// w2_p1.cpp
// 2021/11/28 - Mufleh Al-Shatnawi

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "ProteinDatabase.h"
#include "ProteinDatabase.h" // intentional
#include "TimedTask.h"
#include "TimedTask.h" // intentional

using namespace sdds;

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
		std::cerr << "ERROR: Missing file name!\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "ERROR: Too many arguments!\n";
		return 2;
	}

	sdds::TimedTask t;
	{
		t.startClock();
		sdds::ProteinDatabase protein_DBA;
		t.stopClock();
		t.addTask("  0-arg Constructor");
		std::cout << "  0-arg Constructor - a.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << protein_DBA[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";


		t.startClock();
		ProteinDatabase protein_DBB(argv[1]);
		t.stopClock();
		t.addTask("  1-arg Constructor");
		std::cout << "  1-arg Constructor - b.size = "
			<< std::setw(7) << protein_DBB.size() << " strings -> ";
		std::cout << std::setw(20) << "(b) String     1: [" << protein_DBB[  0].substr(0,20) << "]\n";
		std::cout << std::setw(70) << "(b) String   100: [" << protein_DBB[ 99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  1000: [" << protein_DBB[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  last: [" << protein_DBB[protein_DBB.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String last+: [" << protein_DBB[protein_DBB.size()] << "]\n\n";


		t.startClock();
		ProteinDatabase protein_DBC{ protein_DBB };
		t.stopClock();
		t.addTask("  Copy Constructor");
		std::cout << "  Copy Constructor  - c.size = "
			<< std::setw(7) << protein_DBC.size() << " strings -> ";
		std::cout << std::setw(20) << "(c) String     1: [" << protein_DBC[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String   100: [" << protein_DBC[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  1000: [" << protein_DBC[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  last: [" << protein_DBC[protein_DBC.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String last+: [" << protein_DBC[protein_DBC.size()] << "]\n\n";


		t.startClock();
		protein_DBA = protein_DBB;
		t.stopClock();
		t.addTask("  Copy Assignment");
		std::cout << "  Copy Assignment   - a.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << protein_DBA[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";


		t.startClock();
	}
	t.stopClock();
	t.addTask("  Destructor");

	std::cout << t;
}