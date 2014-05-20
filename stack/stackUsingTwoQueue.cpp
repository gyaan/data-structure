#include<iostream>
//include queue std;

#include<queue>
using namespace std;

//define stack ADT
class Stack {

	queue<int> Q1;
	queue<int> Q2;

public:

	// add elements in stack
	void push(int value) {
		if (this->Q1.empty()) {
			this->Q2.push(value);
		} else {
			this->Q1.push(value);
		}

	}

	//pop elements from stack
	int pop() {
		//move size-1 elements from non empty queue to empty queue
		if (this->Q2.empty()) {
			int size = Q1.size();
			int i = 0;
			while (i < size - 1) {
				int temp = Q1.front();
				Q2.push(temp);
				Q1.pop();
				i++;
			}

			int temp2 = Q1.front();

			//pop nth element from non empty queue
			Q1.pop();

			//return nth element from non empty queue
			return temp2;
		} else { //move size-1 elements from non empty queue to empty queue

			int size = Q2.size();
			int i = 0;
			while (i < size - 1) {
				int temp = Q2.front();
				Q1.push(temp);
				Q2.pop();
				i++;
			}

			int temp2 = Q2.front();

			//pop nth element from non empty queue
			Q2.pop();

			//return nth element from non empty queue
			return temp2;
		}

	}

	bool isEmpty() {

		//if any of the queue is empty means stack is empty
		if (Q1.empty() && Q2.empty())
			return 1;
		else
			return 0;
	}

	int top() {

		//move n-1 elements from non empty to empty queue
		if (this->Q2.empty()) {
			int size = Q1.size();
			int i = 0;
			while (i < size - 1) {
				int temp = Q1.front();
				Q2.push(temp);
				Q1.pop();
				i++;
			}
			int temp2 = Q1.front();

			//add nth element to empty queue
			Q2.push(temp2);
			Q1.pop();

			//return nth element
			return temp2;

		} else { //move n-1 elements from non empty to empty queue
			int size = Q2.size();
			int i = 0;
			while (i < size - 1) {
				int temp = Q2.front();
				Q1.push(temp);
				Q2.pop();
				i++;
			}
			int temp2 = Q2.front();

			//add nth element to empty queue
			Q1.push(temp2);
			Q2.pop();

			//return nth element
			return temp2;
		}
	}
};

int main() {

	Stack st;

	//add some elements to stack
	st.push(23);
	st.push(24);
	st.push(25);
	st.push(26);
	st.push(27);

	//pop elements froms stack
	cout << st.pop();
	cout << st.pop();

	//display top of stack
	cout << st.top();

	//again add some elements to stack
	st.push(28);
	st.push(29);

	//display top
	cout << st.top();

	//again pop elements from stack
	cout << st.pop();
	cout << st.top();

	return 0;
}
