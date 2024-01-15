/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (part1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds
{
    class Bill
    {
    private:
        char m_title[37];  // title of the shopping list
        Item* m_items;     // pointer to the dynamically allocated array of Items
        int m_noOfItems;   // size of the dynamically allocated array of Items
        int m_itemsAdded;  // number of the Items added by the add method

        double totalTax()const;   // returns the total tax applied to the Items
        double totalPrice()const;  // returns the sum of prices of Items
        void Title()const;       // Prints the title of the shopping list
            // prints the footer contaning total tax, price and total price after tax
        void footer()const;
        void setEmpty();     // sets the Bill to an emtpy state
        bool isValid()const;  // returns true is the Bill and all of its Items are valid

    public:
        void init(const char *title, int noOfItems);
        bool add(const char *item_name, double price, bool taxed);
        void display() const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H