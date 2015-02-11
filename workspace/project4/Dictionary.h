/*
 * Dictionary.h
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <string>
#include <vector>

namespace std {

class Dictionary {
	private:
		vector<string> keys;
		vector<string> values;
		int getPos(string key);
		string getDef(string key);

	public:
		Dictionary();
		string operator[] (const string& key);
		void add(string key, string value);

};

} /* namespace std */

#endif /* DICTIONARY_H_ */
