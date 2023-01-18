// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/*
Name : Tushardeep Singh
seneca e-mail: tsingh245@myseneca.ca
Seneca Student ID: 160427217
completion date: 14th January'2023
*/

/*
NOTE TO READERS:
    1. I have tried to keep variable names as descriptive as possible.
    2. I have tried to summarize the code logic in the comments.
    3. P2**... indicates code additions to p1 of lab1.
*/

// header guards
#ifndef FOODORDER_H
#define FOODORDER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

// global variables declared using 'extern' keyword
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
    class FoodOrder
    {
    private:
        // member variables
        char cust_name[10]{'\0'};
        // P2*****************************************************************************
        // char food_desc[25];
        string food_desc; // food_desc changed from char array to string data-type
        // P2*****************************************************************************
        double food_price;
        bool daily_special;

    public:
        // default constructor
        FoodOrder();

        // function: read
        // input: istream&
        // void
        // This function will attempt to read from the `istream` and store the information read into current object.
        void read(istream &obj);

        // function: display
        // Displays to the screen the content of an `Food Order` instance.
        // void
        void display();
    };
}

#endif