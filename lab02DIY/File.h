/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds
{
   bool openFile(const char filename[]);

   void closeFile();

   int noOfRecords();

   // get postalCode and Pop

   bool read(char postalCode[], int &pop);

}
#endif // !SDDS_FILE_H_