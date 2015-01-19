/*
 * Fraction.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: bretttt
 */
#include "Fraction.h"
#include <cmath> // include C math header file
#include <iostream>

/* Default Constructor */
Fraction::Fraction() {
	this->num = 0; // default numerator = 0
	this->denom = 1; // default denominator = 1
}


/* Overloaded parameterized constructor
 * Params: numerator and denominator of object
 * 	DEFAULT VALUES = 0/1
 */
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

	// compare the magnitude of the ratios of both fractions, default=0 implying equal
	if (thisRatio > opRatio) { // if object ratio > operand ratio
		flag = 1; // set flag to 1
	} else if (thisRatio < opRatio) { // else if operand ratio > object ratio
		flag = -1; // set flag to -1
	};
	return flag; // return flag
}


/* overloaded + operator for fraction class
 * Params: two fraction objects
 * Returns: new Fraction object sum */
Fraction& Fraction::operator +(const Fraction& rhs) {
	Fraction *newFrac = new Fraction(this->getNum() + rhs.getNum(), this->getDenom()+rhs.getDenom());
	newFrac->reduce(); // returns new fraction object
	return *newFrac;
}


/* overloaded - operator for fraction class
 * Params: two fraction objects
 * Returns: new Fraction object difference*/
Fraction& Fraction::operator -(const Fraction& rhs) {
	Fraction *newFrac = new Fraction(this->getNum()-rhs.getNum(), this->getDenom()-rhs.getDenom());
	newFrac->reduce(); // returns new fraction object
	return *newFrac;
}


/* overloaded * operator for fraction class
 * Params: two fraction objects
 * Returns: new Fraction object product*/
Fraction& Fraction::operator *(const Fraction& rhs) {
	Fraction *newFrac = new Fraction(this->getNum()*rhs.getNum(), this->getDenom()*rhs.getDenom());
	newFrac->reduce(); // returns new fraction object
	return *newFrac;
}


/* overloaded / operator for fraction class
 * Params: two fraction objects
 * Returns: new Fraction object quotient */
Fraction& Fraction::operator /(const Fraction& rhs) {
	Fraction *newFrac = new Fraction(this->getNum()*rhs.getDenom(), this->getDenom()*rhs.getNum());
	newFrac->reduce(); // returns new fraction object
	return *newFrac;
}


/* Reduces a fraction object using Euclid's method */
void Fraction::reduce() {
	int tempN = this->num;	// store numerator for use as recursive parameter
	this->num = (this->num)/(Fraction::gcd(tempN, this->denom)); // calculate new numerator
	this->denom = (this->denom)/(Fraction::gcd(tempN, this->denom)); // calculate new denominator
}


/* Denominator Getter method
 * Returns int Denominator */
int Fraction::getDenom() const {
	return denom;
}


/* Denominator setter method */
void Fraction::setDenom(int denom) {
	this->denom = denom;
}


/* Numerator Getter method
 * 	returns int numerator */
int Fraction::getNum() const {
	return num;
}


/* Numerator setter method */
void Fraction::setNum(int num) {
	this->num = num;
}


/* Calculaes the greatest common divisor of two integers, using a recursive implementations
 * of Euclid's Method
 * 	Params: two integers (a,b)
 * 	Returns: integer GCD */
int Fraction::gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return Fraction::gcd(b%a, a); // recursive Euclidian method
}
