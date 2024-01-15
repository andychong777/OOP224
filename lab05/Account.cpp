/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (Part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty()
   {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account()
   {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance)
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream &Account::display() const
   {
      if (*this)
      {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
      bool result = false;

      if (m_balance >= 0.0 && (m_number >= 10000 && m_number <= 99999))
      {
         result = true;
      }

      return result;
   }
   Account::operator int() const
   {
      return m_number;
   }
   Account::operator double() const
   {
      return m_balance;
   }

   bool Account::operator~() const
   {
      return m_number == 0;
   }

   Account &Account::operator+=(const double deposit)
   {
      if (m_number > 0 && m_balance >= 0.0 && deposit > 0.0)
      {
         m_balance += deposit;
      }
      return *this;
   }
   Account &Account::operator-=(const double withdraw)
   {
      if (m_number > 0 && m_balance >= 0.0 && withdraw > 0.0 && (m_balance - withdraw) > 0.0)
      {
         m_balance -= withdraw;
      }

      return *this;
   }

   Account &Account::operator<<(Account &move)
   {
      if (this->m_number > 0 && move.m_number > 0 && this->m_number != move.m_number)
      {
         this->m_balance += move.m_balance;
         move.m_balance = 0;
      }

      return *this;
   }

   Account &Account::operator>>(Account &move)
   {
      if (this->m_number > 0 && move.m_number > 0 && this->m_number != move.m_number)
      {
         move.m_balance += this->m_balance;
         this->m_balance = 0;
      }

      return *this;
   }

   Account &Account::operator=(const int acc)
   {
      if (m_number == 0)
      {
         m_number = acc;
      }
      else if (acc < 0)
      {
         setEmpty();
      }
      return *this;
   }

   Account &Account::operator=(Account &move)
   {
      if (this->m_number == 0 && move.m_number >= 10000 && move.m_number <= 99999 && move.m_balance >= 0)
      {
         this->m_number = move.m_number;
         this->m_balance = move.m_balance;
         move.m_number = 0;
         move.m_balance = 0;
      }

      return *this;
   }

   double operator+(const Account &left, const Account &right)
   {
      double sum = 0.0;

      if (left.m_number > 0 && right.m_number > 0)
      {
         sum = left.m_balance + right.m_balance;
      }

      return sum;
   }
   double operator+=(double &value, const Account &add)
   {
      if (add.m_number > 0)
      {
         value += add.m_balance;
      }

      return value;
   }

}