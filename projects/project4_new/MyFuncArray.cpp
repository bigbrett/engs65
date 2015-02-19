/*
 * MyFuncArray.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */

#include "MyFuncArray.h"
#include <iostream>
#include <cmath>
namespace std {

MyFuncArray::MyFuncArray(int vals[SIZE])
{
	for (int i=0; i<SIZE; i++) {
		this->vals[i] = vals[i];
	}
}

bool MyFuncArray::validateInd(int ind) {
	// test for valid index
	bool flag;

	if (ind < SIZE) { // if index is within array size
		if (ind % 2 == 0 && ind < 0) { // if even but negative --> error
			flag = false;
		}
		else if (ind % 2 != 0 && ind > 0) {// if odd but positive --> error
			flag = false;
	}
		else // else valid input
			flag = true;
	}
	else {
		flag = false;
	}

	return flag;
}

/* get index from mapping function */
int MyFuncArray::indMap(int ind)
{
	int retval;
	if (MyFuncArray::validateInd(ind)) {
		retval = ind * pow(-1, ind);
	}
	else {
		std::cerr << "ERROR: index <" << ind << "> is not a valid index" << endl;
		retval = -1;
	}

	return retval;
}


/* Set a value */
void MyFuncArray::setVal(int ind, int val)
{
	this->vals[MyFuncArray::indMap(ind)] = val;
}


/* Overload operator */
int& MyFuncArray::operator [](const int& ind)
{
	int val = -1; // default return value = error

	// check position value for validity
	int pos = MyFuncArray::indMap(ind);
	if (pos == -1)
		std::cout << "ERRONEOUS INDEX <" << ind << "> RETURNS VALUE OF ";
	else
		val = this->vals[MyFuncArray::indMap(ind)];

	return (int &)val;
}


} /* Namespace std */
