#include <iostream>
#include "UniqueVector.h"

#ifndef UNIQUEVECTOR_CPP
#define UNIQUEVECTOR_CPP

using namespace std;

template<typename T>
bool UniqueVector<T>::empty()   // if size is 0, it must be empty.
{
    if (sizeV==0)
    {
	return true;
    }
    else
    {
	return false;
    }
}

template<typename T>
bool UniqueVector<T>::contains(const T& data)
{
    for (unsigned int index=0; index<sizeV; index++)
    {
        if (data == structure[index]) // if found at any given index, it must contain data
        {
            return true;
        }
    }

    return false;
}

template<typename T>
bool UniqueVector<T>::at(unsigned int pos, T& data)
{
    if (pos >= sizeV)    // valid index check
    {
	return false;
    }
    else if (pos < sizeV)
    {
        data = structure[pos]; // data mutated
    }
    return true;
}

template<typename T>
bool UniqueVector<T>::insert(const T& data)
{
    if (this->contains(data)) //avoids rest of function if item is already in vector
    {
        return false;
    }

    if (sizeV+1 <= maxsize)         //executes if vector is not full before adding new element
    {
        structure[sizeV]=data;
        sizeV++;
    }

    else if (sizeV+1 > maxsize) //block is only used if vector is full before adding item, creates bigger vector
    {
        createCopy();

        structure[sizeV]=data;
        maxsize=maxsize*2;      // size updates
        sizeV=sizeV+1;
    }

    return true;
}

template<typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos)
{
    if (pos > sizeV) 	//valid index check
    {
	return false;
    }

    if (this->contains(data)) //uniqueness check
    {
	return false;
    }


    if (sizeV+1 <= maxsize) //if array is not already full, this executes
    {
        for (int i=sizeV; i>pos; i--)
        {
            structure[i]=structure[i-1];
        }

        structure[pos]=data;
        sizeV++;
     }

    else if (sizeV+1 > maxsize) //if array is full before function call, copies it into new array and updates
    {
        createCopy();

        for (int i=sizeV; i>pos; i--) //shifts appropriate data over
        {
            structure[i]=structure[i-1];
        }

        structure[pos]=data;
        sizeV++;
        maxsize=maxsize*2;
    }
    return true;
}

template <typename T>
bool UniqueVector<T>::push_front(const T& data)
{
    if (this->contains(data)) // uniqueness check
    {
	return false;
    }

    if (sizeV+1 <= maxsize)  // if not full, shifts all elements over by 1 to free pos 0
    {
         for (int i=sizeV; i>0; i--)
         {
                structure[i]=structure[i-1];
         }
         structure[0]=data;
         sizeV++;
    }

    else if (sizeV+1 > maxsize) // if full, creates an array with larger capacity first, then proceeds
    {
         createCopy();

         for (int i=sizeV; i>0; i--)
         {
                structure[i]=structure[i-1];
         }
         structure[0]=data;
         sizeV++;
         maxsize=maxsize*2;

    }
    return true;
}

template<typename T>
bool UniqueVector<T>::remove(const T& data)
{
    if (this->contains(data))  // executes only if array has "data"
    {
        int i=0;
        for(; i<sizeV; i++)    // locates which index has "data"
        {
             if (structure[i]==data) {break;}
        }

        for (; sizeV-1>i; i++)  // shifts elements over to "delete" target index
        {
            structure[i]=structure[i+1];
        }
        sizeV--;
        return true;
    }
    else 		// function doesn't do anything if "data" isn't in array
    {
	return false;
    }
}

template<typename T>
bool UniqueVector<T>::remove(unsigned int pos, T& data)
{
    if (pos >= sizeV)   // valid index check
    {
	return false;
    }

    data = structure[pos]; // data takes value of chosen index

    for (; pos<sizeV-1; pos++)
    {
        structure[pos]=structure[pos+1]; //remove data by shifting elements
    }
    sizeV--;
    return true;
}

template<typename T>
bool UniqueVector<T>::pop_back(T& data)
{
    if (this->empty()==false)	  // can only execute if array is not empty
    {
        data = structure[sizeV-1];
        structure[sizeV-1]=structure[sizeV];
        sizeV--;
        return true;
    }
    else
    {
	return false;
    }
}

template<typename T>
void UniqueVector<T>::clear()
{
    T * temp;		// a new (empty) array is created and pointed to by structure,
    temp=structure;
    structure=new T[3];
    delete[] temp;     // deleting "old" array prevents memory leak
    temp=NULL;
    sizeV=0;
    maxsize=3;
}

template<typename T>
void UniqueVector<T>::createCopy() // helper function used to "resize" array when adding another element would
{				   // cause it to go over capacity
    T*temp;
    temp=structure;
    structure=new T[maxsize*2];

    for (int counter=0; counter<sizeV; counter++) //copies over elements into new vector
    {
        structure[counter]=temp[counter];
    }

    delete [] temp;         // deletes outdated list and sets pointer to null
    temp=NULL;
}

template<typename X>
bool operator == (UniqueVector<X>& first, UniqueVector<X>& second) //allows comparison between elements of 2 UniqueVector objects
{
    if(first.size() != second.size()) // if size does not match, no way can they have the same exact elements
    {
	return false;
    }
    else
    {
        for (int i=0; i<first.size(); i++)
        {
            if (first.structure[i] != second.structure[i]) // if a single element does not match, immediately return false
            {
	    	return false;
	    }
        }
    }
    return true;  // if it makes it to this point, all elements must be exactly the same in the same order
}

#endif // UNIQUEVECTOR_CPP
