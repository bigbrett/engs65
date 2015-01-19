/*
 * main.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: bretttt
 */
#include "Fraction.h"
#include <cstdlib>
#include <iostream>

using namespace std;


int main () {
	Fraction *frac1 = new Fraction(6,4);
	Fraction *frac2 = new Fraction(5,20);

	std::cout << frac1->getNum();
	return 0;
}





