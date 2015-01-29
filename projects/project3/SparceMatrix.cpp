/*
 * SparceMatrix.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: bretttt
 */

#include "SparceMatrix.h"
#include <iostream>
#include <iomanip>
#include <vector>

namespace std {
	const string SparceMatrix::city_list[6] = {"ATL", "BOS", "CHI", "DET", "LA", "NY"}; // list of cities as strings
	const int SparceMatrix::initVals[] = {0, 1108,  708,  756, 2191,  854, // initialized matrix
																							0,  994, 1753, 3017,  222,
																										0,  279, 2048,  809,
																													0, 2288,  649,
																																0, 2794,
																																		 0};
/* Constructor */
SparceMatrix::SparceMatrix(int n) {
	this->N = n;
	this->array_len = n*(n+1)/2;
	this->vecMatrix = new int[n]; // reserve memory for N vector slots
	int ind = 0;
	for (int i=0; i<n; i++) { // initialze matrix
			for (int j=0; j<n; j++) {
				if (j >= i) {
					this->setElement(i,j, SparceMatrix::initVals[ind]);
					ind++;
				}
			}
		}
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
	string sp = " ";
	std::cout << "\t";
	for (int i=0; i<N; i++)
		std::cout << left << setw(10) << this->city_list[i];
	std::cout << endl;
	for (int i=0; i<N; i++) { // loop through rows
		std::cout << left << setw(8) << SparceMatrix::city_list[i];
		for (int j=0; j<N; j++) { // loop through columns
			std::cout << left << setw(4) << getElement(i,j) << "      "; // space between elements
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

/* User IO to set a distance between two cities */
void SparceMatrix::setCity() {
	int usr1, usr2, dist = 0;
	for (int i=0; i<this->N; i++)
			std::cout << SparceMatrix::city_list[i] << " (" << i << ")" << endl;
	std::cout << "Chose first city by selecting its number > " << endl;
	std::cin >> usr1;
	std::cout << "City 1 = " << SparceMatrix::city_list[usr1] << endl << endl;
	for (int i=0; i<this->N; i++)
				std::cout << SparceMatrix::city_list[i] << " (" << i << ")" << endl;
  std::cout << "Chose second city by selecting its number > " << endl;
	std::cin >> usr2;
	std::cout<< "City 2 = " << SparceMatrix::city_list[usr2] << endl << endl;
	std::cout << "Chose new distance between " << SparceMatrix::city_list[usr1] << " and " << SparceMatrix::city_list[usr2] << endl;
	std::cin >> dist;
	SparceMatrix::setElement(usr1, usr2, dist);
	std::cout << "Success! " << city_list[usr1] << "-->" << city_list[usr2] << " = " << SparceMatrix::getElement(usr1,usr2) << endl;
}

} /* namespace std */

