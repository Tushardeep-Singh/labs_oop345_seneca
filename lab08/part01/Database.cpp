#include "Database.h"

std::shared_ptr<sdds::Database> sdds::Database::db = nullptr;

std::shared_ptr<sdds::Database> sdds::Database::getInstance(const std::string &filename)
{
    if (!db)
    {
        db = std::shared_ptr<sdds::Database>(new Database(filename));
    }
    return db;
}

sdds::Database::Database(const std::string &filename)
{
    sdds::Database::dbFileName = filename;
    std::cout << '[' << this << "] Database(const std::string&)\n";
    std::ifstream dbFileData(filename);

    std::string temp;
    while (std::getline(dbFileData, temp))
    {
        keys[entry_count] = temp.substr(0, temp.find_first_of('_')) + " " + temp.substr(temp.find_first_of('_') + 1, temp.find_first_of(' ') - temp.find_first_of('_') - 1);
        values[entry_count++] = temp.erase(0, temp.find_first_of('$'));
        continue;
    }
    dbFileData.close();
    return;
}

sdds::Err_Status sdds::Database::GetValue(const std::string &key, std::string &value)
{
    for (size_t i = 0; i < entry_count; ++i)
    {
        if (keys[i] == key)
        {
            value = values[i];
            return sdds::Err_Status::Err_Success;
        }
    }
    return sdds::Err_Status::Err_NotFound;
}

sdds::Err_Status sdds::Database::SetValue(const std::string &key, const std::string &value)
{
    if (entry_count < 20)
    {
        keys[entry_count] = key;
        values[entry_count++] = value;
        return sdds::Err_Status::Err_Success;
    }
    return sdds::Err_Status::Err_OutOfMemory;
}

sdds::Database::~Database()
{
    std::cout << '[' << this << "] ~Database()\n";
    std::string bkpFile = dbFileName + ".bkp.txt";
    std::ofstream backup(bkpFile);
    if (backup.is_open())
    {
        size_t idx = 0;
        while (idx < entry_count)
        {
            backup << std::setw(25) << std::left << keys[idx] << " -> ";
            backup << values[idx++] << '\n';
        }
    }
    backup.close();
}