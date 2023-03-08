// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 28th Feburary'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
long unsigned int sdds::Station::m_widthField{0};
int sdds::Station::id_generator{0};

sdds::Station::Station(const std::string &str)
{
    ++id_generator;
    m_stationId = id_generator;

    Utilities tempUtilities;
    size_t pos{0u};
    bool more = true;

    m_itemName = tempUtilities.extractToken(str, pos, more);
    m_nextSerialNum = std::stoul(tempUtilities.extractToken(str, pos, more));
    m_nInStock = std::stoul(tempUtilities.extractToken(str, pos, more));
    m_widthField = m_widthField > tempUtilities.getFieldWidth() ? m_widthField : tempUtilities.getFieldWidth();
    m_stationDesc = tempUtilities.extractToken(str, pos, more);
}

const std::string &sdds::Station::getItemName() const { return m_itemName; }

size_t sdds::Station::getNextSerialNumber()
{
    static int i = 0;
    if (i == 0)
    {
        ++i;
        return m_nextSerialNum;
    }
    else
    {
        return ++m_nextSerialNum;
    }
}

size_t sdds::Station::getQuantity() const { return m_nInStock; }

void sdds::Station::updateQuantity() { m_nInStock = m_nInStock == 0 ? m_nInStock : (m_nInStock - 1); }

void sdds::Station::display(std::ostream &os, bool full) const
{
    if (!full)
    {
        os << std::setw(3) << std::setfill('0') << std::right << m_stationId << " | ";
        os << std::setw(15) << std::setfill(' ') << std::left << m_itemName << " | ";
        os << std::setw(6) << std::setfill('0') << std::right << m_nextSerialNum << " | \n";
    }
    else
    {
        os << std::setw(3) << std::setfill('0') << std::right << m_stationId << " | ";
        os << std::setw(15) << std::setfill(' ') << std::left << m_itemName << " | ";
        os << std::setw(6) << std::setfill('0') << std::right << m_nextSerialNum << " | ";
        os << std::setw(4) << std::setfill(' ') << std::right << m_nInStock << " | ";
        os << m_stationDesc << '\n';
    }
}