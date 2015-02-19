/*
 * AdjacencyMapGraph.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */
#include "AdjacencyMapGraph.h"

namespace std {

/* Default constructor */
AdjacencyMapGraph::AdjacencyMapGraph() {
	// TODO Default constructor body
}

/* Copy Constructor */
AdjacencyMapGraph::AdjacencyMapGraph(AdjacencyMapGraph& oldGraph) {
	// TODO Copy constructor body
}

AdjacencyMapGraph::~AdjacencyMapGraph() {
	// TODO Default destructor body
}

/* returns vector containing all edges in graph */
const vector<Edge>& AdjacencyMapGraph::getEdges() const {
	return edges;
}

/* allows for new edge list to be imported */
void AdjacencyMapGraph::setEdges(const vector<Edge>& edges) {
	this->edges = edges;
}

/* returns vector containing all vertices in graph */
const vector<Vertex>& AdjacencyMapGraph::getVertices() const {
	return vertices;
}

/* allows for new vertex list to be imported */
void AdjacencyMapGraph::setVertices(const vector<Vertex>& vertices) {
	this->vertices = vertices;
}

} /* namespace std */
