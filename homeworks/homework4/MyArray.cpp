/*
 * MyArray.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */

#include "MyArray.h"
#include <iostream>

namespace std {

/* Constructor that adds each element of a value array and index array to instance arrays */
MyArray::MyArray(int arr[SIZE], int vals[SIZE])
{
	for (int i=0; i<SIZE; i++) {
		this->indices[i] = arr[i];
		this->vals[i] = vals[i];
	}
}


/* get value in value array at position of ind in index array */
int& MyArray::operator[] (const int& ind)
{
	int val = -1; // default = error
	int pos = MyArray::getPosition(ind);

	if (pos == -1)
		std::cout << "ERRONEOUS INDEX <" << ind << "> RETURNS VALUE OF ";
	else
		val = this->vals[pos];

	return (int &)val; //MyArray::vals[pos];
}


/* helper function to get position of ind in index array */
int MyArray::getPosition (int ind)
{
	int pos = -1; // error return
	for (int i=0; i<SIZE; i++) {
		if (MyArray::indices[i] == ind)
			pos = i;
	}

	/* Throw error if desired index does not exists in index array */
	if (pos == -1)
		std::cerr << "ERROR: index <" << ind << "> is not a valid index" << endl;

	return pos;
}


/* set item in value array at position ind in index array */
void MyArray::setVal(int ind, int val)
{
	this->vals[getPosition(ind)] = val;
}


} /* namespace std */
