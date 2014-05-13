/*
 * stack using linkList
 */
#include<map>
using namespace std;

//Node
class Node {

public:
	int value;
	Node * next;
	Node(int val) {
		this->value = val;
		this->next = NULL;
	}

};

class Stack {

	Node *head;
public:
	Stack() {
		this->head = NULL;
	}

	void push(int val) {
		Node *newNode = new Node(val);
		newNode->next = this->head;
		this->head = newNode;
	}

	int pop() {
		Node * temp;
		temp = this->head;
		this->head = this->head->next;
		int returnValue = temp->value;
		delete(temp);
		return returnValue;

	}

	Node* headOftheLinkList() {
		return this->head;
	}

	bool isEmopty() {
		return (this->head == NULL);
	}

};
