## Assignment 1 - UniqueVector and Classroom

This repository contains classes which make use of dynamic memory allocation in order to create a flexible method for organizing data. In order to get started using these classes, one must use the 4 included files within this repository - UniqueVector.h, UniqueVector.cpp, Classroom.h, Classroom.cpp. The .h files contain the interfaces of their respective classes and the .cpp ones implement how the functions perform their tasks. This yields two separate classes: UniqueVector and CLassroom. UniqueVector can be used without Classroom, but Classroom can't be used without UniqueVector. It would be difficult to understand the functionality of the Classroom data type without first understanding the UniqueVector data type, so that is where to begin.

UNIQUEVECTOR:
UniqueVector is a templated class which, as its name implies, stores elements of any data type with one condition: if that same element is already contained in the UniqueVector object, it will not be added to the UniqueVector object - preserving its "uniqueness". Located within the UniqueVector.h file in the public section exists all of the class functionality. This functionality consists of primarily boolean functions which provide a wide range of services like telling how many elements are currently in the vector (size), telling how much space is currently allocated for the vector (capacity), adding new elements to the vector, and even removing a single or all of the elements that currently exist in it. When a new UniqueVector object is created, it by default contains 0 elements with an allocated memory of 3 by means of the constructor function and when an object is destroyed, the destructor function deallocates the memory used. However, the backbone of this class lies in the existence of T * structure, or a templated pointer to an array which is located in the private section. This array is where the actual elements are held. When any member function needs to add, access, or remove an element, structure must be gone through. In order for the vector to keep track of its current status, 2 private data members called sizeV and maxsize contain the size and capacity of the vector, respectively. Any changes, whether it be adding or removing elements, causes these varaibles to update so changes are reflected. If a situation would occur where adding 1 more element would exceed the capacity of the vector, the vector is resized to twice its current capacity and then adds the element. This is abstracted away from the user by a private createCopy() function being called automatically when the vector is about to experience a capacity overload. createCopy() actually creates a new array of twice the capacity of the old one, copies all of the elements from the smaller array into the bigger one, and then adds the new element. The removal functions are performed by shifting over the chosen element and overwriting the element with the value of its neighbor. The method of enforcing the "uniqueness" of the vector exists in the insert and push_front functions. Before the new element is added, these functions first check to make sure the candidate element does not already exist in the vector. If it already exists, it will cause the function to end, thereby preventing duplication of elements. Furthermore, the == operator is overloaded to see if one UniqueVector object contains the same elements in the same order as the other one does.

Sample of creating a UniqueVector object: UniqueVector<string> Test
***A UniqueVector object containing an array of strings named "Test" has been created.


CLASSROOM:
The Classroom data type seems to have less functionality than the UniqueVector class on face value. Classroom allows users to store a list of student names (or more generally, strings). It has 7 functions in total, all public. They allow the user to add a student to the Classroom, remove a student, check to see if a name is on the list, return a string containing all the names in the class, or even combine the current Classroom object with a different Classroom object. Its only private member is UniqueVector<string> roster. Therefore, this class makes use of a UniqueVector object. All of the member functions of Classroom actually make use of roster's intrinsic functionality, so many of them simply return a roster function call. For example, the addStudent function consists of nothing more than: return roster.insert(name)

Sample of creating a Classroom object: Classroom Test
***Test is a Classroom object which has a UniqueVector<string> object named "roster".


COMPILING ON LINUX PLATFORM:
Refer to the 4 needed files at the beginning of this README. Make sure that all 4 of them and your main.cpp are in the same directory. If the user wants to ONLY use the UniqueVector class, it is sufficient to do:

g++ UniqueVector.cpp main.cpp -o UVtest

(where main.cpp must have #include "UniqueVector.h" and UVtest is your executable to be ran)

If the user also wants to use Classroom, it is necessary to do:

g++ Classroom.cpp main.cpp -o Ctest

(where main.cpp must have #include "Classroom.h" and Ctest is your executable to be ran)
