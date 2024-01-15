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
#include "cstring.h"
#include "Food.h"
#include "CalorieList.h"

using namespace std;
namespace sdds
{
    bool CalorieList::isValid() const
    {
        bool result = true;
        bool flag = true;

        for (int i = 0; i < noOfFood && flag; i++)
        {
            if (!food[i].isValid())
            {
                result = false;
                flag = false;
            }
        }

        return result;
    }

    int CalorieList::totalCal() const
    {
        int result = 0;

        for (int i = 0; i < noOfFood; i++)
        {
            result += food[i].calorie();
        }

        return result;
    }

    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::Footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;

        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << totalCal() << " |            |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }

        cout << "+----------------------------------------------------+" << endl;
    }

    CalorieList::CalorieList()
    {

        food = nullptr;
        noOfFood = 0;
        Count = 0;
    }

    CalorieList::~CalorieList()
    {

        if (food != nullptr)
        {
            delete[] food;
            food = nullptr;
        }
    };

    void CalorieList::init(int noOfList)
    {

        if (noOfList > 0)
        {

            noOfFood = noOfList;

            Count = 0;

            food = new Food[noOfList];
        }
    }

    bool CalorieList::add(const char *food_name, int calNum, int consumTime)
    {
        bool result = false;

        if (Count < noOfFood)
        {
            food[Count].set(food_name, calNum, consumTime);
            Count++;

            result = true;
        }

        return result;
    }

    void CalorieList::display() const
    {
        Title();

        for (int i = 0; i < noOfFood; i++)
        {
            food[i].display();
        }

        Footer();
    }

    void CalorieList::deallocate()
    {
        delete[] food;
        food = nullptr;
    }
}
