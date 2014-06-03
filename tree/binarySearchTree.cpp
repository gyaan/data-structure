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

	static bool findAElelentInBinarySearchTree(treeNode * rootNode, int value) {

		//if root node itself is null
		if (rootNode == NULL)
			return 0;
		//if given value is equal to root Node value
		if (rootNode->val == value)
			return 1;
		else {
			if (rootNode->val > value)
				tree::findAElelentInBinarySearchTree(rootNode->leftChild,
						value);
			if (rootNode->val < value)
				tree::findAElelentInBinarySearchTree(rootNode->rightChild,
						value);
		}

	}

	static bool findAElelentInBinarySearchTreeWithoutRecursion(
			treeNode *rootNode, int value) {

		if (rootNode == NULL)
			return 0;
		while (rootNode) {

			if (rootNode->val == value)
				return 1;
			if (rootNode->val > value)
				rootNode = rootNode->leftChild;
			else
				rootNode = rootNode->rightChild;
		}

		return 0;

	}

	treeNode* getRootNode() {
		return this->root;
	}

};

int main() {
//	tree* T = new tree();
	tree T;
	T.insertValue(17);
	T.insertValue(12);
	T.insertValue(3);
	T.insertValue(40);
	T.insertValue(5);
	T.insertValue(90);
	T.insertValue(70);
	T.insertValue(28);
	T.insertValue(19);
	T.insertValue(10);

	cout << "inorder traverse" << endl;
	string traversType = "in";
	T.traverse(traversType);

	cout << "pre order traverse" << endl;
	traversType = "pre";
	T.traverse(traversType);

	cout << "post order traverse" << endl;
	traversType = "post";
	T.traverse(traversType);

	cout << "check if given value is in the tree or not" << endl;

	bool aa;
	aa = tree::findAElelentInBinarySearchTree(T.getRootNode(), 90);

	if (aa)
		cout << "yes found \n";
	else
		cout << "not found \n";

	bool bb ;
	bb= tree::findAElelentInBinarySearchTreeWithoutRecursion(T.getRootNode(),10);

	if (bb)
			cout << "Again yes found \n";
		else
			cout << "Again not found \n";

	return 0;
}

