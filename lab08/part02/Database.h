//  > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     26th March'2023
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database
    {
    public:
        static std::shared_ptr<Database> getInstance(const std::string &filename);
        sdds::Err_Status GetValue(const std::string &key, T &value);
        sdds::Err_Status SetValue(const std::string &key, const T &value);
        ~Database();

    private:
        static std::shared_ptr<Database<T>> db;
        Database() = default;
        size_t entry_count{0};    // counts number of key-value pairs
        std::string keys[20];     // stores keys
        T values[20];             // stores values
        std::string dbFileName{}; // stores database file name
        Database(const std::string &filename);
        void encryptDecrypt(T &value){};
    };
}

#endif