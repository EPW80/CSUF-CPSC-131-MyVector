# CSUF-CPSC131-MyVector

In this project, I implemented a custom vector class named `MyVector`. This project was done as an assignment for CPSC 131 Data Structures @California State University Fullerton.

## Observation

This is a C++ code for implementing a vector class. A vector is a dynamic array that can be resized easily. Here, a template class "MyVector" is defined with various member functions to implement the vector class.

The class contains a default capacity and a minimum capacity. The constructors are defined to create a vector with a certain capacity. If the capacity is not specified, then the default capacity is used.

The class has various functions for accessing and modifying the elements of the vector. The size function returns the number of elements in the vector. The capacity function returns the maximum number of elements that can be stored in the vector.

The push_back function adds a new element to the end of the vector. If the vector is already full, then the capacity of the vector is increased by a factor of 2. The pop_back function removes the last element from the vector. If the vector is empty, then an error is thrown.

The insert function adds a new element at the specified index in the vector. If the vector is already full, then the capacity of the vector is increased by a factor of 2. The erase function removes an element at the specified index from the vector.

The at function returns the element at the specified index in the vector. If the index is out of range, then an error is thrown. The set function sets the element at the specified index to a new value. If the index is out of range, then an error is thrown.

The reserve function is used to reserve a certain amount of memory for the vector. If the new capacity is less than or equal to the current capacity, then nothing is done. Otherwise, a new array is created with the new capacity and the elements from the old array are copied to the new array. The old array is then deleted and the new array is assigned to the elements pointer.

The copy constructor is used to create a new vector with the same elements as an existing vector. The assignment operator is used to assign one vector to another vector.

The destructor is used to delete the elements of the vector and to deallocate the memory used by the vector.

## Contributor/Student

Erik Williams
