/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (DIY)
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
#include "Label.h"
#include "LabelMaker.h"

using namespace std;

namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels > 0)
        {
            totalLabels = noOfLabels;
            listOfLabels = new Label[noOfLabels];
        }
        else
        {
            cout << "You can only input greater than zero" << endl;
            noOfLabels = 0;
        }
    }

    void LabelMaker::readLabels()
    {
        if (totalLabels > 0)
        {
            cout << "Enter " << totalLabels << " labels:" << endl;

            for (int i = 0; i < totalLabels; i++)
            {
                cout << "Enter label number " << i + 1 << endl;

                listOfLabels[i].readLabel();
            }
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < totalLabels; i++)
        {
            listOfLabels[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
        listOfLabels = nullptr;
        delete[] listOfLabels;
    }
}