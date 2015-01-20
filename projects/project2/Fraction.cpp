/* 	Fraction.cpp
 * 	A fraction class created for project 2
 *	ENGS 65
 *  Created on: Jan 19, 2015
 *  Author: Brett Nicholas
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
	this->num = numerator; // initialize numerator
	this->denom = denominator; // initialize denominator
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
	int num1, den1, temp1, temp2;
	den1 = Fraction::lcm(this->getDenom(), rhs.getDenom()); // find LCM of both denominators
	temp1 = this->num * den1/this->denom; // calculate equivalent fraction1 numerator for LCM
  temp2 = rhs.getNum() * den1/rhs.getDenom(); // calculate equivalent fraction 2 numerator for LCM
  num1 = temp1 + temp2; // add equivalent numerators for LCM
  Fraction *newFrac = new Fraction(num1, den1); // create new fraction object representing sum
  newFrac->reduce(); // reduce new fraction
	return *newFrac; // return fraction
}


/* overloaded - operator for fraction class
 * Params: two fraction objects
 * Returns: new Fraction object difference*/
Fraction& Fraction::operator -(const Fraction& rhs) {
	int num1, den1, temp1, temp2;
		den1 = Fraction::lcm(this->getDenom(), rhs.getDenom()); // find LCM of both denominators
		temp1 = this->num * den1/this->denom; // calculate equivalent fraction1 numerator for LCM
	  temp2 = rhs.getNum() * den1/rhs.getDenom(); // calculate equivalent fraction 2 numerator for LCM
	  num1 = temp1 - temp2; // subtract equivalent numerators for LCM
	  Fraction *newFrac = new Fraction(num1, den1); // create new fraction object representing difference
	  newFrac->reduce(); // reduce new fraction
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
	if (this->denom < 0) { // if denominator < 0 impose convention of no negative denominators
		this->num = this->num * (-1); // reverse sign of numerator
		this->denom = this->denom * (-1); // reverse sign of denominator
	}
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


/* Calculates the greatest common divisor of two integers, using a non-recursive implementation
 * of Euclid's Method
 * 	Params: two integers (a,b)
 * 	Returns: integer GCD */
int Fraction::gcd(int a, int b) {
	int temp;
  while(b != 0) {
  	temp = b; // temporary variable
		b = a%b; // find remainder
		a = temp; // a = b
	}
	return a; // return gcd
}


/* Calculaes the Lowest Common Multiple of two integers, using GCD function
 * 	Params: two integers (a,b)
 * 	Returns: integer LCM*/
int Fraction::lcm(int a, int b) {
	int newDen;
	if (a==0 && b==0) { // if both a and b are 0, no LCM
		return 0;
	} else {
	newDen = Fraction::gcd(a,b); // calculate greatest common denominator
	return (a * b/newDen); // return LCM integer
	}
}


/* Prints string representation of fraction */
void Fraction::toString() {
	std::cout << this->getNum() << "/" << this->getDenom() << " ";
}



