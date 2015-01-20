/*
 * 	Fraction.h
 * 	A class template header file for Fraction.cpp
 *	Project 2, ENGS 65
 *  Created on: Jan 19, 2015
 *  Author: Brett Nicholas
 */

#ifndef FRACTION_H_
#define FRACTION_H_
using namespace std;

class Fraction {
private:
	int num; // numerator
	int denom; // denominator

public:
	Fraction(); // constructor
	Fraction(int num, int denom); // overloaded constructor to initialize
	int compare(Fraction operand); // compares magnitude with another fraction
	void reduce(); // reduces a fraction using Euclids method
	static int gcd(int a, int b); // finds greatest common factor between two integers
	static int lcm(int a, int b); // finds lowest common multiple between two integers
	void toString(); // prints fraction to stdout

	/* Operator Overloads */
	Fraction& operator +(const Fraction& rhs); // overload addition
	Fraction& operator -(const Fraction& rhs); // overload subtraction
	Fraction& operator *(const Fraction& rhs); // overload multiplication
	Fraction& operator /(const Fraction& rhs); // overload division

	/* Get/Set functions */
	int getDenom() const;
	void setDenom(int denom);
	int getNum() const;
	void setNum(int num);
};


#endif /* FRACTION_H_ */
