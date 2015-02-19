/*
 * AdjacencyMapGraph.h
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#ifndef ADJACENCYMAPGRAPH_H_
#define ADJACENCYMAPGRAPH_H_
#include "Vertex.h"
#include "Edge.h"
#include <map>

namespace std {

class AdjacencyMapGraph {
	protected:
		vector<Vertex> vertices; // list of all vertices in the graph
		vector<Edge> edges; // list of all edges in the graph

	public:
		AdjacencyMapGraph(); // default constructor
		AdjacencyMapGraph(AdjacencyMapGraph& oldGraph); // copy constructor
		virtual ~AdjacencyMapGraph(); // destructor

		/* Getters/Setters */
		const vector<Edge>& getEdges() const;
		void setEdges(const vector<Edge>& edges);
		const vector<Vertex>& getVertices() const;
		void setVertices(const vector<Vertex>& vertices);

		/* Basis methods */
		const vector<Vertex>& getVertex(Vertex V) const; // returns vertex in graph
		const vector<Edge>& getEdge(Vertex V) const; // returns edge in graph
		int numVertices(); // returns number of vertices in graph
		int numEdges(); // returns number of edges in graph
		void insertVertex(Vertex v); // adds a vertex to graph
		void removeVertex(Vertex v); // removes vertex from graph
		void insertEdge(Edge e); // adds Edge to graph
		void removeEdge(Edge e); // removes Edge from graph

};

} /* namespace std */

#endif /* ADJACENCYMAPGRAPH_H_ */
