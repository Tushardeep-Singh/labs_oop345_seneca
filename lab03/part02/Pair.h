// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 2nd Febuary'2023
*/

#ifndef PAIR_H
#define PAIR_H
#include <iomanip>
namespace sdds
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string &getKey() { return m_key; }
        const std::string &getValue() { return m_value; }
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};

        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.

        Pair(); // default constructor required to set the member variables to empty string when req. Otherwise, uniform initialisation have been used.

        // overloading << to print the instances of objects stored in array to the stream
        friend std::ostream &operator<<(std::ostream &out, const Pair &pair)
        {
            int colwidth{20};
            out << std::setw(colwidth) << std::right << pair.m_key << ": ";
            out << pair.m_value;

            return out;
        }

        // overloading == to compare the keys.
        friend bool operator==(const Pair &lhs, const Pair &rhs)
        {
            if (lhs.m_key == rhs.m_key)
            {
                return true;
            }

            return false;
        }
    };
}

#endif