#include<iostream>
#include<string>
#include<climits>
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
				return tree::findAElelentInBinarySearchTree(rootNode->leftChild,
						value);
			if (rootNode->val < value)
				return tree::findAElelentInBinarySearchTree(
						rootNode->rightChild, value);
		}

	}

	static treeNode* findAElelentInBinarySearchTreeAndReturn(
			treeNode * rootNode, int value) {

		//if root node itself is null
		if (rootNode == NULL)
			return NULL;
		//if given value is equal to root Node value
		if (rootNode->val == value)
			return rootNode;
		else {
			if (rootNode->val > value)
				return tree::findAElelentInBinarySearchTreeAndReturn(
						rootNode->leftChild, value);
			if (rootNode->val < value)
				return tree::findAElelentInBinarySearchTreeAndReturn(
						rootNode->rightChild, value);
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

	static int findMinElementInTheBinaryTree(treeNode *rootNode) {

		if (rootNode->leftChild == NULL)
			return rootNode->val;
		else
			return tree::findMinElementInTheBinaryTree(rootNode->leftChild);

	}

	static int findMinElementInTheBinaryTreeWithoutRecursion(
			treeNode *rootNode) {

		while (true) {

			if (rootNode->leftChild == NULL)
				return rootNode->val;
			else
				rootNode = rootNode->leftChild;
		}

	}

	static int findMaxElementInTheBinaryTree(treeNode *rootNode) {
		if (rootNode->rightChild == NULL)
			return rootNode->val;
		else
			return tree::findMaxElementInTheBinaryTree(rootNode->rightChild);
	}

	static int findMaxElementInTheBinaryTreeWithoutRecursion(
			treeNode * rootNode) {
		while (true) {

			if (rootNode->rightChild == NULL)
				return rootNode->val;
			else
				rootNode = rootNode->rightChild;
		}

	}

	static treeNode* deleteAElementInBinarySearchTree(treeNode *rootNode,
			int value) {

		if (rootNode == NULL) //if given tree rootNode itself is null
			cout << "Given rootNode itself is null";

		// if given node value is less then current rootNode Value
		else if (rootNode->val > value)
			rootNode->leftChild = tree::deleteAElementInBinarySearchTree(
					rootNode->leftChild, value);

		// if given node value is greater then current rootNode Value
		else if (rootNode->val < value)
			rootNode->rightChild = tree::deleteAElementInBinarySearchTree(
					rootNode->rightChild, value);
		else {  //we got the node

			//if given node have both children
			if (rootNode->leftChild && rootNode->rightChild) {

				//find max element in left subTree
				int temp = tree::findMaxElementInTheBinaryTree(
						rootNode->leftChild);

				//replace given node value to max value
				rootNode->val = temp;

				//again call same function for left subTree
				rootNode->leftChild = tree::deleteAElementInBinarySearchTree(
						rootNode->leftChild, rootNode->val);

			}

			//if given node is a leaf node
			else if (!rootNode->leftChild && !rootNode->rightChild) {
				rootNode = NULL;
			}

			//if given node have only one child node
			else {

				//if given node have leftChild
				if (rootNode->leftChild != NULL)
					rootNode = rootNode->leftChild;

				//if given node have rightChild
				if (rootNode->rightChild != NULL)
					rootNode = rootNode->rightChild;

			}

		}

		return rootNode;

	}

	static treeNode * lowestCommonAncestorOfGivenTwoNodes(treeNode *rootNode,
			treeNode *node1, treeNode *node2) {
		if (rootNode == NULL)
			return NULL;

		//always node2 value should greater then node1
		if (node1->val > node2->val) {
			treeNode* temp = node1;
			node1 = node2;
			node2 = temp;
		}

		while (1) {

			//yes we got LCA of node1 n node2
			if (node1->val < rootNode->val && node2->val > rootNode->val)
				return rootNode;
			//if current node value is less then both n1 and n2 value
			//means LCA will be in right subtree
			else if (node1->val > rootNode->val && node2->val > rootNode->val)
				rootNode = rootNode->rightChild;

			//if current node value is greater then both n1 and n2 value
			//means LCA will be in left subtree
			else
				rootNode = rootNode->leftChild;

		}

	}

	static bool isItBinarySearchTree(treeNode *rootNode) {

		//if root node is null then its bst
		if (rootNode == NULL)
			return 1;
		//if rootNode left child value is gr8 then root node value
		if (rootNode->leftChild != NULL
				&& rootNode->val < rootNode->leftChild->val)
			return 0;
		//if rootNode rightChild value is less then the root node value
		if (rootNode->rightChild != NULL
				&& rootNode->val > rootNode->rightChild->val)
			return 0;

		// check left and right children should also be bst
		if (!tree::isItBinarySearchTree(rootNode->leftChild)
				|| !tree::isItBinarySearchTree(rootNode->rightChild))
			return 0;

		//after traversing all nodes
		return 1;

	}

	static bool isItBinarySearchTreeUsingMinAndMax(treeNode *rootNode) {

		//if rootNode is null means its BST
		if (rootNode == NULL)
			return 1;

		//if rootNode value is less then max value in left subtree
		if (rootNode->leftChild != NULL
				&& rootNode->val
						< tree::findMaxElementInTheBinaryTree(
								rootNode->leftChild))
			return 0;

		//if rootNode value is greater then min value in right subtree
		if (rootNode->rightChild != NULL
				&& rootNode->val
						> tree::findMinElementInTheBinaryTree(
								rootNode->rightChild))
			return 0;

		//check for left and right children
		if (!tree::isItBinarySearchTreeUsingMinAndMax(rootNode->leftChild)
				|| !tree::isItBinarySearchTreeUsingMinAndMax(
						rootNode->rightChild))
			return 0;

		// after checking all nodes
		return 1;
	}

	static bool isItBinarySearchTreeUsingInOrderTraversal(treeNode *rootNode,
			int *min) {

		//if rootNode is null means it's BST
		if (rootNode == NULL)
			return 1;

		//check left child is BST or not
		if (!tree::isItBinarySearchTreeUsingInOrderTraversal(
				rootNode->leftChild, min))
			return 0;

		//check current node value if less then return 0
		if (rootNode->val < *min)
			return 0;

		//assign current node value to min
		*min = rootNode->val;

		//check right child is BST or not
		if (!tree::isItBinarySearchTreeUsingInOrderTraversal(
				rootNode->rightChild, min))
			return 0;

		return 1;
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
	aa = tree::findAElelentInBinarySearchTree(T.getRootNode(), 76);

	if (aa)
		cout << "yes found \n";
	else
		cout << "not found \n";

	bool bb;
	bb = tree::findAElelentInBinarySearchTreeWithoutRecursion(T.getRootNode(),
			10);

	if (bb)
		cout << "Again yes found \n";
	else
		cout << "Again not found \n";

	cout << "minimum Element in the bst "
			<< tree::findMinElementInTheBinaryTree(T.getRootNode());
	cout << endl;

	cout << "minimum Element in the bst Again "
			<< tree::findMinElementInTheBinaryTreeWithoutRecursion(
					T.getRootNode());
	cout << endl;

	cout << "maximum Element in the bst "
			<< tree::findMaxElementInTheBinaryTree(T.getRootNode());
	cout << endl;

	cout << "maximum Element in the bst Again "
			<< tree::findMaxElementInTheBinaryTreeWithoutRecursion(
					T.getRootNode());
	cout << endl;

//delete a node have value 19
	tree::deleteAElementInBinarySearchTree(T.getRootNode(), 19);

//check 19 is deleted or not
	cout << "inorder traverse" << endl;

	T.traverse("in");

//get to nodes from tree and find LCA of those two node

	treeNode* n1 = tree::findAElelentInBinarySearchTreeAndReturn(
			T.getRootNode(), 40);
	treeNode* n2 = tree::findAElelentInBinarySearchTreeAndReturn(
			T.getRootNode(), 5);
	cout << endl;

	treeNode* lca = tree::lowestCommonAncestorOfGivenTwoNodes(T.getRootNode(),
			n1, n2);

	cout << "lca of " << n1->val << " and " << n2->val << " is " << lca->val;

	cout << endl;

	cout << "check given tree is binary tree or not" << endl;

	int min = INT_MIN;

	bool check = tree::isItBinarySearchTreeUsingInOrderTraversal(
			T.getRootNode(), &min);
	if (check)
		cout << "Yes given tree is binary search tree";
	else
		cout << "No given tree is not binary search tree";

//lets make bst to non bst

	n1->val = 7;

	cout << endl;

	int minAgain = INT_MIN;
	bool checkAgain = tree::isItBinarySearchTreeUsingInOrderTraversal(
			T.getRootNode(), &minAgain);
	if (checkAgain)
		cout << "Yes given tree is binary search tree";
	else
		cout << "No given tree is not binary search tree";

	cout << endl;
//make it again bst for future use
	n1->val = 40;

	return 0;
}

