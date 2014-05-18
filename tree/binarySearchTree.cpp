#include<iostream>
#include<string>
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

//tree ADT

class tree {

public:
	treeNode* root;
	tree() {
		this->root = NULL;
	}

	void insert(treeNode* &Elem, int value) {
		treeNode *newNode = new treeNode(value);
		if (Elem == NULL) {
			Elem = newNode;
		} else if (value < Elem->val) {  // insert at left side
			this->insert(Elem->leftChild, value);
		} else {
			this->insert(Elem->rightChild, value);
		}

	}

	void insertValue(int value) {
		this->insert(this->root, value);
	}

	void preOrderTraversal(treeNode *Elem) {
		if (Elem) {
			cout << Elem->val;
			cout << endl;
			this->preOrderTraversal(Elem->leftChild);
			this->preOrderTraversal(Elem->rightChild);
		}
	}

	void inOrderTraversal(treeNode *Elem) {
		if (Elem) {
			this->inOrderTraversal(Elem->leftChild);
			cout << Elem->val;
			cout << endl;
			this->inOrderTraversal(Elem->rightChild);
		}
	}

	void postOrderTraversal(treeNode *Elem) {
		if (Elem) {
			this->postOrderTraversal(Elem->leftChild);
			this->postOrderTraversal(Elem->rightChild);
			cout << Elem->val;
			cout << endl;
		}
	}

	void traverse(string type = "pre") {
		if (type == "post")
			this->postOrderTraversal(this->root);
		else if (type == "in")
			this->inOrderTraversal(this->root);
		else
			this->preOrderTraversal(this->root);
	}

};

int main() {
	tree* T = new tree();
	T->insertValue(1);
	T->insertValue(2);
	T->insertValue(3);
	T->insertValue(4);
	T->insertValue(5);
	T->insertValue(6);
	T->insertValue(7);
	T->insertValue(8);
	T->insertValue(9);
	T->insertValue(10);

    cout<<"inorder traverse"<<endl;
	string traversType = "in";
	T->traverse(traversType);

	cout<<"pre order traverse"<<endl;
	traversType = "pre";
	T->traverse(traversType);

	cout<<"post order traverse"<<endl;
	traversType = "post";
	T->traverse(traversType);

	return 0;
}

