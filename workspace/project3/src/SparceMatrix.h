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

//	protected:
		vector<int> vecMatrix; // create vector of length N


	public:
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
		const vector<int>& getVecMatrix() const {
					return vecMatrix;
				}

		/* Member functions */
		int getElement(int i, int j); // returns value at i,j
		int setElement(int i, int j, int val); // sets value at i,j
		void printMatrix(); // prints matrix
		int vectorize(int i, int j); // maps matrix indices to vector index


};

} /* namespace std */

#endif /* SPARCEMATRIX_H_ */
