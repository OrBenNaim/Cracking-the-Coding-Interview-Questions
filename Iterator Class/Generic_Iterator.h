#ifndef Generic_Iterator_H
#define Generic_Iterator_H

#include <iostream>
using namespace std;

/* 
This is an Abstract Base Class for 'Generic Iterators' -> Therefore won't be able to create an instance of Generic_Iterator object.
The class contains basic functions that will be passed to derived classes. 
Other functions, such as 'operator++', will be implemented  in each derived class separately.
*/


template <class T>
class Generic_Iterator      
{
    public:
        T* current_ptr;     // Pointer to the current element

        Generic_Iterator(T* ptr=nullptr) : current_ptr(ptr) {}   // Default constructor


        virtual ~Generic_Iterator()=0;  // Pure virtual destructor -> Make this class abstruct base class

        //void GetCurrentPointer


        // Dereference operator (*) to return the current element:
        T& operator*() const {return *current_ptr;}


        // Equality operator to compare two Generic_Iterators
        bool operator==(const Generic_Iterator<T>& other_Generic_Iterator) const
        {
            return current_ptr == other_Generic_Iterator.current_ptr;   
        }


        // Inequality operator to compare two Generic_Iterators
        bool operator!=(const Generic_Iterator<T>& other_Generic_Iterator) const
        {
            return current_ptr != other_Generic_Iterator.current_ptr;   
        }


        friend ostream& operator<<(ostream& os, const Generic_Iterator<T>& Generic_Iterator)
        {
            if (Generic_Iterator.current_ptr) 
            {
                os << Generic_Iterator.current_ptr; // Print the current element
            } 
            else 
            {
                os << "null"; // Print null if the pointer is null
            }
            return os;
        }

        friend istream& operator>>(istream& is, Generic_Iterator<T>& Generic_Iterator)
        {
            if (Generic_Iterator.current_ptr) 
            {
                is >> *Generic_Iterator.current_ptr; // Input into the current element
            }
            return is;
        }

};

// Provide an empty definition for the pure virtual destructor outside the class
template <class T>
Generic_Iterator<T>::~Generic_Iterator() {}

#endif  // Generic_Iterator_H