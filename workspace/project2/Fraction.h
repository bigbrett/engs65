/*
 * Fraction.h
 *
 *  Created on: Jan 18, 2015
 *      Author: bretttt
 */

#ifndef FRACTION_H_
#define FRACTION_H_

namespace std {

class Fraction {
private:
	int num; // numerator
	int denom; // denominator

public:
	Fraction(); // constructor
	Fraction(int num, int denom); // overloaded constructor to initialize
	virtual ~Fraction(); // destructor
	int compare(Fraction operand); // compares magnitude with another fraction
	static Fraction reduce(Fraction frac); // reduces a fraction
	static int gcd(int a, int b); // finds greatest common factor between two integers

	/* Operator Overloads */
	Fraction& operator+ (Fraction lhs, const Fraction& rhs);
	Fraction& operator- (Fraction lhs, const Fraction& rhs);
	Fraction& operator* (Fraction lhs, const Fraction& rhs);
	Fraction& operator/ (Fraction lhs, const Fraction& rhs);

	/* Getters and Setters */
	int getDenom() const { return denom; } // get denominator
  void setDenom(int denom) {this->denom = denom;} // set denominator
  int getNum() const { return num; } // get numerator
  void setNum(int num) { this->num = num; } // set numerator
};

} /* namespace std */

#endif /* FRACTION_H_ */
