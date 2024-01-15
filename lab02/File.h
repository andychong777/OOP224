/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (PART 1)
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

   // TODO: Declare read prototypes

   bool read(char* m_name);

   bool read(int& m_empNo);

   bool read(double& m_salary);

}
#endif // !SDDS_FILE_H_