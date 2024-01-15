/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <iomanip>
#include "Food.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Food::~Food() {}

    Food::Food()
    {
        foodName[0] = '\0';
        calNum = -1;
        mealTime = 0;
    }

    bool Food::isValid() const
    {
        return foodName[0] != '\0';
    }

    int Food::calorie() const
    {
        return calNum;
    }

    void Food::set(const char *name, int calories, int time)
    {
        if (name != nullptr && name[0] != '\0' && calories > -1 && calories <= 3000 && time > 0 && time < 5)
        {
            strnCpy(foodName, name, 30);
            calNum = calories;
            mealTime = time;
        }
    }

    void Food::display() const
    {
        if (isValid())
        {
            display(foodName);

            cout << " | ";
            cout.width(4);
            cout << calNum;

            display(mealTime);
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    void Food::display(const char *name) const
    {
        char pad = cout.fill('.');
        cout << "| ";
        cout.setf(ios::left);
        cout.width(30);
        cout << name;
        cout.fill(pad);
        cout.unsetf(ios::left);
    }

    void Food::display(int time) const
    {
        cout << " | ";
        cout.setf(ios::left);
        cout.width(11);

        switch (time)
        {
        case 1:
            cout << "Breakfast"
                 << "|" << endl;
            ;
            break;

        case 2:
            cout << "Lunch"
                 << "|" << endl;
            ;
            break;

        case 3:
            cout << "Dinner"
                 << "|" << endl;
            ;
            break;

        case 4:
            cout << "Snack"
                 << "|" << endl;
            ;
            break;
        }
        cout.unsetf(ios::left);
    }

}
