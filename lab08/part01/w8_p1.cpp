//w8_p1.cpp - main function for the data base

#include <iostream>
#include <string>
#include <algorithm>
#include "Database.h"

int cout = 0;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: w8 data.txt\n";
		return -1;
	}

	{
		// TEST #1: Singleton

		// getInstance() creates an object of type Database
		//   if that object does not already exist.
		// If that object already exists, getInstance will
		//   return that object.
		// The parameter is useful only in the first call,
		//   after that it should have no impact.

		auto db1 = sdds::Database::getInstance(argv[1]);
		auto db2 = sdds::Database::getInstance("nothing");

		if (db1 == db2)
			std::cout << "Same database.\n\n";
		else
			std::cout << "Different database.\n\n";
	}

	{
		// TEST #2: test content of database

		std::string keys[]{ "Naomi Osaka", "Ashleigh Barty", "Karolina Pliskova", "Barbora Krejcikova", "Leylah Fernandez" };
		std::sort(keys, keys + sizeof(keys) / sizeof(keys[0]));

		for (auto& key : keys)
		{
			auto dB = sdds::Database::getInstance(key); // the parameter should be ignored
			std::string value;
			if (dB->GetValue(key, value) == sdds::Err_Status::Err_Success)
				std::cout << key << " earned " << value << std::endl;
			else
				std::cout << "Unable to retrieve earnings for " << key << std::endl;
		}
	}

	return cout;
}
