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
#include <fstream>
#include <string>
#include "Truck.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Truck::Truck(const char* lp, int yr, double cap, const char* addr):MotorVehicle(lp, yr){
        moveTo(addr);
        capacity = cap;
        load = 0;
    }

    bool Truck::addCargo(double cargo){
        if(load + cargo <= capacity){
            load += cargo;
            return true;
        }else if(load != capacity){
            // need this to meet sample output in main line 87
            load = capacity;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo(){
        if(load > 0){
            load = 0;
            return true;
        }
        return false;
    }

    ostream &Truck::write(ostream &os)const{
        MotorVehicle::write(os);
        os << "| " << load << " / " << capacity;
        return os;
    }

    istream &Truck::read(istream &is){
        MotorVehicle::read(is);
        cout << "Capacity: ";
        is >> capacity;
        cout << "Cargo: ";
        is >> load;
        if(load > capacity){
            cout << "adjusted load to capacity" << endl;
            load = capacity;
        }
        return is;
    }

    std::ostream &operator<<(std::ostream &ostr, const Truck &truck)
    {
        return truck.write(ostr);
    }

    std::istream &operator>>(std::istream &istr, Truck &truck)
    {
        return truck.read(istr);
    }
}