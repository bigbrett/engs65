/*
 * StackDLL.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */

#ifndef STACKDLL_H_
#define STACKDLL_H_
#include <iostream>


namespace std {

/*
 *
 */
template <typename T>
class StackDLL {
		/* Node in the DLL */
		struct Node {
				T data; // data held in node
				Node* next;
				Node* prev;
				Node(T data);
				Node(T data, Node* n, Node* p); // constructor

				T getData(); // gets data
				Node* getNext(); // gets node's next member
				Node* getPrev(); // gets previous member
				void setData(T data);
		}; // struct Node

	private:
		Node* head; // pointer to head of DLL
		Node* tail; // pointer to tail of DLL
		int size; // size of list

	public:
		StackDLL() {
			this->head = NULL;
			this->tail = NULL;
			this->size = 0;;
		}
		~StackDLL() {
			while (head) {
				Node* temp(head);
				head=head->next;
				delete temp;
			}
		}


		void add(T data); // adds new node to DLL holding data of type T
		void remove(); // removes current element from list
		bool empty() const;
		operator bool() const { return !empty(); } // checks if empty
//};

//} /* namespace std */

template<typename T>
inline StackDLL<T>::Node::Node(T data)
{
	this->data = data;
	this->next = this->prev = NULL; // set next and previous pointers to NULL

}

template<typename T>
inline StackDLL<T>::Node::Node(T data, Node* n, Node* p)
{
	this->data = data;
	this->next = n;
	this->prev = p;
}

/*
 * Returns Data at node
 */
template<typename T>
inline T StackDLL<T>::Node::getData()
{
	return this->data;
}

/*
 * returns next pointer of a given node
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::Node::getNext()
{
	return this->next;
}

/*
 * returns previous pointer of a given node
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::Node::getPrev()
{
	return this->prev;
}

/*
 * Sets data of a node
 */
template<typename T>
inline void StackDLL<T>::Node::setData(T data)
{
	this->data = data;
}

/*
 * adds a new node holding data to the DLL
 */
template<typename T>
inline void StackDLL<T>::add(T data)
{
	// create new node and make it tail
	Node* node = new Node(data);


	// If list is empty, both head/tail point to new element
	if ( this->empty() ) {
		this->head = node;
		this->tail = node;
		node->prev = NULL; // update previous to null
	}

	else {
		node->prev = tail; // if not empty, previous = tail
	}

	this->tail = node; // update DLL tail pointer
	this->size++; // increment size
}


/*
 * removes node from DLL
 */
template<typename T>
inline void StackDLL<T>::remove()
{
	if (! empty() ) {
		tail = tail->prev; // previous element becomes new tail
		tail->next = NULL;
	}
}

/*
 * checks if DLL is empty
 */
template<typename T>
inline bool StackDLL<T>::empty() const
{
	return ( !head || !tail );
}




#endif /* STACKDLL_H_ */
};
}
