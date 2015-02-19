/*
 * Vertex.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#include "Vertex.h"

namespace std {

/* Default Constructor */
Vertex::Vertex() {
	/* TODO  populate instance variables */
}

/* Copy Constructor */
Vertex::Vertex(Vertex& oldVertex) {
	/* TODO Copy Constructor Body */
}

Vertex::~Vertex() {
	/* TODO Free relevant items*/
}

/* Returns incident edges as iterable vector */
const vector<Edge>& Vertex::getIncidentEdges() const {
	return incidentEdges;
}

/* sets edges incident on this vertex */
void Vertex::setIncidentEdges(const vector<Edge>& incidentEdges) {
	this->incidentEdges = incidentEdges;
}

/* returns relevant data one would want associated with themselves */
PERSONAL_DATA_t Vertex::getMyData() const {
	return myData;
}

/* Sets data associated with vertex person */
void Vertex::setMyData(PERSONAL_DATA_t myData) {
	this->myData = myData;
}

/* returns name of vertex */
const string& Vertex::getName() const {
	return name;
}

/* sets name of vertex */
void Vertex::setName(const string& name) {
	this->name = name;
}

/* gets position in Graph's vertex list */
int Vertex::getPosition() const {
	return position;
}

/* sets position in Graph's vertex list */
void Vertex::setPosition(int position) {
	this->position = position;
}



} /* namespace std */
