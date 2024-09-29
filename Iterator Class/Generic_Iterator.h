#ifndef Generic_Iterator_H
#define Generic_Iterator_H

#include <iostream>

using namespace std;

template <class T>
class Generic_Iterator
{
    protected:
        T* current_ptr;     // Pointer to the current element


    public:
        Generic_Iterator(T* ptr=nullptr) : current_ptr(ptr) {}   // Default constructor


        virtual ~Generic_Iterator() = 0;  // Pure virtual destructor -> Make this class to abstruct base class


        // Make the increment operator pure virtual to enforce derived classes to implement it
        virtual Generic_Iterator& operator++()=0;         // Pure virtual function
        virtual Generic_Iterator operator++(int)=0;      // Pure virtual function for postfix


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