#include "Toy.h"

sdds::Toy::Toy() = default;

void sdds::Toy::update(int numItems)
{
    temp_toy_count = numItems;
}

sdds::Toy::Toy(const std::string &toy)
{
    int start = 0;
    char delimiter = ':';
    int end = toy.find(delimiter); // finds the index of the delimiter

    if (toy[0] != '#')
    {
        // order id
        order_id = stoi(toy.substr(start, end)); // the whitespaces will be automatically removed when converted to int.

        // toy name
        start = (end + 1);
        end = toy.find(delimiter, start);
        toy_name = toy.substr(start, end - start);
        int first = toy_name.find_first_not_of(' ');
        int last = toy_name.find_last_not_of(' ');
        toy_name = toy_name.substr(first, last + 1);

        // toy count
        start = (end + 1);
        end = toy.find(delimiter, start);
        temp_toy_count = stoi(toy.substr(start, end - start)); // string to integer

        // price
        start = (end + 1);
        end = toy.find(delimiter, start);
        temp_toy_price = stod(toy.substr(start, end - start)); // string to double
    }
}

