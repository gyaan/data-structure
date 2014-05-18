/*
 * stack using linkList
 */
#include<map>
using namespace std;

//Node

template<class T>
class Node {

public:
	T value;
	Node * next;
	Node(T val) {
		this->value = val;
		this->next = NULL;
	}

};


template<class DT>
class Stack {

	Node <DT> *head;
public:
	Stack() {
		this->head = NULL;
	}

	void push(int val) {
		Node <DT> *newNode = new Node <DT>(val);
		newNode->next = this->head;
		this->head = newNode;
	}

	int pop() {
		Node <DT> * temp;
		temp = this->head;
		this->head = this->head->next;
		int returnValue = temp->value;
		delete(temp);
		return returnValue;

	}

	Node* headOftheLinkList() {
		return this->head;
	}

	bool isEmpty() {
		return (this->head == NULL);
	}

};
