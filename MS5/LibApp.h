/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 2.0
Author	Andy Chong
Revision History
-----------------------------------------------------------
Date      Reason
Aug18     MS5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Menu.h"
#include "Book.h"
#include "Streamable.h"
#include "Date.h"
#include "Publication.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include "Lib.h"

namespace sdds
{
   const int SDDS_LIBRARY_CAPACITY = 333;
   const int SDDS_FILENAME_MAX = 256;

   class LibApp
   {
   private:
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;

      char m_filename[SDDS_FILENAME_MAX];  // Store the filename
      Publication* PPA[SDDS_LIBRARY_CAPACITY]; // Publication Pointers Array (PPA)
      int NOLP;  // Number Of Loaded Publications
      int LLRN;  
      Menu m_pubTypeMenu; 
   
      bool confirm(const char *message);

      void load();   // prints: "Loading Data"<NEWLINE>
      void save();   // prints: "Saving Data"<NEWLINE>
      int search(int);

      void returnPub(); /*  Calls the search() method.
                            prints "Returning publication"<NEWLINE>
                            prints "Publication returned"<NEWLINE>
                            sets m_changed to true;
                        */

      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      LibApp(const char *filename);
      ~LibApp();
      void run();

      Publication *getPub(int libRef);
   };
}
#endif // !SDDS_LIBAPP_H
