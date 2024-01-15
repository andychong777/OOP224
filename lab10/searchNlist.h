/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #10 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SEARCH_N_LIST_H
#define SEARCH_N_LIST_H

#include "Car.h"
#include "Student.h"
#include "Employee.h"
#include "Collection.h"
#include <iostream>

// Function template: search
template <typename Collection, typename T, typename Key>
bool search(Collection& collection, T* array, size_t size, const Key& key) {
    // Template type requirements:
    // 1. The Collection type must support the "==" operator to check for a match between objects and the key.
    // 2. The T type (array element type) must be comparable with the Key type using the "==" operator.

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == key) {
            collection.add(array[i]);
            found = true;
        }
    }
    return found;
}

// Function template: listArrayElements
template <typename T>
void listArrayElements(const char* title, const T* array, size_t size) {
    // Template type requirements:
    // The T type must support the insertion operator '<<' for printing.

    std::cout << title << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << i + 1 << ": " << array[i] << std::endl;
    }
}

/*
search function template:
The search function template accepts a Collection and an array of templated objects. 
To work with this function, the Collection type must have support for the "==" operator 
so that we can check for a match between objects and the key. Additionally, the T 
type (array element type) must be comparable with the Key type using the "==" operator, 
which is necessary to compare the elements of the array with the key to find matches.

listArrayElements function template:
The listArrayElements function template prints the elements of an array. To work 
with this function, the T type must support the insertion operator '<<' so that 
we can print the elements using the cout object.
*/
#endif // SEARCH_N_LIST_H
