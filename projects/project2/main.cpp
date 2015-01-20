/*
 * 	main.cpp
 * 	A driver program for Fraction.cpp
 *	Project 2, ENGS 65
 *  Created on: Jan 19, 2015
 *  Author: Brett Nicholas
 */
#include "Fraction.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main () {

	/* create + initialize Fraction objects */
	Fraction *frac1 = new Fraction(1,3); // 1/3
	Fraction *frac2 = new Fraction(4,5); // 4/5
	Fraction *frac3 = new Fraction(); // 0/1
	Fraction *frac4 = new Fraction(); // 0/1

	std::cout << "**** Project 2 test program ****" << endl << endl; // print header

	*frac3 = (*frac1 + *frac2); // add fractions and store in frac 3
	std::cout << "1/3 + 4/5 = "; frac3->toString(); // print answer
	std::cout << endl; // \n

	*frac3 = (*frac1 / *frac2); // divide fractions and store in frac 3
	std::cout << "1/3 / 4/5 = "; frac3->toString(); // print answer
	std::cout << endl; // \n


	/* set new fraction objects */
	frac1->setNum(3); frac1->setDenom(10); // frac1=3/10
	frac2->setNum(4); frac2->setDenom(6); //	frac2=4/6
	frac3->setNum(5); frac3->setDenom(8); // frac3=5/8
	*frac4 = (*frac1 - (*frac2 * *frac3)); // perfor operation
	std::cout << "3/10 - (4/6 * 5/6) = "; frac4->toString(); std::cout << endl; // print result

	frac1->setNum(100); frac1->setDenom(101); // set fraction
	std::cout << "get denominator of 100/101 = " << frac1->getDenom() << endl; // print denominator

	frac1->setNum(50); frac1->setDenom(33); // set fraction
	std::cout << "get numerator of 50/33 = " << frac1->getNum() << endl; // print numerator

	frac2->setNum(100); frac2->setDenom(450); // set fraction
	frac2->reduce(); // reduce fraction
	std::cout << "reduce 100/450 = ";	frac2->toString(); std::cout << endl; // print result

	frac3->setNum(10); frac3->setDenom(11); // set fraction
	frac3->reduce(); // reduce fraction
	std::cout << "reduce 10/11 = "; frac3->toString(); std::cout << endl; // print result


	frac1->setNum(1); frac1->setDenom(2); // set fraction 1
	frac2->setNum(2); frac2->setDenom(4); // set fraction 2
	int flag = frac1->compare(*frac2); // compare two fractions
	std::cout << "is 1/2 equal to 2/4? --> "; // print question
	if (flag == 0) { // if frac1 == frac 2, answer = yes
		std::cout << "yes" << endl; // print yes
	} else {
		std::cout << "no" << endl; // print no
	}


	std::cout << "which is larger? 4/100 or 39/342 ? --> "; // print question
	frac1->setNum(4); frac1->setDenom(100); // set fractions
	frac2->setNum(39); frac2->setDenom(342);
	flag = frac1->compare(*frac2); // compare two fractions

  if (flag == 0) { // fraction 1 == fraction 2
  	std::cout << "Fractions are Equal" << endl; // print question
  } else if (flag > 0) {
  	frac1->toString();  // print fraction 1
  } else {
  	frac2->toString(); // print fraction 2
  }

	return 0;
}





