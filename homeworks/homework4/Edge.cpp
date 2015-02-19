/*
 * Edge.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#include "Edge.h"

namespace std {

/* Default constructor */
Edge::Edge() {
	// TODO default constructor body
}

Edge::~Edge() {
	// TODO default destructor body
}

Edge::Edge(Edge& oldEdge) {
	// TODO default copy constructor
}

/* Returns whatever data structure is held in edge */
EDGE_DATA_t Edge::getEdgeData() const {
	return edgeData;
}

/* sets whatever data structure is held in edge */
void Edge::setEdgeData(EDGE_DATA_t edgeData) {
	this->edgeData = edgeData;
}

/* returns vertices on opposite ends of this edge as 2-member vector */
const vector<Vertex>& Edge::getEndpoints() const {
	return endpoints;
}

/* Sets vertices on both sides of edge */
void Edge::setEndpoints(const vector<Vertex>& endpoints) {
	this->endpoints = endpoints;
}

/* gets string label of edge */
const string& Edge::getLabel() const {
	return label;
}

/* sets string label of edge */
void Edge::setLabel(const string& label) {
	this->label = label;
}

/* returns position of edge in graph's edge list */
int Edge::getPosition() const {
	return position;
}

/* sets position of edge in graphs edge list */
void Edge::setPosition(int position) {
	this->position = position;
}


} /* namespace std */
