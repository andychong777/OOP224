/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (PART 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }

   // TODO: read functions go here    
   bool read(char m_name[])
   {
      if (fscanf(fptr, "%[^\n]\n", m_name) == 1)
      {
         return true;
      }
      else
      {
         return false;
      }

   }

   bool read(int& m_empNo)
   {
      if (fscanf(fptr, "%d,", &m_empNo) == 1)
      {
         return true;
      }
      else
      {
         return false;
      }
      
   }

   bool read(double& m_salary)
   {
      if (fscanf(fptr, "%lf,", &m_salary) == 1)
      {
         return true;
      }
      else
      {
         return false;
      }
      
   }
}