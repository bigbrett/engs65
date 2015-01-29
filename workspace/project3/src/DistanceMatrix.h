/*
 * DistanceMatrix.h
 *
 *  Created on: Jan 28, 2015
 *      Author: bretttt
 */

#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_

#include "SparceMatrix.h"

namespace std {

class DistanceMatrix: public SparceMatrix {
	private:
		enum city_t {Atl, Bos, Chi, Det, LA, NY}; // possible cities

	public:
		DistanceMatrix();
		virtual ~DistanceMatrix();


};

} /* namespace std */

#endif /* DISTANCEMATRIX_H_ */
