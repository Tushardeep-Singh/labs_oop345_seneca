// w7_p1.cpp

#include <iostream>
#include <iomanip>
#include "Bakery.h"
#include "Bakery.h"

using namespace sdds;

void printstars(std::ostream& os, size_t cnt) {
  for (auto i = 0u; i < cnt; ++i)
    os << "*";
  os << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";
  
  sdds::Bakery bakery(argv[1]);
  std::cout << std::left << std::setw(15) << "Type" << std::setw(23) << "Description"
     << std::setw(8) << "Shelf" << std::setw(8) << "Stock"
     << std::right << std::setw(8) << "Price" << std::endl;
  printstars(std::cout, 64);
  bakery.showGoods(std::cout);
  printstars(std::cout, 64);
}
