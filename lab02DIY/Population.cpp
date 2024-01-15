/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "File.h"
#include "Population.h"

using namespace std;

namespace sdds
{
    int numberOfPostCodes;
    ReportRecord *reports;

    bool load(const char file[])
    {
        char postalCode[100];

        bool ok = false;

        if (openFile(file))
        {
            numberOfPostCodes = noOfRecords();
            reports = new ReportRecord[numberOfPostCodes];

            for (int i = 0; i < numberOfPostCodes; i++)
            {
                if (read(postalCode, reports[i].pop))
                {
                    reports[i].postalCode = new char[strLen(postalCode) + 1];
                    strCpy(reports[i].postalCode, postalCode);
                    ok = true;
                }
                else
                {
                    ok = false;
                    cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                }
            }
        }
        else
        {
            cout << "Could not open data file: " << file << endl;
        }

        return ok;
    }

    void sort()
    {
        int i, j;
        ReportRecord temp;

        for (i = numberOfPostCodes - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (reports[j].pop > reports[j + 1].pop)
                {
                    temp = reports[j];
                    reports[j] = reports[j + 1];
                    reports[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        int totalPopulation = 0;

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < numberOfPostCodes; i++)
        {
            cout << i + 1 << "- ";
            display(reports[i]);
            totalPopulation += reports[i].pop;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation << endl;
    }

    void display(const ReportRecord &report)
    {
        cout << report.postalCode << ":  " << report.pop << endl;
    }

    void deallocateMemory()
    {
        delete[] reports;
    }
}