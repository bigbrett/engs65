/*
 * Edge.h
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#ifndef EDGE_H_
#define EDGE_H_
#define "EDGE_DATA_t"
#include <string>
#include <vector>


namespace std {

class Edge {
	protected:
		string label; // string edge label for reference
		vector<Vertex> endpoints; // holds edges on both sides
		int position; // position of this edge in the graph's Adjacency List

		// some complex data structure containing relevant connection data
		EDGE_DATA_t edgeData;

	public:
		Edge();
		Edge(Edge& oldEdge);
		virtual ~Edge();

		/* Getters/Setters */
		EDGE_DATA_t getEdgeData() const;
		void setEdgeData(EDGE_DATA_t edgeData);
		const vector<Vertex>& getEndpoints() const;
		void setEndpoints(const vector<Vertex>& endpoints);
		const string& getLabel() const;
		void setLabel(const string& label);
		int getPosition() const;
		void setPosition(int position);
};

} /* namespace std */

#endif /* EDGE_H_ */
