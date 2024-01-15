/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (Part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
    class Account
    {
    private:
        int m_number;
        double m_balance;
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);
        std::ostream &display() const;

        operator bool() const;
        operator int() const;
        operator double() const;

        bool operator~() const;

        Account &operator+=(const double deposit);
        Account &operator-=(const double withdraw);
        Account &operator<<(Account &move);
        Account &operator>>(Account &move);
        Account &operator=(const int acc);
        Account &operator=(Account &move);

        friend double operator+(const Account &left, const Account &right);
        friend double operator+=(double &value, const Account &add);
    };

}
#endif // SDDS_ACCOUNT_H_