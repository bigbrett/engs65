/*
 * Fraction.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: bretttt
 */

#include "Fraction.h"
#include <cmath>

namespace std {

Fraction::Fraction() {
	this->num = 0;
	this->denom = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	this->num = numerator;
	this->denom = denominator;
}

/* Compares fraction object to operand fraction
 * returns 1 if this > operand
 * returns 0 if this == operand
 * returns -1 if this < operand */
int Fraction::compare(Fraction operand) {
	int flag = 0; // flag to determine relative magnitude
	double num1 = (double)operand.getNum(); // operand numerator
	double den1 = (double)operand.getDenom(); // operand denominator
	double thisRatio = abs( (double)(this->num)/(double)(this->denom)); // take ratio of THIS
	double opRatio = abs(num1 / den1); // take ratio of operand

	if (thisRatio > opRatio) {
		flag = 1;
	} else if (thisRatio < opRatio) {
		flag = -1;
	};
	return flag;
}


Fraction& operator+ (Fraction lhs, const Fraction& rhs) {
	Fraction newFrac = new Fraction(lhs.getNum() + rhs.getNum(), lhs.getDenom()+rhs.getDenom());
	return *(Fraction::reduce(newFrac));
}

Fraction& operator- (Fraction lhs, const Fraction& rhs) {
	Fraction newFrac = new Fraction(lhs.getNum()-rhs.getNum(), lhs.getDenom()-rhs.getDenom());
	return *(Fraction::reduce(newFrac));
}

Fraction& operator* (Fraction lhs, const Fraction& rhs) {
	Fraction newFrac = new Fraction(lhs.getNum()*rhs.getNum(), lhs.getDenom()*rhs.getDenom());
	return *(Fraction::reduce(newFrac));
}

Fraction& operator/ (Fraction lhs, const Fraction& rhs) {
	Fraction newFrac = new Fraction(lhs.getNum()*rhs.getDen(), lhs.getDenom()*rhs.getNum());
	return *(Fraction::reduce(newFrac));
}

Fraction Fraction::reduce(Fraction frac) {

}

} /* namespace std */
