/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include "Label.h"

using namespace std;

namespace sdds {

    class LabelMaker
    {
        Label *listOfLabels;
        int totalLabels;

    public:
        //creates a dynamic array of Labels to the size of noOfLabels
        LabelMaker(int noOfLabels);
        
        //Gets the contents of the Labels
        void readLabels();

        //Prints the Labels
        void printLabels();

        //Deallocates the memory when LabelMaker goes out of scope.
        ~LabelMaker();
    };
    
}
#endif // !SDDS_LABELMAKER_H_
