/*
 * MyFuncArray.h
 *
 *  Created on: Feb 10, 2015
 *      Author: bretttt
 */

#ifndef MYFUNCARRAY_H_
#define MYFUNCARRAY_H_
#define SIZE 10

namespace std {

class MyFuncArray {
	protected:
		int vals[SIZE];
		int contains(int ind);
		int indMap(int ind);
		bool validateInd(int ind);

	public:
		MyFuncArray(int vals[SIZE]);
		void setVal(int ind, int val); // set value at position
		int& operator[] (const int& ind);

};

} /* namespace std */

#endif /* MYFUNCARRAY_H_ */
