// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 2nd Febuary'2023
*/

#ifndef COLLECTION_H
#define COLLECTION_H

#include "Pair.h"

namespace sdds
{
    // template parameters : T,CAPACITY
    template <typename T, int CAPACITY>
    class Collection
    {
    private:
        T _dummy_obj{}; // members will be empty strings.
    public:
        int _n_capacity = 0; // number of elements in COLLECTION / array _collection_arr
        T _collection_arr[CAPACITY];
        int capacity_cpy = CAPACITY;

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

        // virtual will pick the add() from the class type that the pointer is pointing to, when dynamic memory is allocated provided there is not any more specialised class that meets thee requirement, then that will be selected.
        virtual bool add(const T &item)
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

        // virtual will help to destroy the object created of derived class type.
        virtual ~Collection() {} // empty destructor of type virtual
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

    template <> // specialising collection class
    class Collection<sdds::Pair, 100>
    {
    private:
        Pair _dummy_obj{"No Key", "No Value"}; // uniform intialisation
    public:
        int _n_capacity = 0; // count of elements in successfully stored in _collection_arr
        Pair _collection_arr[100];
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

        // since this is specialised class with <sdds::Pair, 100>, so below 'add' will be called instead of 'add' in Set class, when : for (const auto& item : pData) {setDictionary->add(item);}
        bool add(const Pair &item)
        {
            if (_n_capacity >= 100)
            {
                return false;
            }
            static int i = 0; // for index of array

            _collection_arr[i] = item;
            for (int x = 0; x < i; ++x)
            {
                if (x != i && (_collection_arr[i].getKey() == _collection_arr[x].getKey()))
                {
                    return false;
                }
            }
            ++_n_capacity;
            ++i;
            return true;
        }

        Pair operator[](int index)
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
}

#endif
