/*
 * SocialNetwork.h
 *
 *  Created on: Feb 16, 2015
 *      Author: bretttt
 */

#ifndef SOCIALNETWORK_H_
#define SOCIALNETWORK_H_

#include "AdjacencyMapGraph.h"
#include <Map>
namespace std {

class SocialNetwork: public AdjacencyMapGraph {
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
					 /* Getter/Setter Methods
					  * NOTE: THESE ARE SELF EXPLANATORY SO METHOD BODIES REMAIN UNDEFINED
					  * */
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

				}; // END class Profile

	private:
		Profile	myProfile; // the vertex that represents the user

		public:
			vector<Profile> everyone; // A everybody on the social network

			void createProfile(Vertex newPerson) ;



	/* Profile:
	 * a nested class to represent someone's social media profile
	 *
	 * the owner of the profile is a vertex in the adjacency map, and that
	 * owners' connections are represented by edges
	 *
	 */



};

} /* namespace std */

#endif /* SOCIALNETWORK_H_ */
