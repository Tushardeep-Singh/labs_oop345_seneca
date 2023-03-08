// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 28th Feburary'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
char sdds::Utilities::m_delimiter{};

void sdds::Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

size_t sdds::Utilities::getFieldWidth() const { return m_widthField; }

std::string sdds::Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
{
    if (m_delimiter == str[next_pos])
    {
        more = false;
        throw "Invalid position.";
    }
    else
    {
        // extracting tokens using string library functions
        long unsigned int end = str.find_first_of(m_delimiter, next_pos);
        // std::string::npos is returned when delimiter is not found
        more = (end != std::string::npos) ? true : false;
        static std::string m_temp{};
        m_temp = (more == false) ? str.substr(next_pos) : str.substr(next_pos, end - next_pos);
        while (m_temp.back() == ' ')
        {
            m_temp.pop_back();
        }
        m_widthField = m_widthField > m_temp.length() ? m_widthField : m_temp.length();
        next_pos = str.find_first_not_of(' ', end + 1);

        return m_temp;
    }
}

void sdds::Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

char sdds::Utilities::getDelimiter() { return m_delimiter; }