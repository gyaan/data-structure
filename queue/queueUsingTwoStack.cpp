#include<iostream>

//add stack std
#include<stack>
using namespace std;

// create Queue ADT
class queue {

	//define two stacks
	stack<int> s1;
	stack<int> s2;

public:

	//add elements in queue
	void enQueue(int data) {
		this->s1.push(data);
	}

	//remove elements from queue
	int deQueue() {
		this->shiftStackValues();
		int value = this->s2.top();
		this->s2.pop();
		return value;
	}

	//check if list is empty or not
	bool isEmpty() {
		this->shiftStackValues();
		return this->s2.empty();

	}

	//get the front value of queue
	int front() {
		this->shiftStackValues();
		return this->s2.top();
	}

	//keep in sync s2 with s1
	void shiftStackValues() {
		while (!this->s1.empty()) {
			this->s2.push(this->s1.top());
			this->s1.pop();
		}
	}

};

int main() {

	//create a queue object
	queue Q;

	//add some elements on it
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
	Q.enQueue(5);
	Q.enQueue(6);
	Q.enQueue(7);

	cout<< Q.front();
	//display queue elements
	while(!Q.isEmpty())
	cout << Q.deQueue();

	return 0;
}
