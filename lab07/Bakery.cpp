// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
             Name :     Tushardeep Singh
    Seneca e-mail :     tsingh245@myseneca.ca
      Student I'd :     160427217
Date of completion:     16th March'2023
*/
#include "Bakery.h"

sdds::Bakery::Bakery(const std::string &file_name)
{
    std::ifstream file(file_name);
    if (file_name.find(".txt") == std::string::npos)
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

    std::string line = "";
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
    bg.shelf_life = extract_token(line, 15);
    bg.n_stock = extract_token(line, 8);
    bg.item_price = extract_token(line, 6);
    collection.push_back(std::move(bg));
    return;
}

std::string sdds::Bakery::extract_token(std::string &line, int width)
{
    std::string token = line.substr(0, width);
    token = token.substr(0, token.find_last_not_of(' ') + 1);
    line.erase(0, width); // remove token from line(Referenced) once extracted and stored
    return token;
}

std::ostream &sdds::operator<<(std::ostream &out, const BakedGood &b)
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
    out << std::setw(8) << std::right << b.item_price;
    out << " * ";

    return out;
}

void sdds::Bakery::showGoods(std::ostream &os) const // prints BakedGoods
{
    std::ostream_iterator<BakedGood> print(os, "\n"); // print will use ostream os to print BakedGoods
    std::copy(collection.begin(), collection.end(), print);
    return;
}