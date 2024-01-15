/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Author Andy Chong
// Description
// Get int function
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"

using namespace std;
namespace sdds
{
    int getInt(int max)
    {
        int input{};
        bool valid = false;
        cin >> input;
        while (valid == false)
        {
            if (cin.fail() || input > max || input < 0)
            {

                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> input;
            }
            else
            {
                valid = true;
                cin.ignore(1000, '\n');
            }
        }
        return input;
    }

}