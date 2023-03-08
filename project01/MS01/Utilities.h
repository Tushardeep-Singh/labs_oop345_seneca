// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 28th Feburary'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace sdds
{
    class Utilities
    {
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string &str, size_t &next_pos, bool &more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

    private:
        long unsigned int m_widthField{1};
        static char m_delimiter;
    };
}

#endif