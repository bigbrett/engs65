/*
 * Dictionary.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */
/*
 * Dictionary.h
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */
#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 10

namespace std{

/* Default constructor */
Dictionary::Dictionary()
{
	this->keys.reserve(SIZE);
	this->values.reserve(SIZE);
}


/* add value to map */
void Dictionary::add(string key, string value)
{
	this->keys.push_back(key);
	this->values.push_back(value);
}


/* Get position of definition in its array */
int Dictionary::getPos(string key)
{
	vector<string>::iterator iter = keys.begin (); // iterator on array of keys

	// iterate through array of keys to get pointer to end
	while (iter != this->keys.end ()){
		++ iter;
	}

	// get index of key (word) once found, which corresponds to the index of the value (definition)
	iter = find(this->keys.begin (), this->keys.end (), key);
	return distance(keys.begin (), iter);
}


string Dictionary::getDef(string key) {
	string retval;
	int val = Dictionary::getPos(key);
	if (val == SIZE &&  key != keys[val]) {
		retval = "~~ NO ENTRY ~~";
		std::cerr << "ERROR: <" << key << "> is not an entry in Dictionary";
	}
	else
		retval = this->values[val];
	return retval;
}




string Dictionary::operator[] (const string& key) {
	string def = this->getDef(key);
	return def;
}


}
