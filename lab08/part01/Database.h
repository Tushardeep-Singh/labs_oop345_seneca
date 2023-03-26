#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database
    {
    public:
        static std::shared_ptr<Database> getInstance(const std::string &filename);
        sdds::Err_Status GetValue(const std::string &key, std::string &value);
        sdds::Err_Status SetValue(const std::string &key, const std::string &value);
        ~Database();

    private:
        static std::shared_ptr<Database> db;
        Database() = default;
        size_t entry_count{0};
        std::string keys[20];
        std::string values[20];
        std::string dbFileName{};
        Database(const std::string &filename);
    };
}

#endif