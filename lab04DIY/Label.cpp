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
    Label::Label()
    {
        text = nullptr;
        strCpy(symbol, defautSymbol);
    }

    Label::Label(const char *frameArg)
    {
        text = nullptr;
        strCpy(symbol, frameArg);
    }

    Label::Label(const char *frameArg, const char *content)
    {
        strCpy(symbol, frameArg);

        size_t contentLength = strLen(content);

        if (contentLength < 71)
        {
            text = new char[contentLength + 1];
            strCpy(text, content);
        }
    }

    Label::~Label()
    {
        if (text)
        {
            text = nullptr;
            delete[] text;
        }
    }

    void Label::readLabel()
    {
        char input[71];

        if (text != nullptr)
        {
            delete[] text;
            text = nullptr;
        }

        cout << "> ";

        cin.get(input, 71);
        cin.ignore(32767, '\n');
        input[70] = '\0';

        text = new char[strLen(input) + 1];
        strCpy(text, input);
    }

    std::ostream &Label::printLabel() const
    {
        if (text != nullptr)
        {
            cout << symbol[0];
            cout.fill(symbol[1]);
            cout.width(strLen(text) + 3);
            cout << symbol[2] << endl;

            cout << symbol[7];
            cout.fill(' ');
            cout.width(strLen(text) + 3);
            cout << symbol[3] << endl;

            cout << symbol[7];
            cout.width(strLen(text) + 1);
            cout << text;
            cout << " " << symbol[3] << endl;

            cout << symbol[7];
            cout.fill(' ');
            cout.width(strLen(text) + 3);
            cout << symbol[3] << endl;

            cout << symbol[6];
            cout.fill(symbol[5]);
            cout.width(strLen(text) + 3);
            cout << symbol[4];
        }
        
        return cout;
    }
}