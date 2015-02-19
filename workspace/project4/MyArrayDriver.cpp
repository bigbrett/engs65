/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */
#include <iostream>
#include <iomanip>
#include "MyArray.h"
#include "MyFuncArray.h"
#include "Dictionary.h"

using namespace std;

int main (void) {

	int inds[SIZE] = {12,8,14,-12,6,32,1,9,10,0};
	int func_inds[SIZE] = {0,-1, 2 ,-3, 4, -5, 6, -7, 8, -9};
	int vals[SIZE] = {1,2,3,4,5,6,7,8,9,10};

/* TEST PART 1 */
	MyArray *arr = new MyArray(inds, vals);
	std::cout << "TEST for MyArray : (part 1) : " << endl;

	// print value corresponding to each index in inds array
	for (int i=0; i<SIZE; i++) {
		std::cout << left << " index:" << right << setw(5) << inds[i];
		int foo = (*arr)[inds[i]];
		std::cout << left << "  value: " << right << setw(4) << foo << endl;
	}

	// test input error handling by giving invalid index
	std::cout << (*arr)[132] << endl << endl << endl;


/* TEST PART 2 */
	MyFuncArray *farr = new MyFuncArray(vals);
	std::cout << "TEST for MyFuncArray (part 2) : " << endl;

	for (int i=0; i<SIZE; i++) {
			std::cout << left << " index:" << right << setw(5) << func_inds[i];
			int foo = (*farr)[func_inds[i]];
			std::cout << left << "  value: " << right << setw(4) << foo << endl;
		}

	// test for error if index is invalid
	std::cout << (*farr)[132] << endl << endl << endl;


/* TEST PART 3 */
	string words[SIZE] = {"foo", "bar", "noo", "poo", "GNU", "computer", "beer", "fish", "lol", "Burt's Bees"};
	string defs[SIZE] = {"def_foo", "def_bar", "def_noo", "def_poo", "def_GNU", "def_computer", "def_beer",
											"def_fish", "def_lol", "def_Burt's Bees"};
	Dictionary *dict = new Dictionary();

	//Add word/definition pairs to dictionary
	for (int i=0; i<SIZE; i++) {
		dict->add(words[i], defs[i]);
	}


	// loop through dictionary and print word/definition combos
	for (int i=0; i<SIZE; i++) {
		std::cout << left << setw(6) << "word: " << left << setw(20) << words[i]
		                             << " definition: " << left << setw(40) << (*dict)[words[i]] << endl;
	}


	// Test for errors
	string bad = "ERRONEOUS WORD";
	std::cout << left << setw(6) << "word: " << left << setw(20) << bad
		                             << " definition: " << left << setw(40) << (*dict)[bad] << endl << endl;






	return 0;
}

