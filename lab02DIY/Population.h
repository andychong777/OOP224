/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulations.csv"
namespace sdds
{
    struct ReportRecord
    {
        char *postalCode;
        int pop;
    };

    bool load(const char file[]);

    void sort();

    void display();

    void display(const ReportRecord &report);

    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_