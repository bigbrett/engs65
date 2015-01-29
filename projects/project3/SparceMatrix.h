/*
 * SparceMatrix.h
 *
 *  Created on: Jan 27, 2015
 *      Author: bretttt
 */

#ifndef SPARCEMATRIX_H_
#define SPARCEMATRIX_H_
#include <vector>
namespace std {

class SparceMatrix {
	private:
		int N; // number of dimensions of symetric NxN matrix
		int array_len; // numner of elements in array
		static const string city_list[6];
		static const int initVals[24];
		int* vecMatrix ;
public:
		enum CITY_t {ATL=0, BOS=1, CHI=2, DET=3, LA=4, NY=5};
//		int* vecMatrix ;
/* Constructors/Destructors */
		SparceMatrix(int n=0);
		SparceMatrix(const SparceMatrix& other); // copy constructor
		virtual ~SparceMatrix(); // destructor
/* Getters/Setters */
		/* get array length */
		int getArrayLen() const {
			return array_len;
		}
		/* get Matrix Dimensions */
		int getN() const {
			return N;
		}
		/* get reference to the vector representation of matrix */
		int* getVecMatrix() const {
			return vecMatrix;
		}
/* Member functions */
		int getElement(int i, int j); // returns value at i,j
		int setElement(int i, int j, int val); // sets value at i,j
		void printMatrix(); // prints matrix
		int vectorize(int i, int j); // maps matrix indices to vector index
		void setCity(); // sets a city value with user I/O

};

} /* namespace std */

#endif /* SPARCEMATRIX_H_ */
