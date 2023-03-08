// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 28th Feburary'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H

#include <iomanip>
#include "Utilities.h"

namespace sdds
{
    class Station
    {
    public:
        Station(const std::string &str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;

    private:
        int m_stationId{};
        std::string m_itemName{};
        std::string m_stationDesc{};
        size_t m_nextSerialNum{};
        size_t m_nInStock{};

        static long unsigned int m_widthField;
        static int id_generator;
    };
}

#endif