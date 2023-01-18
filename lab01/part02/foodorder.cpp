// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
NOTE TO READERS:
    1. I have tried to keep variable names as descriptive as possible.
    2. I have tried to summarize the code logic in the comments.
    3. P2**... indicates code additions to p1 of lab1.
*/

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 14th January'2023
*/

#include "foodorder.h"

// global variables declared with 'extern' keyword need to be declared before being used in the program.
double g_taxrate;
double g_dailydiscount;

sdds::FoodOrder::FoodOrder() = default;

void sdds::FoodOrder::read(istream &obj)
{
    // static variable named 'counter' which allows to read next order once the current order has been read.
    static size_t counter = 0;

    // getline() stores at-max 9 charaters in cust_name and exits when ',' is interpreted.
    obj.getline(cust_name, 10, ',');

    // P2*****************************************************************************
    // obj.getline(food_desc, 25, ',');
    getline(obj, food_desc, ','); // data stored in food_desc as string.
    // P2*****************************************************************************
    obj >> food_price;
    obj.ignore(1, ',');

    char d_special[2];

    // get() stores only one character, the next one is null terminator.
    obj.get(d_special, 2);

    if (d_special[0] == 'N')
    {
        daily_special = false;
    }
    else
    {
        daily_special = true;
    }
    ++counter;
}

void sdds::FoodOrder::display()
{
    // P2*****************************************************************************
    // pointer to an array with size : food_desc.length() + null terminator
    char *f_d_any_length = new char[food_desc.length() + 1];

    // food_desc.c_str() will return pointer to an array with size: food_desc.length() + null terminator
    // copying the contents of string 'food_desc' into pointer to array 'f_d_any_length'
    strcpy(f_d_any_length, food_desc.c_str());
    // P2*****************************************************************************

    // static will prevent 'counter' from getting re-initialised with 1.
    static size_t counter{1};
    double taxed_price = (food_price + (food_price * g_taxrate));
    double special_price = taxed_price - g_dailydiscount;

    // if cust_name is empty then it's length is 0.
    if (strlen(cust_name) == 0)
    {
        cout << left;
        cout << setw(2) << counter << ". "
             << "No Order" << endl;
    }
    else
    { // left-align, right-align, setw() together form the specified format.
        cout << left;
        cout << setw(2) << counter << setw(2) << "." << setw(10) << cust_name << "|" << setw(25) << /*food_desc*/ f_d_any_length << "|";
        cout << setprecision(2);
        cout << fixed;
        cout << setw(12) << taxed_price << "|";

        if (daily_special)
        {
            cout << right;
            cout << setw(13) << special_price << endl;
        }
        else
        {
            cout << endl;
        }
    }

    ++counter;

    // P2*****************************************************************************
    // dynamic memory returned
    delete[] f_d_any_length;
    f_d_any_length = nullptr;
    // P2*****************************************************************************
}