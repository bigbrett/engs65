//============================================================================
// Name        : project3.cpp
// Author      : Brett Nicholas
// Description : Created for ENGS 65 project 3
//============================================================================

#include <iostream>
#include "SparceMatrix.h"
//#include "DistanceMatrix.h"
using namespace std;

int main() {
	// prompt user for size of matrix
	std::cout << "size of array > " << endl;
	int n;
	std::cin >> n;

	SparceMatrix* cities = new SparceMatrix(); // create new sparce matrix

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j >= i) {
				std::cout << "enter values for (" << i << "," << j << ") " << endl;
				int val;
				std::cin >> val;
				cities->setElement(i,j,val);
			}
		}
	}


	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			std::cout << "(" << i << "," << j << "): " << cities->getElement(i,j) << endl;
		}
	}


	cities->printMatrix();



	return 0;
}
