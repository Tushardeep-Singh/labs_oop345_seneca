// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 11th Febuary'2023
*/
#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H
#include "Toy.h"

namespace sdds
{
    class ConfirmOrder
    {
    public:
        // default constructor
        ConfirmOrder() = default;

        // overload '<<'
        friend std::ostream &operator<<(std::ostream &out, ConfirmOrder &confirmOrder)
        {
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            std::cout << "Confirmations to Send" << '\n';
            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            if (confirmOrder.count == 0)
            {
                std::cout << "There are no confirmations to send!" << '\n';
            }

            for (int i = 0; i < confirmOrder.count; ++i)
            {
                std::cout << *(confirmOrder.array_toy[i]); // will use Toy overload '<<'
            }

            std::cout << std::setw(26) << std::setfill('-') << std::right << "-" << '\n'
                      << std::setfill(' ');
            return out;
        }

        // overload '+='
        ConfirmOrder &operator+=(const Toy &toy)
        {
            // check duplicate
            // allocate temp
            // add to temp &toy
            // loop through, add to temp all the value before count stored in array_toy
            // then deallocate array_toy
            // allocate memory to array_toy with counter +1
            // store everything into array_toy again with c+ 1 from temp
            // delete temp

            // check for duplicate value
            for (int i = 0; i < count; ++i)
            {
                if (array_toy[i] == &toy)
                {
                    // delete[] temp;
                    // temp = nullptr;
                    return *this;
                }
            }

            const Toy **temp = new const sdds::Toy *[count + 1]; // create a temporary array, used to resize the array_toy
            temp[count] = &toy;

            // check for duplicate value
            // for (int i = 0; i < count; ++i)
            // {
            //     if (array_toy[i] == &toy)
            //     {
            //         delete[] temp; // if duplicate delete temp otherwise memory leak
            //         temp = nullptr;
            //         return *this;
            //     }
            // }

            // below in a series, the array_toy gets resized
            for (int i = 0; i < count; ++i)
            {
                temp[i] = this->array_toy[i];
            }

            for (int i = 0; i < count; ++i)
            {
                this->array_toy[i] = nullptr;
            }

            if (array_toy != nullptr)
            {
                delete[] array_toy;
                array_toy = nullptr;
            }

            array_toy = new const Toy *[count + 1];

            for (int i = 0; i <= count; ++i)
            {
                this->array_toy[i] = temp[i];
            }

            for (int i = 0; i < count; ++i)
            {
                temp[i] = nullptr;
            }
            delete[] temp;
            temp = nullptr;

            ++count;
            return *this;
        }

        // overload '-='
        ConfirmOrder &operator-=(const Toy &toy)
        {
            int j = count;
            // removing and assigning (i+1) to (i)
            for (int i = 0; i < count; ++i)
            {
                if (array_toy[i] == &toy)
                {
                    array_toy[i] = nullptr;
                    for (; i < count - 1; ++i)
                    {
                        array_toy[i] = array_toy[i + 1];
                    }
                    count--;
                    break;
                }
            }

            // If element removed, j != count, true
            // resizing the array
            if (j != count)
            {
                const sdds::Toy **temp = new const sdds::Toy *[count]; // used to resize array_toy
                for (int i = 0; i < count; ++i)
                {
                    temp[i] = array_toy[i];
                }
                for (int i = 0; i < count; ++i)
                {
                    array_toy[i] = nullptr;
                }
                delete[] array_toy;
                array_toy = nullptr;

                array_toy = new const sdds::Toy *[count];
                for (int i = 0; i < count; ++i)
                {
                    array_toy[i] = temp[i];
                }
                for (int i = 0; i < count; ++i)
                {
                    temp[i] = nullptr;
                }
                delete[] temp;
                temp = nullptr;
            }
            return *this;
        }

        // copy constructor
        ConfirmOrder(const ConfirmOrder &confirmOrder)
        {
            if (this != &confirmOrder) // self assign check
            {
                this->count = confirmOrder.count;
                this->~ConfirmOrder(); // clean up before
                this->array_toy = new const sdds::Toy *[this->count];
                for (int i = 0; i < this->count; ++i)
                {
                    this->array_toy[i] = confirmOrder.array_toy[i];
                }
            }
        }

        // assingment operator:
        ConfirmOrder &operator=(const ConfirmOrder &assin_this)
        {
            if (this != &assin_this) // self assign check
            {
                this->count = 0;
                this->count = assin_this.count;
                if (this->array_toy != nullptr) // clean up before
                {
                    for (int i = 0; i < this->count; ++i)
                    {
                        delete[] this->array_toy[i];
                        this->array_toy[i] = nullptr;
                    }
                    delete[] array_toy;
                }
                this->array_toy = new const sdds::Toy *[this->count];

                for (int i = 0; i < this->count; ++i)
                {
                    this->array_toy[i] = assin_this.array_toy[i];
                }
            }
            return *this;
        }

        // move constructor
        ConfirmOrder(ConfirmOrder &&confirmOrder)
        {
            if (this != &confirmOrder) // self assign check
            {
                if (this->array_toy != nullptr) // clean up
                {
                    for (int i = 0; i < this->count; ++i)
                    {
                        this->array_toy[i] = nullptr;
                    }
                    delete[] array_toy;
                }
                this->count = 0;
                this->count = confirmOrder.count;
                this->array_toy = new const sdds::Toy *[this->count];
                for (int i = 0; i < this->count; ++i)
                {
                    this->array_toy[i] = confirmOrder.array_toy[i];
                }

                for (int i = 0; i < confirmOrder.count; ++i)
                {
                    confirmOrder.array_toy[i] = nullptr;
                }
                delete[] confirmOrder.array_toy;
                confirmOrder.array_toy = nullptr;
                confirmOrder.count = 0;
            }
        }

        // destructor
        ~ConfirmOrder()
        {
            if (array_toy != nullptr)
            {
                for (int i = 0; i < count; ++i)
                {
                    array_toy[i] = nullptr;
                }
                delete[] array_toy;
                array_toy = nullptr;
            }
        }

    private:
        const sdds::Toy **array_toy = nullptr;
        int count{0};
    };
}

#endif