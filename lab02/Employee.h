/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (PART 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds 
{
   struct Employee 
   {
      char* m_name;
      int m_empNo;
      double m_salary;
   };
   
   //sorts the dynamic array of employees based on the GPA of the employees.
   void sort();
   // loads a employee structue with its values from the file
   bool load(Employee &employee);
   // allocates the dyanmic array of employees and loads all the file
   // recoreds into the array
   bool load();

   // TODO: Declare the prototype for the display function that
   // displays a employee record on the screen:
   void display(const Employee &employee);

   // TODO: Declare the prototype for the display function that 
   // first sorts the employees then displays all the employees on the screen
   void display();

   // TODO: Declare the prototype for the deallocateMemory function that
   // first will deallocate all the names in the employee elements
   // then it will deallocate the employee array 
   void deallocateMemory();
}   
#endif // SDDS_EMPLOYEE_H_