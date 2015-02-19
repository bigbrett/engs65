/*
 * MyArray.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Brett Nicholas
 */

#ifndef MYARRAY_H_
#define MYARRAY_H_
#define SIZE 10

namespace std {

class MyArray {
	private:
		int indices[SIZE]; // array that holds index values
		int vals[SIZE];


	public:
		MyArray(int arr[SIZE], int vals[SIZE]); // indexed with arr
		int getPosition(int ind);
		void setVal(int ind, int val); // set value at position
		int& operator[] (const int& ind); // overload subscript operator

};

} /* namespace std */

#endif /* MYARRAY_H_ */
