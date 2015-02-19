/*
 * postfixSolver.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */

#ifndef POSTFIXSOLVER_H_
#define POSTFIXSOLVER_H_
#include "StackDLL.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/*
 *
 */
class postfixSolver {
	public:

		vector<string> eqn; // vector to hold postfix expression
		void printEqn();
		StackDLL<string> myStack; // stack
		postfixSolver();
		postfixSolver(vector<string>& eqn); // give it an equation
		virtual ~postfixSolver();
		float eval(); // equation solver


};


#endif /* POSTFIXSOLVER_H_ */
