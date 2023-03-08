// Name: Tushardeep Singh
// Seneca Student ID: 160427217
// Seneca email: tsingh245@myseneca.ca
// Date of completion: 2nd March'2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef CUSTOMER_ORDER_H
#define CUSTOMER_ORDER_H

#include "Utilities.h"
#include "Station.h"

namespace sdds
{
    class CustomerOrder
    {
    public:
        struct Item
        {
            std::string m_itemName;
            size_t m_serialNumber{0};
            bool m_isFilled{false};

            Item(const std::string &src) : m_itemName(src){};
        };

        CustomerOrder();
        CustomerOrder(const std::string &str);
        CustomerOrder(CustomerOrder &) { throw std::runtime_error("do not call copy constructor on CustomerOrder object."); }
        CustomerOrder &operator=(CustomerOrder &) = delete;
        CustomerOrder(CustomerOrder &&src) noexcept;
        CustomerOrder &operator=(CustomerOrder &&src) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;

    private:
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item **m_lstItem{};

        static size_t m_widthField;
    };
}

#endif