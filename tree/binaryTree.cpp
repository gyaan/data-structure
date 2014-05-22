#include<iostream>
#include<climits>
#include<queue>
#include<stack>
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
	treeNode* root;
public:

	tree() {
		this->root = NULL;
	}

	void insertAElement(treeNode* Elem, int value) {
		treeNode *temp;

		//create a Queue
		queue<treeNode*> Q;
		treeNode *newNode = new treeNode(value);

		if (!this->root) {
			this->root = newNode;
			return;
		}

		Q.push(Elem);
		while (!Q.empty()) {
			temp = Q.front();
			Q.pop();
			if (temp->leftChild) {
				Q.push(temp->leftChild);
			} else {
				temp->leftChild = newNode;
				return;
			}

			if (temp->rightChild) {
				Q.push(temp->rightChild);

			} else {
				temp->rightChild = newNode;
				return;
			}

		}
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

	treeNode * getRootNode() {
		return this->root;
	}

	static int maxElementInTheTree(treeNode * rootNode) {

		int root_val, left, right, max = INT_MIN;
		if (rootNode != NULL) {
			root_val = rootNode->val;
			left = tree::maxElementInTheTree(rootNode->leftChild);
			right = tree::maxElementInTheTree(rootNode->rightChild);
			if (left > right)
				max = left;
			else
				max = right;

			if (max < root_val)
				max = root_val;
		}
		return max;
	}

	static int maxElementInTheTreeWithoutRecursion(treeNode* rootNode) {
		int max = INT_MIN;
		queue<treeNode*> Q;

		Q.push(rootNode);
		while (!Q.empty()) {
			treeNode * temp = Q.front();
			Q.pop();
			if (temp->val > max) {
				max = temp->val;
			}
			if (temp->leftChild) {
				Q.push(temp->leftChild);
			}
			if (temp->rightChild) {
				Q.push(temp->rightChild);
			}

		}
		return max;
	}

	static bool FindAElementInTheTree(treeNode *rootNode, int value) {

		if (rootNode == NULL)
			return 0;
		else {
			if (rootNode->val == value) {
				return 1;
			} else {
				bool temp = tree::FindAElementInTheTree(rootNode->leftChild,
						value);
				if (temp != 0)
					return 1;
				else
					tree::FindAElementInTheTree(rootNode->rightChild, value);
			}
		}

	}

	static bool FindAElementInTheTreeWithoutRecursion(treeNode *rootNode,
			int value) {

		queue<treeNode *> Q;
		Q.push(rootNode);

		while (!Q.empty()) {
			treeNode * temp = Q.front();
			Q.pop();

			if (temp->val == value) {
				return 1;
			}
			if (temp->leftChild)
				Q.push(temp->leftChild);
			if (temp->rightChild)
				Q.push(temp->rightChild);
		}

		return 0;

	}

};

int main() {
	tree T;
	T.insert(1);
	T.insert(20);
	T.insert(3);
	T.insert(4);
	T.insert(5);

	//display element
	T.travers();

	//print the max element
//	int value = tree::maxElementInTheTree(T.getRootNode());
	int value = tree::maxElementInTheTreeWithoutRecursion(T.getRootNode());
	cout << "Max. Value in the Tree:" << value;
	cout << endl;

	bool isFind = tree::FindAElementInTheTree(T.getRootNode(), 3);
	if (isFind)
		cout << "yes given element found in the tree.";
	else
		cout << "given element not found in the tree";

	bool isFindWithoutRecursion = tree::FindAElementInTheTreeWithoutRecursion(
			T.getRootNode(), 13);
	cout << endl;

	if (isFindWithoutRecursion)
		cout << "yes again given element found in the tree";
	else
		cout << "given element not found in the tree";
	cout << endl;

	return 0;
}
