/*
 * DLLdriver.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */
#include "postfixSolver.h"
#include <iostream>


/*
 * Driver for StackDLL.h
 */
int main(void) {

	/* create vectorized equation (could be done with I/O
	 * I just chose to hardcode for simplicity)
	 */
	std::vector<string> equation;
	equation.push_back("3");
	equation.push_back("4");
	equation.push_back("+");
	equation.push_back("2");
	equation.push_back("*");
	equation.push_back("4");
	equation.push_back("-");

	// create new solver object
	postfixSolver solver(equation);

	// print equation
	std::cout << "EQUATION 1: "; solver.printEqn();

	// evaluate and display result
	float ans = solver.eval();
	std::cout << "ANSWER 1 = " << ans << endl << endl << endl;


	// repeat for new equation
	equation.clear();
	equation.push_back("3");
	equation.push_back("5");
	equation.push_back("*");
	equation.push_back("2");
	equation.push_back("+");
	equation.push_back("0.5");
	equation.push_back("/");
	postfixSolver solver2(equation);
	std::cout << "EQUATION 2: "; solver2.printEqn();
	ans = solver2.eval();
	std::cout << "ANSWER 2= " << ans << endl;


	return 0;
}



