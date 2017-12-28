#include <iostream>
#include <string>
#include "UniqueVector.h"
using namespace std;

#ifndef CLASSROOM_H
#define CLASSROOM_H

class Classroom
{
public:
    // adds student to roster if they are not on it already
    bool addStudent(const string& name);
    // if student is on roster, they are removed from it
    bool removeStudent(const string& name);
    // checks to see if student is in roster
    bool containsStudent(const string& name);
    // creates string of all student names in the class
    string listAllStudents();
    // removes from the vector and returns the name that comes alphabetically first
    string removeAlphabeticallyFirst();
    // removes from the vector and returns the name that comes alphabetically last
    string removeAlphabeticallyLast();
    // adds contens of otherclass to current classroom object
    void combineClasses(Classroom& otherClass);

private:
    UniqueVector<string> roster; // uniquevector object of strings which contains the class list
};

#endif // CLASSROOM_H
