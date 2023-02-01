// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 1st Febuary'2023
*/

#ifndef COLLECTION_H
#define COLLECTION_H

#include "Pair.h"

namespace sdds
{
    template <typename T, int CAPACITY>
    class Collection
    {
    private:
        int _n_capacity = 0; // number of elements in COLLECTION
        T _dummy_obj{};

    public:
        T _collection_arr[CAPACITY]; 

        int size()
        {
            return _n_capacity;
        }

        const void display()
        {
            std::cout << "----------------------\n";
            std::cout << "| Collection Content |\n";
            std::cout << "----------------------\n";

            for (int i = 0; i < _n_capacity; ++i)
            {
                std::cout << _collection_arr[i] << "\n"; // '<<' overloaded for Pair object instances stored in _collection_arr
            }

            std::cout << "----------------------\n";
        }

        bool add(const T &item)
        {
            if (_n_capacity >= CAPACITY)
            {
                return false;
            }
            static int i = 0; // for index of array

            _collection_arr[i] = item;

            ++_n_capacity;
            ++i;

            return true;
        }

        T operator[](int index)
        {
            if (index >= _n_capacity)
            {
                return _dummy_obj;
            }
            else
            {
                return _collection_arr[index];
            }
        }
    };
    template <> // specialising _dummy_obj
    class Collection<Pair, 100>
    {
        Pair _dummy_obj{"No Key", "No Value"};
    };
}

#endif