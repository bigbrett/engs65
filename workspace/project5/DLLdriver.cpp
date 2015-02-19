/*
 * DLLdriver.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */
#include "StackDLL.h"
#include <iostream>

namespace std {

int main(void) {

	StackDLL<string> *mylist = new StackDLL<string>;
	mylist->add("hello!");





	return 0;
}



}
