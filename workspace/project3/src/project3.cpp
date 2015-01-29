//============================================================================
// Name        : project3.cpp
// Author      : Brett Nicholas
// Description : Driver Program created for ENGS 65 project 3
//============================================================================

#include <iostream>
#include "SparceMatrix.h"
using namespace std;

int main() {
	SparceMatrix* cities = new SparceMatrix(6); // create new sparce matrix

	// Print Matrix
	cities->printMatrix();
	std::cout << endl;

	// Query Distance Between Atlanta and Boston to make sure they are equal
	int dist1 = cities->getElement(0,1);
	int dist2 = cities->getElement(1,0);
	std::cout << dist1 << " should = " << dist2 << endl << endl;


	// Reset distance between City and Verify
	cities->setCity(); // reset
	cities->printMatrix(); // verify

	return 0;
}
