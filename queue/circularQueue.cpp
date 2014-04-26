#include<iostream>
#include<vector>
using namespace std;

class CircularQueue {

private:
	int front, rear, maxSize;
	vector<int> queElements;

public:
	CircularQueue(int size) {
		this->front = this->rear = -1;
		this->maxSize = size;
		this->queElements.reserve(size);
	}

	void enQueue(int value) {
		if (this->isFull()) {
			cout << "queue is overflow";
		} else {
			this->rear = (this->rear + 1) % this->maxSize;
			this->queElements[this->rear] = value;
			if (this->front == -1)
				this->front = this->rear;
		}
	}

	int deQueue() {

		if (this->isEmpty()) {
			cout << "Queue is Empty";
			return 0;
		} else {
			int data = this->queElements[this->front];
			if (this->front == this->rear)
				this->front = this->rear = -1;
			else
				this->front = (this->front + 1) % this->maxSize;
			return data;
		}
	}

	int size() {
		return (this->maxSize - this->front + this->rear + 1) % this->maxSize;
	}

	bool isEmpty() {
		return (this->front == -1);
	}

	bool isFull() {
		return ((this->rear + 1) % this->maxSize == this->front);
	}

};

int main() {

	CircularQueue theQueue(10);
//lets play with queue

 //arrange some elements
	theQueue.enQueue(10);
	theQueue.enQueue(20);
	theQueue.enQueue(30);
	theQueue.enQueue(40);
	theQueue.enQueue(50);
	theQueue.enQueue(60);

	//remove some elements
	theQueue.deQueue();
	theQueue.deQueue();
	theQueue.deQueue();

	//add some elements
	theQueue.enQueue(70);
	theQueue.enQueue(80);
	theQueue.enQueue(90);
	theQueue.enQueue(100);
	theQueue.enQueue(110);
	theQueue.enQueue(120);

	cout << "size Of Queue :" << theQueue.size() << endl;

	while (!theQueue.isEmpty()) {
		int de = theQueue.deQueue();
		cout << de << endl;
	}
	return 0;
}

