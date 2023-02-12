// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 11th Febuary'2023
*/
#ifndef CHILD_H
#define CHILD_H
#include "Toy.h"

namespace sdds
{
    class Child
    {
    public:
        // constructor
        Child(std::string name, int age, const Toy *toys[], size_t count);

        // overload '<<'
        friend std::ostream &operator<<(std::ostream &output, const Child &child)
        {
            static int CALL_CNT = 1;
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            output << "Child " << CALL_CNT << ": " << child.name << " " << child.age << " years old:\n";
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            if (child.count == 0)
            {
                std::cout << "This child has no toys!" << '\n';
            }
            for (int i = 0; i < child.count; ++i)
            {
                std::cout << *child.toy_array[i]; // calling overloaded operator '<<' of Toy object
            }
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            ++CALL_CNT;
            return output;
        }

        size_t size() const
        {
            return toy_counter;
        }

        // copy constructor:
        Child(const Child &child);

        // copy assignment operator
        Child &operator=(const Child &child)
        {
            if (this != &child)
            {
                this->~Child(); // free up this
                this->name = child.name;
                this->age = child.age;
                this->count = child.count;
                this->toy_counter = child.toy_counter;

                this->toy_array = new sdds::Toy *[this->count];

                for (int i = 0; i < this->count; ++i)
                {
                    this->toy_array[i] = new sdds::Toy(*child.toy_array[i]); // allocating new heap memory for each pointer to object
                }
            }
            return *this;
        }

        // move constructor
        Child(Child &&child);

        // move assignment operator
        Child &operator=(Child &&child)
        {
            if (this != &child) // self assign check
            {
                this->name = child.name;
                this->age = child.age;
                this->count = child.count;
                this->toy_counter = child.toy_counter;

                // free existing memory
                if (this->toy_array != nullptr)
                {
                    for (int i = 0; i < this->count; ++i)
                    {
                        this->toy_array[i] = nullptr;
                    }
                    delete[] this->toy_array;
                    this->toy_array = nullptr;
                }

                this->toy_array = child.toy_array;
                child.toy_array = nullptr;

                child.name = "";
                child.age = 0;
                child.count = 0;
                child.toy_counter = 0;
            }
            return *this;
        }

        // destructor
        ~Child();

        Child() = default;

    private:
        sdds::Toy **toy_array = nullptr;
        std::string name{};
        int age{};
        int count{};
        int toy_counter = 0;
    };
}

#endif