#include<iostream>
using namespace std;

#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H

template<typename T>
class UniqueVector
{
public:
    // constructor and destructor
    UniqueVector(): maxsize(3), sizeV(0){structure=new T[maxsize];}
    ~UniqueVector() {delete[] structure;}

    //tells how much space is available in current array
    unsigned int capacity() {return maxsize;};
    // tells number of elements in array
    unsigned int size() {return sizeV;};
    // tells if vector has 0 elements
    bool empty();
    //tells whether or not array has "data"
    bool contains(const T& data);
    //data takes value of element in pos
    bool at(unsigned int pos, T& data);
    //if not already in array, data is added to back of array
    bool insert(const T& data);
    // data added in position pos of array
    bool insert(const T& data, unsigned int pos);
    //data added to position 0
    bool push_front(const T& data);
    //removes "data' if it's in array
    bool remove(const T& data);
    // data's value becomes element in position pos, then that element is removed from array
    bool remove(unsigned int pos, T& data);
    //data takes value of last element in array, then element is removed
    bool pop_back(T& data);
    //removes all elements in array and resets size to 0 and capacity to 3
    void clear();

    // overloaded operator
    template<typename X>
    friend bool operator == (UniqueVector<X>&, UniqueVector<X>&);

private:
    unsigned int maxsize; //capacity of array
    unsigned int sizeV;   // number of elements in array
    T * structure;        // foundation of dynamic array

    //helper function which resizes array when full
    void createCopy();
};
#include "UniqueVector.cpp"
#endif // UNIQUEVECTOR_H
