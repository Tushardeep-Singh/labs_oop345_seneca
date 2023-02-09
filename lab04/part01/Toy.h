// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 9th Febuary'2023
*/
#ifndef TOY_H
#define TOY_H

#include <string>
#include <iostream>
#include <iomanip>

namespace sdds
{
    class Toy
    {
    private:
        int order_id{};
        std::string toy_name{};
        int temp_toy_count{};
        double temp_toy_price{};

    public:
        Toy();
        void update(int numItems);
        Toy(const std::string &toy);
        friend std::ostream &operator<<(std::ostream &print, Toy &toy) // overloading '<<'
        {
            double subtotal = (toy.temp_toy_price * toy.temp_toy_count);
            double sales_tax = (13 * subtotal) / 100;
            double total = (subtotal + sales_tax);
            print << "Toy";
            print << std::setw(8) << toy.order_id << ":";
            print << std::setw(18) << std::right << toy.toy_name;
            print << std::setw(3) << std::right << toy.temp_toy_count;
            print << " items";
            print << std::setw(8) << std::right << toy.temp_toy_price;
            print << "/item  subtotal:";
            print << std::setw(7) << std::right << subtotal;
            print << " tax:";
            print << std::setw(6) << std::right << std::fixed << std::setprecision(2) << sales_tax;
            print << " total:";
            print << std::setw(7) << std::right << std::fixed << std::setprecision(2) << total << '\n';

            return print;
        }
    };
}

#endif