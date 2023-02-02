// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 2nd Febuary'2023
*/

#ifndef SET_H
#define SET_H

#include "Collection.h"
#include <cmath>

namespace sdds
{
    template <typename T>
    class Set : public Collection<T, 100>
    {
    public:
        Set() = default;

        bool add(const T &item)
        {
            // _n_capacity assigned default value of collection class
            if (this->_n_capacity >= 100)
            {
                return false;
            }
            static int i = 0; // for index of array
            for (int x = 0; x < i; ++x)
            {
                if (this->_collection_arr[x] == item)
                {
                    return false;
                }
            }
            this->_collection_arr[i] = item;
            ++this->_n_capacity;
            ++i;
            return true;
        }

        ~Set(){};
    };

    template <>
    class Set<double> : public Collection<double, 100>
    {
    public:
        bool add(const double &item)
        {
            if (this->_n_capacity >= this->capacity_cpy)
            {
                return false;
            }
            static int i = 0; // for index of array

            for (int i = 0; i < this->_n_capacity; ++i)
            {
                if (std::fabs(this->_collection_arr[i] - item) <= 0.01)
                {
                    return false;
                }
            }
            this->_collection_arr[i] = item;

            ++this->_n_capacity;
            ++i;
            return true;
        }
    };
}

#endif