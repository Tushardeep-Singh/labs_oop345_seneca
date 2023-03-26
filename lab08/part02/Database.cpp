//  > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     26th March'2023
*/
#include "Database.h"

template <typename T>
std::shared_ptr<sdds::Database<T>> sdds::Database<T>::db = nullptr; // static variable initialization

// template specialization for getInstance() function
template <typename T>
std::shared_ptr<sdds::Database<T>> sdds::Database<T>::getInstance(const std::string &filename)
{
    if (!db) // if shared_ptr is null
    {
        db = std::shared_ptr<sdds::Database<T>>(new Database(filename)); // create new instance of Database<T> and store it in shared_ptr
    }
    return db; // return shared_ptr
}

template <>
std::shared_ptr<sdds::Database<std::string>> sdds::Database<std::string>::getInstance(const std::string &filename)
{
    if (!db)
    {
        db = std::shared_ptr<sdds::Database<std::string>>(new Database(filename));
    }
    return db;
}

template <>
std::shared_ptr<sdds::Database<long long>> sdds::Database<long long>::getInstance(const std::string &filename)
{
    if (!db)
    {
        db = std::shared_ptr<sdds::Database<long long>>(new Database(filename));
    }
    return db;
}

template <typename T>
sdds::Database<T>::Database(const std::string &filename) // Database constructor
{
    sdds::Database<T>::dbFileName = filename;
    std::cout << '[' << this << "] Database(const std::string&)\n";
    std::ifstream dbFileData(filename); // open file

    std::string temp;
    T tempValues;
    while (std::getline(dbFileData, temp)) // read from file and store each line in temp
    {
        keys[entry_count] = temp.substr(0, temp.find_first_of('_')) + " " + temp.substr(temp.find_first_of('_') + 1, temp.find_first_of(' ') - temp.find_first_of('_') - 1); // get first token, then remove '_' and add ' '

        if constexpr (std::is_same_v<T, std::string>) // if Type T is same as std::string
        {
            tempValues = temp.substr(temp.find_last_of(' ') + 1); // get encrypted value
            encryptDecrypt(tempValues);                           // decrypt value
        }
        else
        {
            tempValues = std::stoll(temp.substr(temp.find_last_of(' ') + 1));
            encryptDecrypt(tempValues);
        }
        values[entry_count++] = tempValues; // add decrypted value to values[] and increment entry_count
        continue;
    }
    dbFileData.close(); // close file
    return;
}

// template specializations for GetValue() function
template <typename T>
sdds::Err_Status sdds::Database<T>::GetValue(const std::string &key, T &value)
{
    auto it = std::find(keys, keys + sizeof(keys) / sizeof(keys[0]), key); // find for 'key' in container keys
    if (it != keys + sizeof(keys) / sizeof(keys[0]))
    {
        value = values[it - keys]; // add corresponding value to referenced value param
        return sdds::Err_Status::Err_Success;
    }

    return sdds::Err_Status::Err_NotFound; // if not found, return Err_NotFound
}

template <>
sdds::Err_Status sdds::Database<long long>::GetValue(const std::string &key, long long &value)
{
    auto it = std::find(keys, keys + sizeof(keys) / sizeof(keys[0]), key);
    if (it != keys + sizeof(keys) / sizeof(keys[0]))
    {
        value = values[it - keys];
        return sdds::Err_Status::Err_Success;
    }

    return sdds::Err_Status::Err_NotFound;
}

template <>
sdds::Err_Status sdds::Database<std::string>::GetValue(const std::string &key, std::string &value)
{
    auto it = std::find(keys, keys + sizeof(keys) / sizeof(keys[0]), key);
    if (it != keys + sizeof(keys) / sizeof(keys[0]))
    {
        value = values[it - keys];
        return sdds::Err_Status::Err_Success;
    }

    return sdds::Err_Status::Err_NotFound;
}

// template specialisations for SetValue()
template <typename T>
sdds::Err_Status sdds::Database<T>::SetValue(const std::string &key, const T &value)
{
    if (entry_count < 20) // do-something only if space available
    {                     // add key-value pair
        keys[entry_count] = key;
        values[entry_count++] = value;
        return sdds::Err_Status::Err_Success;
    }
    return sdds::Err_Status::Err_OutOfMemory;
}

template <>
sdds::Err_Status sdds::Database<long long>::SetValue(const std::string &key, const long long &value)
{
    if (entry_count < 20)
    {
        keys[entry_count] = key;
        values[entry_count++] = value;
        return sdds::Err_Status::Err_Success;
    }
    return sdds::Err_Status::Err_OutOfMemory;
}
template <>
sdds::Err_Status sdds::Database<std::string>::SetValue(const std::string &key, const std::string &value)
{
    if (entry_count < 20)
    {
        keys[entry_count] = key;
        values[entry_count++] = value;
        return sdds::Err_Status::Err_Success;
    }
    return sdds::Err_Status::Err_OutOfMemory;
}

template <typename T>
sdds::Database<T>::~Database()
{
    std::cout << '[' << this << "] ~Database()\n";
    std::string bkpFile = dbFileName + ".bkp.txt"; // create back up file name
    std::ofstream backup(bkpFile);
    if (backup.is_open())
    {
        size_t idx = 0;
        T tempValues;
        while (idx < entry_count) // write into bkpFile
        {
            backup << std::setw(25) << std::left << keys[idx] << " -> ";
            tempValues = values[idx++];
            encryptDecrypt(tempValues); // encrypt before writing
            backup << tempValues << '\n';
        }
    }
    backup.close(); // close file
}

template <>
void sdds::Database<std::string>::encryptDecrypt(std::string &value)
{
    const char secret[]{"secret encryption key"};
    for (size_t i = 0; i < value.length(); ++i)
    {
        for (size_t j = 0; j < (sizeof(secret) / sizeof(secret[0])); ++j)
        {
            value[i] ^= secret[j % (sizeof(secret) / sizeof(secret[0]))]; // XOR every character of value with every character of secret
        }
    }
    return;
}

template <>
void sdds::Database<long long>::encryptDecrypt(long long &value)
{
    const char secret[]{"super secret encryption key"};
    size_t size = sizeof(long long);
    char *bytes = reinterpret_cast<char *>(&value); // create an array of char type containing value bytes
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < (sizeof(secret) / sizeof(secret[0])); ++j)
        {
            bytes[i] ^= secret[j % (sizeof(secret) / sizeof(secret[0]))]; // XOR every byte of value with every character in secret
        }
    }
    return;
}