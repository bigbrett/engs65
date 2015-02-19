/*
 * postfixSolver.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */

#include "postfixSolver.h"
#define SIZE 5
#define DEBUG 0

postfixSolver::postfixSolver()
{
	this->eqn.push_back("3");
	this->eqn.push_back("4");
	this->eqn.push_back("+");
	this->eqn.push_back("2");
	this->eqn.push_back("*");
}

postfixSolver::postfixSolver(vector<string>& eqn)
{
	this->eqn = eqn;
}


postfixSolver::~postfixSolver()
{
}

/*
 * Prints equation vector
 */
void postfixSolver::printEqn()
{
	for( std::vector<string>::const_iterator i = this->eqn.begin(); i != this->eqn.end(); ++i)
		std::cout << *i << ' ';
	std::cout <<endl;
}


/*
 * Solves vector equation of postfix notation
 */
float postfixSolver::eval()
{
	float ans = -1;

	// iterate through input vector
	std::vector<string>::const_iterator i = this->eqn.begin();

	// push first item onto the stack
	StackDLL<string>::Node node = StackDLL<string>::Node(*i); // dummy node
	string x = node.getData(); // string data
	myStack.push(x);
	myStack.printStack();
	i++;

	while ( i != this->eqn.end()) {
		// get item from equation vector
		node = StackDLL<string>::Node(*i); // dummy node
		string x = node.getData(); // string data
		if (DEBUG) std::cout << "x = " << x << endl;


		// if item is operator, pop twice and evaluate expression
		//		if ((x. == "+") || (x == "-") || (x == "*") || (x == "/")) {
		if ((x.compare("+") == 0) || (x.compare("-") == 0) || (x.compare("*") == 0) || (x.compare("/") == 0) ) {

			// pop and convert to float
			float a = std::stof(myStack.pop()->getData());
			float b = std::stof(myStack.pop()->getData());

			if (DEBUG) std::cout << "a = " << a << "   b = " << b << endl;

			// evaluate expression and push the result back onto stack as a string
			if(x == "+" )
				myStack.push(to_string(a+b));
			else if (x == "-")
				myStack.push(to_string(b - a));
			else if (x == "*")
				myStack.push(to_string(b * a));
			else if (x == "/")
				myStack.push(to_string(b / a));

		}
		else {
			// not operator so push value onto stack
			myStack.push(x);
			if (DEBUG) std::cout << "push-->" << x << endl;
		}

		this->myStack.printStack();

		// if only one element left in stack
		if (myStack.getSize() == 1) {
			string sAns = myStack.getTail()->getData();
			ans = std::stof(sAns); // convert to string
			if (DEBUG) std::cout << "ans = " << ans << endl;
		}
		++i; // increment iterator
	}
	return ans;
}


