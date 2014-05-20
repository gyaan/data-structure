#include<iostream>
#include<vector>
using namespace std;
class Stack {

private:
	int maxSize;
	vector<double> stackVect;
	int top;
public:
	Stack(int size) {
		this->maxSize = size;
		this->stackVect.reserve(this->maxSize);
		this->top = -1;
	}

	void push(double j) {
		if (!(this->isFull())) {
			this->stackVect[++this->top] = j;
		} else {
			cout << "stack is full";
		}

	}

	double pop() {
		if (!(this->isEmpty())) {
			return this->stackVect[this->top--];
		} else {
			cout << "stack is empty";
		}
	}

	double peak() {
		return this->stackVect[this->top];
	}
	bool isEmpty() {
		return (this->top == -1);
	}

	bool isFull() {
		return (this->top == this->maxSize - 1);
	}

};

int main() {

	//create object of Stack ADT
	Stack theStack(10);

	//push some elements in stack
	theStack.push(10);
	theStack.push(20);
	theStack.push(30);
	theStack.push(40);
	theStack.push(60);

	//pop elements from stack
	while (!theStack.isEmpty()) {
		cout << theStack.pop() << " ";
	}
}
