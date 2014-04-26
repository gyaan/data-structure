/*
 * queue.cpp
 * Created on: 19-Apr-2014
 * Author: Gyaneshwar Pardhi
 */
#include<iostream>
#include<vector>
using namespace std;

class Queue{

private:
	int maxSize;
	vector<int>queVector;
	int front;
	int rear;
	int nItems;
public:

	Queue(int size){
		this->front = 0;
		this->rear  = -1;
		this->nItems =0;
		this->maxSize = size;
		this->queVector.reserve(size);

	}
	void enQueue (int j){
		if (this->rear == this->maxSize-1){
			this->rear = -1;
		}
		this->queVector[++this->rear]=j;
		this->nItems++;
	}

	int deQueue(){
		int temp = this->queVector[this->front++];
		if(this->front==this->maxSize)
			this->front = 0;
		this->nItems--;
		return temp;
	}
	int peek(){
		return this->queVector[this->front];
	}

	bool isEmpty(){
	return (this->nItems==0);
	}
	bool isFull(){
		return (this->nItems==this->maxSize);
	}

	int size(){
		return this->nItems;
	}

};

int main(){
	//create object of queue class
	Queue theQueue(10);

	//lets insert some elements
	theQueue.enQueue(10);
	theQueue.enQueue(20);
	theQueue.enQueue(30);
	theQueue.enQueue(40);

	//lets delete some elements from queue
//	theQueue.deQueue();
//	theQueue.deQueue();
//	theQueue.deQueue();

	//let again insert some elements in queue
	theQueue.enQueue(50);
	theQueue.enQueue(60);
	theQueue.enQueue(70);
	theQueue.enQueue(80);
	theQueue.enQueue(90);
	theQueue.enQueue(100);
	theQueue.enQueue(110);
		theQueue.enQueue(120);
		theQueue.enQueue(130);
		theQueue.enQueue(140);

	//display queue elements
	while(!theQueue.isEmpty()){
		int n = theQueue.deQueue();
		cout<<n<<" ";
	}

	return 0;
}
