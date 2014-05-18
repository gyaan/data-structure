#include<iostream>
#include<vector>
using namespace std;

//tree node
class treeNode {
public:
	int val;
	treeNode *leftChild;
	treeNode *rightChild;

	treeNode(int value) {
		val = value;
		leftChild = NULL;
		rightChild = NULL;
	}

};

//queue class
class Queue {

public:
	int maxSize;
	vector<treeNode*> queVector;
	int front;
	int rear;
	int nItems;

	Queue(int size) {
		front = 0;
		rear = -1;
		nItems = 0;
		maxSize = size;
		queVector.reserve(size);

	}
	void insert(treeNode *j) {
		if (rear == maxSize - 1)
			rear = -1;
		queVector[++rear] = j;
		nItems++;
	}

	treeNode* remove() {
		treeNode* temp = queVector[front++];
		if (front == maxSize)
			front = 0;
		nItems--;
		return temp;
	}
	treeNode* peekFront() {
		return queVector[front];
	}

	bool isEmpty() {
		return (nItems == 0);
	}
	bool isFull() {
		return (nItems == maxSize);
	}

	int size() {
		return nItems;
	}

	void deleteQueue() {
		while (!isEmpty()) {
			remove();
		}
	}

};

//tree ADT

class tree {

public:
	treeNode* root;
	tree() {
		this->root = NULL;
	}

	void insertAElement(treeNode* Elem, int value) {
		treeNode *temp;

		//create a Queue
		Queue Q(100);
		treeNode *newNode = new treeNode(value);

		if (!this->root) {
			this->root = newNode;
			return;
		}

		Q.insert(Elem);
		while (!Q.isEmpty()) {
			temp = Q.remove();
			if (temp->leftChild) {
				Q.insert(temp->leftChild);
			} else {
				temp->leftChild = newNode;
				Q.deleteQueue();
				return;
			}

			if (temp->rightChild) {
				Q.insert(temp->rightChild);

			} else {
				temp->rightChild = newNode;
				Q.deleteQueue();
				return;
			}

		}
		Q.deleteQueue();/**/
	}

	void preorderTraversal(treeNode * Elem) {
		if (Elem) {
			cout << Elem->val << endl;
			this->preorderTraversal(Elem->leftChild);
			this->preorderTraversal(Elem->rightChild);
		}
	}
	void inOrderTraversal(treeNode * Elem) {
		if (Elem) {
			this->inOrderTraversal(Elem->leftChild);
			cout << Elem->val << endl;
			this->inOrderTraversal(Elem->rightChild);
		}
	}

	void postOrderTraversal(treeNode * Elem) {
		if (Elem) {
			this->postOrderTraversal(Elem->leftChild);
			this->postOrderTraversal(Elem->rightChild);
			cout << Elem->val << endl;
		}
	}

	void insert(int value) {
		this->insertAElement(this->root, value);
	}

	void travers() {
		this->inOrderTraversal(this->root);
	}

};

int main() {
	tree T;
	T.insert(1);
	T.insert(2);
	T.insert(3);
	T.insert(4);
	T.insert(5);
	T.travers();
	return 0;
}
