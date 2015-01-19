/*
 * Fraction.h
 *
 *  Created on: Jan 18, 2015
 *      Author: bretttt
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

	/* Operator Overloads */
	Fraction& operator +(const Fraction& rhs);
	Fraction& operator -(const Fraction& rhs);
	Fraction& operator *(const Fraction& rhs);
	Fraction& operator /(const Fraction& rhs);

	/* Get/Set functions */
	int getDenom() const;
	void setDenom(int denom);
	int getNum() const;
	void setNum(int num);
};


#endif /* FRACTION_H_ */
