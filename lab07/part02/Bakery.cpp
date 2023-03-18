// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     18th March'2023
*/
#include "Bakery.h"

sdds::Bakery::Bakery(const std::string &file_name)
{
    std::ifstream file(file_name);
    if (file_name.find(".txt") == std::string::npos) // file_name should have extension .txt
    {
        file.close();
        throw std::invalid_argument("Abort. Invalid Argument!");
        return;
    }
    else if (!file.is_open())
    {
        file.close();
        throw std::runtime_error("Abort. error opening file!");
        return;
    }

    std::string line{};
    while (std::getline(file, line))
    {
        populate(line); // each line populates one BakedGood
        continue;
    };
    file.close();
    return;
}

void sdds::Bakery::populate(std::string &line)
{
    sdds::BakedGood bg;
    std::string type = extract_token(line, 8);
    bg.type = (type == "Bread") ? sdds::BakedType::BREAD : sdds::BakedType::PASTERY;
    bg.desc = extract_token(line, 20);
    bg.shelf_life = std::stoi(extract_token(line, 15));
    bg.n_stock = std::stoi(extract_token(line, 8));
    bg.item_price = std::stod(extract_token(line, 6));
    collection.push_back(std::move(bg));
    return;
}

std::string sdds::Bakery::extract_token(std::string &line, int width)
{
    std::string token = line.substr(0, width);                // extract token with length 'width'
    token = token.substr(0, token.find_last_not_of(' ') + 1); // remove blank spaces at end
    line.erase(0, width);                                     // remove token from line(Referenced) once extracted and stored
    return token;                                             // return token
}

std::ostream &sdds::operator<<(std::ostream &out, const BakedGood &b) // overloading insertion operator
{
    out << "* ";
    if (b.type == BakedType::BREAD)
    {
        out << std::setw(10) << std::left << "Bread";
    }
    else
    {
        out << std::setw(10) << std::left << "Pastry";
    }
    out << " * ";
    out << std::setw(20) << std::left << b.desc;
    out << " * ";
    out << std::setw(5) << std::left << b.shelf_life;
    out << " * ";
    out << std::setw(5) << std::left << b.n_stock;
    out << " * ";
    out << std::setw(8) << std::right << std::fixed << std::setprecision(2) << b.item_price;
    out << " * ";

    return out;
}

void sdds::Bakery::showGoods(std::ostream &os) const // prints BakedGoods
{
    std::ostream_iterator<BakedGood> print(os, "\n");       // 'ostream_iterator' object print will print to output stream 'os' with newline character as delimiter
    std::copy(collection.begin(), collection.end(), print); // print to output stream BakedGood objects from <vector> collection using print iterator

    int total_stock{};
    double total_price{};

    // std::accumulate used to add all n_stock / item_price values of all BakedGood objects in <vector> collection
    total_stock = std::accumulate(collection.begin(), collection.end(), 0, [](double sum_stock, const sdds::BakedGood &bg)
                                  { return (sum_stock + bg.n_stock); });

    total_price = std::accumulate(collection.begin(), collection.end(), 0.0, [](double sum_price, const sdds::BakedGood &bg)
                                  { return (sum_price + bg.item_price); });

    os << "Total Stock: " << total_stock;
    os << "\nTotal Price: " << total_price << '\n';
    return;
}

void sdds::Bakery::sortBakery(const std::string &sortBy) // sort <vector> collection by 'sortBy' which is a member varibale of BakedGood object, using std::sort
{
    if (sortBy == "Description")
    {
        std::sort(collection.begin(), collection.end(), [](const BakedGood &bgA, const BakedGood &bgB)
                  { return bgA.desc < bgB.desc; });
        return;
    }
    else if (sortBy == "Shelf")
    {
        std::sort(collection.begin(), collection.end(), [](const BakedGood &bgA, const BakedGood &bgB)
                  { return bgA.shelf_life < bgB.shelf_life; });
        return;
    }
    else if (sortBy == "Stock")
    {
        std::sort(collection.begin(), collection.end(), [](const BakedGood &bgA, const BakedGood &bgB)
                  { return bgA.n_stock < bgB.n_stock; });
        return;
    }
    std::sort(collection.begin(), collection.end(), [](const BakedGood &bgA, const BakedGood &bgB)
              { return bgA.item_price < bgB.item_price; });
    return;
}

std::vector<sdds::BakedGood> sdds::Bakery::combine(sdds::Bakery &bakeryA) // merge 'this' with param 'bakeryA'
{
    this->sortBakery("Price"); // sort before merging
    bakeryA.sortBakery("Price");

    std::vector<sdds::BakedGood> cmb_this_bakeryA{}; // use back_inserter to push_back
    std::merge(this->collection.begin(), this->collection.end(), bakeryA.collection.begin(), bakeryA.collection.end(), std::back_inserter(cmb_this_bakeryA), [](const sdds::BakedGood &from_this, const sdds::BakedGood &from_bakeryA)
               { return (from_this.item_price < from_bakeryA.item_price); });

    return cmb_this_bakeryA;
}

bool sdds::Bakery::inStock(const std::string &description, const sdds::BakedType &bakedType) const
{ // use find_if to look for a specified condition object and return ierator pointing to it.
    auto it = std::find_if(collection.begin(), collection.end(), [&description, &bakedType](const sdds::BakedGood &bg)
                           { return ((bg.desc == description) && (bg.type == bakedType)); });

    return (it != collection.end());
}

std::list<sdds::BakedGood> sdds::Bakery::outOfStock(const sdds::BakedType &bakedType) const
{
    std::list<sdds::BakedGood> type_coll(collection.begin(), collection.end()); // create a list and copy collection to it.

    // shift all BakedGood objects to end that satisfy given condition, using remove_if and then erase them using std::erase
    type_coll.erase(std::remove_if(type_coll.begin(), type_coll.end(), [bakedType](const sdds::BakedGood &bg)
                                   { return (bg.type != bakedType) || ((bg.type == bakedType) && (bg.n_stock != 0)); }),
                    type_coll.end());
    return type_coll;
}