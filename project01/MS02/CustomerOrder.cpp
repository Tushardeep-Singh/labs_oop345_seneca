// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 2nd March'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <vector>
#include "CustomerOrder.h"

size_t sdds::CustomerOrder::m_widthField{};
sdds::CustomerOrder::CustomerOrder() = default;

// 1-arg constructor
sdds::CustomerOrder::CustomerOrder(const std::string &str)
{
    Utilities tempUtilities;
    size_t pos{0u};
    bool more = true;

    m_name = tempUtilities.extractToken(str, pos, more);
    m_product = tempUtilities.extractToken(str, pos, more);

    // vector to store item names
    std::vector<std::string> temp_arr;

    while (more)
    {
        temp_arr.push_back(tempUtilities.extractToken(str, pos, more));
        ++m_cntItem;
    }
    // assign item names
    m_lstItem = new Item *[m_cntItem];
    for (size_t i = 0u; i < m_cntItem; ++i)
    {
        m_lstItem[i] = new Item(temp_arr[i]);
    }

    if (m_widthField < tempUtilities.getFieldWidth())
    {
        m_widthField = tempUtilities.getFieldWidth();
    }
}

// move constructor
sdds::CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept
{
    if (this != &src)
    {
        this->m_lstItem = nullptr;

        this->m_name = src.m_name;
        this->m_product = src.m_product;
        this->m_cntItem = src.m_cntItem;
        this->m_lstItem = std::move(src.m_lstItem);

        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;
    }
}

// move assigment operator
sdds::CustomerOrder &sdds::CustomerOrder::operator=(CustomerOrder &&src) noexcept
{
    if (this != &src)
    {
        this->m_name = "";
        this->m_product = "";
        this->~CustomerOrder();
        this->m_cntItem = 0;

        this->m_name = src.m_name;
        this->m_product = src.m_product;
        this->m_cntItem = src.m_cntItem;
        this->m_lstItem = std::move(src.m_lstItem);

        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;
    }
    return *this;
}

// destructor
sdds::CustomerOrder::~CustomerOrder()
{
    if (m_lstItem != nullptr)
    {
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        delete[] m_lstItem;
        m_lstItem = nullptr;
    }
}

bool sdds::CustomerOrder::isOrderFilled() const
{
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        if (!(m_lstItem[i]->m_isFilled))
        {
            return false;
        }
        continue;
    }
    return true;
}

bool sdds::CustomerOrder::isItemFilled(const std::string &itemName) const
{
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        if (m_lstItem[i]->m_itemName == itemName)
        {
            return (m_lstItem[i]->m_isFilled);
        }
        continue;
    }
    return true;
}

void sdds::CustomerOrder::fillItem(Station &station, std::ostream &os)
{
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        if (station.getItemName() == m_lstItem[i]->m_itemName && m_lstItem[i]->m_isFilled == false)
        {
            if (station.getQuantity() >= 1)
            {
                if (i == 0)
                {
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    station.getNextSerialNumber();
                    os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
                }
                // do not fill if station.getItemName() has been filled before
                for (int x = i - 1; x >= 0; --x)
                {
                    if (station.getItemName() == m_lstItem[x]->m_itemName)
                    {
                        break;
                    }
                    if (x == 0)
                    {
                        m_lstItem[i]->m_isFilled = true;
                        station.updateQuantity();
                        station.getNextSerialNumber();
                        os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
                    }
                    continue;
                }
                break;
            }
            else
            {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
            }
        }
        continue;
    }
}

void sdds::CustomerOrder::display(std::ostream &os) const
{
    os << m_name << " - " << m_product << '\n';
    for (size_t i = 0u; i < m_cntItem; ++i)
    {
        os << '[' << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] ";
        os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName << "   - ";
        if (m_lstItem[i]->m_isFilled == false)
        {
            os << "TO BE FILLED\n";
        }
        else
        {
            os << "FILLED\n";
        }
    }
}