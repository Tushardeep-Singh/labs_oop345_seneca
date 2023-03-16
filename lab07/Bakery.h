// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     16th March'2023
*/

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include <exception>
#include <iomanip>

namespace sdds
{

    enum class BakedType
    {
        BREAD,
        PASTERY
    };

    struct BakedGood
    {
        BakedType type;
        std::string desc = ""; // description
        std::string shelf_life = "";
        std::string n_stock = "";
        std::string item_price = "";
    };

    class Bakery
    {
    private:
        std::vector<BakedGood> collection;

    public:
        Bakery() = default;
        Bakery(const std::string &file_name);
        std::string extract_token(std::string &line, int width); // extracts each token
        void populate(std::string &line);                        // populates BakedGood
        void showGoods(std::ostream &os) const;                  // prints BakedGoods
    };
    std::ostream &operator<<(std::ostream &out, const BakedGood &b);
};
#endif