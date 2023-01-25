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

#include "ProteinDatabase.h"
#include <utility>

// 'protein sequences' in 'p_seq_arr' are stored from index 1 to counter+1, both inclusive.

sdds::ProteinDatabase::ProteinDatabase() = default;

sdds::ProteinDatabase::ProteinDatabase(string file_name)
{
    ifstream read(file_name); // open file 'file_name'

    char gt_char = '>';
    string line;

    while (getline(read, line)) // read each line of 'read' and store in string 'line'.
    {
        if (line[0] == gt_char) // check if first character is '>'
        {
            ++counter; // used to count number of sequences
        }
    }

    if (p_seq_arr == nullptr) // null pointer safety
    {
        p_seq_arr = new string[counter + 2];
    }

    p_seq_arr[0] = " "; // protein sequences will starting loading from index 1.

    read.clear();            // flags (eof) will be set to default. used because eof was set.
    read.seekg(0, ios::beg); // relative to beginning, offset zero : start from index 0. used because end of file was reached before.

    size_t index = 0;
    while (getline(read, line))
    {
        if (line[0] == gt_char)
        {
            index++; // the first line of proteinsequences.txt contains '>'
        }
        else
        {
            p_seq_arr[index] += line; // append
        }
    }

    read.close(); // not closing the file may cause unexpected behaviour.
}

size_t sdds::ProteinDatabase::size()
{
    return counter; // returns number of sequences.
}

string sdds::ProteinDatabase::operator[](size_t index)
{
    if (index >= counter)
    {
        return "";
    }
    else
    {
        return p_seq_arr[index + 1]; // requested index : x, my index : x+1
    }
}

sdds::ProteinDatabase::ProteinDatabase(const ProteinDatabase &source)
{
    this->counter = source.counter;
    if (p_seq_arr == nullptr) // null pointer safety
    {
        this->p_seq_arr = new string[counter + 2];
    }

    for (size_t i = 0; i < this->counter + 2; ++i)
    {
        this->p_seq_arr[i] = source.p_seq_arr[i]; // filling this->p_seq_arr[i] with source.p_seq_arr[i]
    }
}

// P2********************************************************************************************************************************

// move constructor
sdds::ProteinDatabase::ProteinDatabase(ProteinDatabase &&source)
{
    this->counter = source.counter;

    (this->p_seq_arr) = move((source.p_seq_arr));

    if (source.p_seq_arr != nullptr)
    {
        source.p_seq_arr = nullptr;
    }

    source.counter = 0;
}
// P2********************************************************************************************************************************