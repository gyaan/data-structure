#include<iostream>
#include<vector>
using namespace std;

class Link {
public:
	int data;
	Link * next;
	Link(int value) {
		data = value;
		next = NULL;
	}
};

class stackADT {

public:
	Link *head;
	stackADT() {
		head = NULL;
	}

	void push(int value) {
		Link * newLink = new Link(value);
		if (head == NULL) {

			head = newLink;

		} else {
			Link * current = head;
			while (current->next != NULL){
				current = current->next;
			}
			current->next = newLink;
		}
	}

	void pop() {
		if (head == NULL) {
			cout << "stack is empty";
		} else {
			Link * current = head;
			Link *prev;
			while (current->next != NULL) {
				prev = current;
				current = current->next;
			}
			prev->next = NULL;
			delete (current);
		}
	}

	void display() {
		Link *current = head;
		while (current != NULL) {
			cout << current->data << "-->";
			current = current->next;
		}
	}
};

int main() {
	stackADT stack;
	stack.push(12);
	stack.push(13);
	stack.push(14);
	stack.push(15);
	stack.push(16);
	stack.push(17);
	stack.push(18);
	stack.display();
	stack.pop();
	stack.pop();
	cout<<"after pop-->>";
	stack.display();
	return 0;
}
