#include <iostream>
#include "Classroom.h"
using namespace std;

bool Classroom::addStudent(const string& name)
{
    return roster.insert(name); // uses insert function of uniquevector class
}

bool Classroom::removeStudent(const string& name)
{
    return roster.remove(name); // uses remove function of uniquevector class
}

bool Classroom::containsStudent(const string& name)
{
    return roster.contains(name); // uses contains function of uniquevector class
}

string Classroom::listAllStudents()
{
    if (roster.size() == 0) // if empty, return empty string
    {
	return "";
    }
    string all="";
    string data="";

    for (unsigned int current=0; current<roster.size(); current++)
    {
        if (current == roster.size()-1) // use only when final name on list is reached so no comma is appended
        {
            roster.at(current, data);
            all=all+data;
        }
        else
        {
            roster.at(current, data); // concatenate current name to the list string and then append a comma
            all=all+data+",";
        }
    }
    return all;
}

string Classroom::removeAlphabeticallyFirst()
{
    string data;
    string temp;  // temp holds current alphabetically first name
    unsigned int pos; // pos tracks position of where current "first" name is
    if (roster.size() != 0) // first name by default is alphabetically first at this point
    {
	roster.at(0, data);
    }
    temp=data;
    pos=0;
    for (unsigned int i=1; i<roster.size(); i++) // go through all names on list
    {
        roster.at(i, data);
        if (data < temp)    // checks to see if current data value comes before temp
        {
           temp=data;
           pos=i;
        }
    }
    data=temp;
    roster.remove(pos,data); // alphabetically first name is then removed from vector
    return data;
}

string Classroom::removeAlphabeticallyLast()
{
    string data;
    string temp; // holds current "last"
    unsigned int pos; //tracks position of "last" name
    if (roster.size() != 0) // first name on list becomes "last" by default
    {
	roster.at(0, data);
    }
    temp=data;
    pos=0;
    for (unsigned int i=1; i<roster.size(); i++) // cycles through each element in vector
    {
        roster.at(i, data);
        if (data > temp)    // if current data value comes after current temp, temp is updated
        {
           temp=data;
           pos=i;
        }
    }
    data=temp;
    roster.remove(pos,data); // alphabetically last name is removed from vector
    return data;
}

void Classroom::combineClasses(Classroom& otherClass)
{
    string data;
    for (unsigned int i=0; i<otherClass.roster.size(); i++) // goes through each element of 2nd class
    {
        otherClass.roster.at(i, data);  // data takes value of current index position
        this->roster.insert(data);      // data is added to the vector using the vector's insert function
    }
}
