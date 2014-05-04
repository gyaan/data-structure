/*
 * stack using linkList
 */
#include<iostream>
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
		return temp->value;

	}

	Node* headOftheLinkList() {
		return this->head;
	}

	bool isEmopty() {
		return (this->head == NULL);
	}


};

int main() {
	Stack s;
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);
	s.push(16);
	s.push(17);
	s.push(18);
	s.push(19);
	s.push(20);
	s.push(21);
    cout<<s.pop()<<"-->";
    cout<<s.pop();
	return 0;
}
