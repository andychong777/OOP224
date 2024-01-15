/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    MotorVehicle::MotorVehicle(){
        strCpy(licPlate, "");
        year = 0;
        strCpy(address, "");
    }

    MotorVehicle::MotorVehicle(const char* lp, int yr){
        strnCpy(licPlate, lp, 8);
        year = yr;
        strCpy(address, "Factory");
    }

    void MotorVehicle::moveTo(const char* addr){
        cout << "|" << setw(8) << right << licPlate <<
                "| |" << setw(20) << right << address <<
                " ---> " << setw(20) << left << addr <<
                "|" << endl;
        strnCpy(address, addr, 63);
    }

    ostream &MotorVehicle::write(ostream &os)const{
        os << "| " << year <<
             " | " << licPlate <<
             " | " << address;
        return os;
    }

    istream &MotorVehicle::read(istream &is){
        cout << "Built year: ";
        is >> year;
        cout << "License plate: ";
        is >> licPlate;
        cout << "Current location: ";
        is >> address;
        return is;
    }

    std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &mv)
    {
        return mv.write(ostr);
    }

    std::istream &operator>>(std::istream &istr, MotorVehicle &mv)
    {
        return mv.read(istr);
    }
}