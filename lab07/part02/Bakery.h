// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     18th March'2023
*/

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <string>    // std::string
#include <iterator>  // std::ostream_iterator, std::back_inserter
#include <fstream>   // std::ifstream
#include <vector>    // std::vector
#include <stdexcept> // std::invalid_argument, std::runtime_error
#include <iomanip>   // std::setw, std::left, std::right, std::setprecision
#include <numeric>   // std::accumulate
#include <algorithm> // std::sort, std::merge, std::find_if
#include <list>      // std::list, std::erase, std::remove_if

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
        std::string desc{}; // description
        int shelf_life{};
        int n_stock{};
        double item_price{};
    };

    class Bakery
    {
    private:
        std::vector<BakedGood> collection{};

    public:
        Bakery() = default;
        Bakery(const std::string &file_name);
        std::string extract_token(std::string &line, int width);                              // extracts each token
        void populate(std::string &line);                                                     // populates BakedGood
        void showGoods(std::ostream &os) const;                                               // prints BakedGoods
        void sortBakery(const std::string &sortBy);                                           // sort baked goods by sortBy
        std::vector<BakedGood> combine(sdds::Bakery &bakeryA);                                // combines this->collection with bakeryA.collection
        bool inStock(const std::string &description, const sdds::BakedType &bakedType) const; // checks if any BakedGood has description && bakedType
        std::list<BakedGood> outOfStock(const sdds::BakedType &bakedType) const;              // checks for outOfStock bakedType BakedGoods
    };
    std::ostream &operator<<(std::ostream &out, const BakedGood &b);
};

#endif