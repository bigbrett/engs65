/*
 * SparceMatrix.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: bretttt
 */

#include "SparceMatrix.h"
#include <iostream>
#include <vector>

namespace std {

/* Constructor */
SparceMatrix::SparceMatrix(int n) {
	this->N = n;
	this->array_len = n*(n+1)/2;
	this->vecMatrix.reserve(N); // reserve memory for N vector slots
}


/* Copy constructor */
SparceMatrix::SparceMatrix(const SparceMatrix& other) {
	this->N = other.N;
	this->array_len = other.array_len;
	this->vecMatrix = other.vecMatrix;
}


/* Destructor */
SparceMatrix::~SparceMatrix() {
}


/* returns element at (i,j) */
int SparceMatrix::getElement(int i, int j) {
	return vecMatrix[ vectorize(i,j) ]; // get element at i,j
}


/* sets element at (i,j). Returns 0 if successful, returns -1 if fail */
int SparceMatrix::setElement(int i, int j, int val) {
	int ind = vectorize(i,j); // find index of i,j in vector
	vecMatrix[ind] = val; // set new value
	return 0;
}


/* prints vector in "matrix" form - row major */
void SparceMatrix::printMatrix() {
	for (int i=0; i<N; i++) { // loop through rows
		for (int j=0; j<N; j++) { // loop through columns
			std::cout << getElement(i,j) << "  "; // space between elements
			if (j % (N-1) == 0 && j>1) // carriage return every N elements
				std::cout << endl;
		}
	}
}


/* helper method to transform SYMMETRIC matrix indices into vector index
 * Params: (i,j) matrix coordinates
 * returns: vector index
 */
int SparceMatrix::vectorize(int i, int j) {
	int ind;
	if (i <= j)
		ind = (i * N) - ((i - 1) * i)/2 +( j - i);
	else
		ind = (j * N) - ((j - 1) * j)/2 +( i - j);
	return ind;
}




} /* namespace std */
