/*
 * SocialNetwork
 *
 * A C++ class representing a social network, where vertices are people, and edges
 * are connections (friendships).
 * * Built on top of an Adjacency map graph
 * Created on: Feb 16, 2015
 *
 * Author: Brett Nicholas
 *
 */
#include "AdjacencyMapGraph.h"

namespace std {

class SocialNetwork: public AdjacencyMapGraph {
		/******************************************************************/
		/* Profile:
		 * a nested class to represent someone's (a vertex's) social media profile
		 *
		 * Every person in represented by a vertex
		 * Their connections are represented by edges
		 *
		 */
		class Profile {
			private:
				Vertex owner; // the owner of any given profile
				vector<Edge> connections; // people you might know
				vector<Vertex> friends; // people you are friends with
				vector<Vertex> family; // your family
				vector<string> interests; // things you like to do
				vector<string> music; // music you like
				vector<PICTURE_t> photos; // uploaded photos (assuming PICTURE_t exists)
				vector<string> job; // your job
				//TODO: MANY MANY MORE ..... I COULD GO ON ALL DAY

			public:

				Profile(); // default constructor

				/* Constructor for Profile, with the person and personal info passed as Vertex object */
				Profile(Vertex person) {
					this->owner = person;
					/*
					 * all instance variables would be intitialized
					 * through user I/O
					 *
					 */
				}

				/* Getter/Setter Methods
				 * NOTE: THESE ARE SELF EXPLANATORY SO METHOD BODIES REMAIN UNDEFINED
				 */
				const vector<Edge>& getConnections() const;
				void setConnections(const vector<Edge>& connections);
				const vector<Vertex>& getFriends() const;
				void setFriends(const vector<Vertex>& friends);
				const vector<string>& getInterests() const;
				void setFamily(const vector<Vertex>& family);
				const vector<Vertex>& getFamily() const;
				void setInterests(const vector<string>& interests);
				const vector<string>& getJob() const;
				void setJob(const vector<string>& job);
				const vector<string>& getMusic() const;
				void setMusic(const vector<string>& music);
				const Vertex& getOwner() const;
				void setOwner(const Vertex& owner);
				vector<PICTURE_t> getPhotos() const;
				void setPhotos(vector<PICTURE_t> photos);
		};
		/********************** END class Profile *************************************/

	private:
		Profile	myProfile; // the vertex that represents the user
		vector<Profile> everyone; // A vector containing every profile on the social network
		map<string, Vertex> name2vertex; // a hash map connecting string names to their corresponding Vertex objects
		map<Vertex, Profile> vertex2profile; // a hash map connecting Vertex objects (people) to their profiles

	public:

		/* adds a profile to the social network */
		void addProfile(Profile person) {
			Vertex v = person.getOwner();
			this->insertVertex(v); // add person to social network
			this->insertEdges(v.getIncidentEdges()); // update friends
			// add <name, vertex> pair to name2vertex map
			// add <vertex, Profile> to vertex2Profile map
		}


		/* removes profile from social network */
		void removeProfile(Profile person) {
			// remove vertex from vertex list
			// remove edge from edge list
			// erase map entries
			// Free memory with destructors
		}


		/* Finds a profile based on the person's name */
		Profile findProfile(string name) {
			Vertex targetVert = name2vertex.find(name);
			return vertex2profile.find(targetVert);
		}


		vector<Profile> suggestFriends() {
			vector<Profile> pplImightKnow;
			for each (Edge e in myProfile.getIncidentEdges() {
				for each (vertex v in e) {
					Profile prof = vertex2profile.find(v);
					pplImightKnow->add(prof);
				}
			}
			return pplImightKnow;
		}

		vector<Profile> jobConnections() {
			vector<Profile> connections;
			for each friend in myProfile.getFriends() {
				if (friend has job in a similar field )
					connections.add(friend);
			}

			return connections;
		}

};

} /* namespace std */
