/*
 * StackDLL.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Brett Nicholas
 */

#ifndef STACKDLL_H_
#define STACKDLL_H_
#define DEBUG1 0
#include <iostream>

using namespace std;

template <typename T>
class StackDLL {
		/*****************************************************
		 Public netsted structure describing Node in list */
	public: struct Node {
		private:
		T data; // data held in node
		Node* next;
		Node* prev;
		public:
		//Node(); // default constructor
		Node(T data); // constructor
		Node(T data, Node* n, Node* p); // constructor
		Node(const Node& node); // copy constructor
		T getData(); // gets data
		void setData(T data); // sets data of node
		Node* getNext(); // gets node's next member
		void setNext(Node* node); // sets a nodes next member
		Node* getPrev(); // gets previous member
		void setPrev(Node* node); // sets data of node

	};
	/*****************************************************/

	protected:
	Node* head; // pointer to head of DLL
	Node* tail; // pointer to tail of DLL
	int size; // size of list

	public:

	StackDLL(); // default constructor
	~StackDLL(); // default destructor

	//		static Node* createNode() {return Node();}  // calls default constructor
	//		static Node* createNode(T data) {return *Node(data);} // calls constructor
	//		static Node* createNode(T data, Node* n, Node* p) {return Node(data, n, p);} // calls constructor
	//		static Node*	createNode(const Node& node) {return Node(node);}  // calls copy constructor

	/* Getter/Setters */
	Node* getHead(); // returns head of list
	Node* getTail(); // returns tail of list
	int getSize(); // returns size of list

	/* Member Functions */
	void push(T data); // adds new node to DLL at tail
	Node* pop(); // removes and returns tail element
	void remove(); // removes tail element from list
	bool empty() const;
	operator bool() const { return !empty(); } // checks if empty
	void printStack(); // prints stack
	void printVals(); // prints values


};


/************************ NODE MEMBER FUNCTIONS **************************/
/*
 * Default constructor for DLL node initializng to NULL
 */
//template<typename T>
//StackDLL<T>::Node::Node()
//{
//	this->data = NULL;
//	this->next = NULL;
//	this->prev = NULL;
//}

/*
 * Constructor for DLL node given only data
 */
template<typename T>
StackDLL<T>::Node::Node(T data)
{
	this->data = data;
	this->next = this->prev = NULL; // set next and previous pointers to NULL

}

/*
 * Constructor for DLL node that initializes next and prev pointers
 */
template<typename T>
StackDLL<T>::Node::Node(T data, Node* n, Node* p)
{
	this->data = data;
	this->next = n;
	this->prev = p;
}

/*
 * Copy constructor
 */
template<typename T>
StackDLL<T>::Node::Node(const Node& node)
{
	this->data = node.data;
	this->next = node.next;
	this->prev = node.prev;
}

/*
 * Returns Data at node
 */
template<typename T>
T StackDLL<T>::Node::getData()
{
	return this->data;
}

/*
 * Sets data of a node
 */
template<typename T>
void StackDLL<T>::Node::setData(T data)
{
	this->data = data;
}

/*
 * returns next pointer of a given node
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::Node::getNext()
{
	if (this->next == NULL)
		if (DEBUG1) std::cout << "NO NEXT NODE" << endl;
	return this->next;
}

/*
 * sets next pointer of a given node
 */
template<typename T>
void StackDLL<T>::Node::setNext(Node* node)
{
	this->next = node;
}

/*
 * returns previous pointer of a given node
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::Node::getPrev()
{
	if (this->prev== NULL)
		if (DEBUG1) std::cout << "NO PREV NODE" << endl;
	return this->prev;
}

/*
 * sets previous pointer of a given node
 */
template<typename T>
void StackDLL<T>::Node::setPrev(Node* node)
{
	this->prev = node;
}
/************************ STACK DLL MEMBER FUNCTIONS **************************/


/* default constructor */
template<typename T>
StackDLL<T>::StackDLL() {
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}


/* default destructor */
template<typename T>
StackDLL<T>::~StackDLL() {
	while (head) {
		Node* temp(head);
		head=head->getNext();
		delete temp;
	}
}


template<typename T>
void StackDLL<T>::printVals() {
	std::cout << "printvals!" << endl;
	if (this->head != NULL && this->tail != NULL) {
		std::cout << head->getData();
		std::cout << "Head: " << head->getData() << " (prev--> " << head->getPrev()->getData() << " (next --> " << head->getNext()->getData() << endl;
		std::cout << "Tail: " << tail->getData() << " (prev--> " << tail->getPrev()->getData() << " (next --> " << tail->getNext()->getData() << endl;
	} else
		std::cout << "MISSING HEAD/TAIL" << endl;
}

/* Prints pretty version of stack */
template<typename T>
void StackDLL<T>::printStack() {
	Node *temp = head; // calls copy constructor
	cout << "STACK (" << this->size << ")" << endl;
	if (! this->empty()) {
		int done = 0;
		while (! done) {
			// print stack member
			cout << "\t" << temp->getData() << endl;

			// when next == null, at end of stack
			if (temp->getNext() == NULL)
				done++;
			else
				temp = temp->getNext();
		}
	} else
		cout << "stack is empty" << endl;
}


/*
 * adds a new node holding data to the DLL
 */
template<typename T>
void StackDLL<T>::push(T data)
{
	// create new node holding data
	Node* node = new Node(data);

	// If list is empty, seat head and tail as new element
	if ( this->empty() ) {
		this->head = node;
		this->tail = node;
		node->setPrev(NULL); // update previous to null
		node->setNext(NULL);
	}
	else {
		node->setPrev(tail); // if not empty, previous = old tail
		node->setNext(NULL); // next = null
		node->getPrev()->setNext(node); // update previous nodes next pointer
		this->tail = node; // update tail pointer
	}

	this->size++; // increment size
}


/*
 * removes and returns tailmost element in DLL
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::pop()
{
	StackDLL<T>::Node *stack_top = this->tail; // get tail element
	this->remove(); // remove tail from the stack
	return stack_top; // return previous tailmost element
}


/*
 * removes tail node from DLL
 */
template<typename T>
void StackDLL<T>::remove()
{
	if (! empty() ) {
		if (tail != head) {
			tail = tail->getPrev(); // previous element becomes new tail
			tail->setNext(NULL);
		} else {
			tail = head = NULL;
			if (DEBUG1) cout << "STACK NOW EMPTY" << endl;
		}
		this->size--; // update size of list
	}
	else
		cout << "STACK IS EMPTY" << endl;
}


/*
 * returns first element in DLL
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::getHead()
{
	return this->head;
}


/*
 * returns tail element in DLL
 */
template<typename T>
typename StackDLL<T>::Node* StackDLL<T>::getTail()
{
	return this->tail;
}


/*
 * returns size of DLL
 */
template<typename T>
int StackDLL<T>::getSize() {
	return this->size;
}


/*
 * checks if DLL is empty
 */
template<typename T>
bool StackDLL<T>::empty() const
{

	if (this->head == NULL && this->tail == NULL)
		return true; //empty
	else
		return false;
}


#endif /* STACKDLL_H_ */

