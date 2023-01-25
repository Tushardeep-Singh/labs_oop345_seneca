// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
NOTE TO READERS:
    1. I have tried to keep variable names as descriptive as possible.
    2. I have tried to summarize the code logic in the comments.
    3. P2**... indicates code additions to p1 of lab1.
*/

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 24th January'2023
*/

#ifndef PROTEINDATABASE_H // header guards
#define PROTEINDATABASE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace sdds
{
    class ProteinDatabase
    {
    private:
        size_t counter{0};
        string *p_seq_arr = nullptr;

    public:
        ProteinDatabase(); // default constructor

        ProteinDatabase(string file_name); // 1-argument constructor

        size_t size(); // returns number of protein sequences.

        string operator[](size_t); // a query that returns a copy of the protein sequence at the index received as the function parameter.

        ~ProteinDatabase() // destructor
        {
            if (p_seq_arr != nullptr) // null pointer safety
            {
                delete[] p_seq_arr;
                p_seq_arr = nullptr;
            }
        }

        // copy constructor:
        ProteinDatabase(const ProteinDatabase &source);

        // copy assignment operator:
        ProteinDatabase &operator=(const ProteinDatabase &source)
        {
            this->counter = source.counter;

            if (this != &source) // preventing self assignment
            {
                delete[] this->p_seq_arr;                      // delete
                this->p_seq_arr = nullptr;                     // nullptr
                this->p_seq_arr = new string[counter + 2];     // new
                for (size_t i = 0; i < this->counter + 2; ++i) // filling this->p_seq_arr[i] with source.p_seq_arr[i]
                {
                    this->p_seq_arr[i] = source.p_seq_arr[i];
                }
            }

            return *this;
        }
        // P2********************************************************************************************************************************
        ProteinDatabase(ProteinDatabase &&source); // move constructor

        // move assignment operator
        ProteinDatabase &operator=(ProteinDatabase &&source)
        {
            if (this != &source) // preventing self-assignment
            {
                if (this->p_seq_arr != nullptr)
                {
                    delete[] this->p_seq_arr;
                    this->p_seq_arr = nullptr;
                }
                // I don't have to assign 'p_seq_arr' to a new heap memory because move() will transfer the ownership of 'source.p_seq_arr' to 'p_seq_arr'.

                this->counter = source.counter;

                (this->p_seq_arr) = move((source.p_seq_arr)); 

                // assigning to nullptr prevents destructor from deleting the memory.
                if (source.p_seq_arr != nullptr)
                {
                    source.p_seq_arr = nullptr; // assigning source.p_seq_arr to nullptr and not deleting it because this->p_seq_arr also points to same address.
                }

                source.counter = 0; // setting the counter back to default.
            }

            return *this;
        }
    };
}
// P2********************************************************************************************************************************

#endif