/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds
{
    class CalorieList
    {
    private:
        int noOfFood;
        int Count;
        Food *food;

        bool isValid() const;
        int totalCal() const;
        void Title() const;
        void Footer() const;

    public:
        CalorieList(); 
        ~CalorieList();

        void init(int noOfList);
        bool add(const char *food_name, int calNum, int consumTime);
        void display() const;
        void deallocate();
    };
}

#endif