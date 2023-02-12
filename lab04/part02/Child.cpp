// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 11th Febuary'2023
*/
#include "Child.h"

// constructor
sdds::Child::Child(std::string name, int age, const Toy *toys[], size_t count)
{
    this->name = name;
    this->age = age;
    this->count = count;

    toy_array = new sdds::Toy *[count]; // allocate heap memory
    for (size_t i = 0; i < count; ++i)  // all pointers nullptr
    {
        toy_array[i] = nullptr;
    }

    for (size_t i = 0; i < count; ++i)
    {
        toy_array[i] = new sdds::Toy(*toys[i]); // create new mem for each pointer at i and then in it copy the contents of *toys[i]
        ++toy_counter;
    }
}

// copy constructor:
sdds::Child::Child(const Child &child)
{
    this->name = child.name;
    this->age = child.age;
    this->count = child.count;
    this->toy_counter = child.toy_counter;
    this->~Child();
    this->toy_array = new sdds::Toy *[this->count]; // allocating heap memory
    for (int i = 0; i < this->count; ++i)
    {
        toy_array[i] = nullptr;
    }

    for (int i = 0; i < this->count; ++i)
    {
        this->toy_array[i] = new sdds::Toy(*child.toy_array[i]); // allocating new heap memory for each pointer to object
    }
}

// move constructor
sdds::Child::Child(Child &&child)
{
    this->name = "";
    this->age = 0;
    this->count = 0;
    this->toy_counter = 0;

    this->name = child.name;
    this->age = child.age;
    this->count = child.count;
    this->toy_counter = child.toy_counter;

    this->~Child();
    this->toy_array = child.toy_array;
    child.toy_array = nullptr;

    child.name = "";
    child.age = 0;
    child.count = 0;
    child.toy_counter = 0;
}

sdds::Child::~Child()
{
    if (toy_array != nullptr)
    {
        for (int i = 0; i < count; ++i)
        {
            delete toy_array[i];
            toy_array[i] = nullptr;
        }
        delete[] toy_array;
        toy_array = nullptr;
    }
}