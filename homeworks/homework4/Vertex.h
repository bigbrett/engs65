/*
 * Vertex.h
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#ifndef VERTEX_H_
#define VERTEX_H_
#define SIZE 1000
#include <vector>
#include <string>
#include "PERSONAL_DATA_t"

namespace std {

class Vertex {
	protected:
		string name; // Person's Name
		vector<Edge> incidentEdges; // Vector containing incident edges (friends)
		int position; // position of this vertex in a graph's adjacency list

		// Some complex data stucture holding all things social media (pictures, etc.)
		PERSONAL_DATA_t myData;

	public:
		/* Constructors/Destructors */
		Vertex();
		Vertex(Vertex& oldVertex); // copy constructor
		virtual ~Vertex();

		/* Getter/Setters */
		const vector<Edge>& getIncidentEdges() const;
		void setIncidentEdges(const vector<Edge>& incidentEdges);
		PERSONAL_DATA_t getMyData() const;
		void setMyData(PERSONAL_DATA_t myData);
		const string& getName() const;
		void setName(const string& name);
		int getPosition() const;
		void setPosition(int position);
};

} /* namespace std */

#endif /* VERTEX_H_ */
