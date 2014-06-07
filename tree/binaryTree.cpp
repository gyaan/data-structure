#include<iostream>
#include<climits>
#include<queue>
#include<stack>
#include<list>
#include<string>
#include<map>
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

		//if root node is null
		if (rootNode == NULL)
			return 0;
		else {
			if (rootNode->val == value) { //if root node value is equal to search key ::yes found
				return 1;
			} else {
				bool temp = tree::FindAElementInTheTree(rootNode->leftChild,
						value); //check search key in left child
				if (temp != 0)  //yes found no need to check in right child
					return 1;
				else
					tree::FindAElementInTheTree(rootNode->rightChild, value); //need to check in right child
			}
		}

	}

	static treeNode* FindAElementInTheTreeAndReturnThatNode(treeNode *rootNode, int value) {

		//if root node is null
		if (rootNode == NULL)
			return NULL;
		else {
			if (rootNode->val == value) { //if root node value is equal to search key ::yes found
				return rootNode;
			} else {
				treeNode *temp = tree::FindAElementInTheTreeAndReturnThatNode(rootNode->leftChild,
						value); //check search key in left child
				if (temp != NULL)  //yes found no need to check in right child
					return temp;
				else
					tree::FindAElementInTheTreeAndReturnThatNode(rootNode->rightChild, value); //need to check in right child
			}
		}

	}




	static bool FindAElementInTheTreeWithoutRecursion(treeNode *rootNode,
			int value) {

		queue<treeNode *> Q;

		//add root node in the queue
		Q.push(rootNode);

		while (!Q.empty()) {  //run till all the elements not checked
			treeNode * temp = Q.front();  //get the front element form queue
			Q.pop();

			if (temp->val == value) { //if search is equal to front  node value :: yes found
				return 1;
			}
			if (temp->leftChild) //if node have left child add it to queue
				Q.push(temp->leftChild);
			if (temp->rightChild) //if node have right child add it to queue
				Q.push(temp->rightChild);
		}
		return 0; //after traversing complete tree given search key not found

	}

	static int sizeOfBinaryTree(treeNode * rootNode) {

		//size = size of left tree + 1 + size of right tree
		if (rootNode == NULL)
			return 0;
		else
			return sizeOfBinaryTree(rootNode->leftChild) + 1
					+ sizeOfBinaryTree(rootNode->rightChild);

	}

	static int sizeOfBinaryTreeWithoutRecursion(treeNode * rootNode) {
		int count = 0;

		// create a Q which store pointer of treeNode object
		queue<treeNode*> Q;

		//add first element to Q
		Q.push(rootNode);

		while (!Q.empty()) {  //till queue is not empty
			treeNode * temp = Q.front();
			Q.pop();
			count++; //increase count by 1
			if (temp->leftChild) //if node have left child then add it to Q
				Q.push(temp->leftChild);
			if (temp->rightChild)  //if node have right child then add it to Q
				Q.push(temp->rightChild);
		}
		return count; //size of tree
	}

	static void printTheLevelOrderDataInReversOrder(treeNode * rootNode) {

		//define a queue ADT
		queue<treeNode*> Q;
		//define a stack ADT
		stack<treeNode*> St;

		// add root node to Q
		Q.push(rootNode);

		while (!Q.empty()) {  //till queue is not empty

			treeNode * temp = Q.front();
			Q.pop(); //pop top element from queue

			if (temp->rightChild)
				Q.push(temp->rightChild); //traverse the right child of root node
			if (temp->leftChild)
				Q.push(temp->leftChild); //then traverse the left child of root node
			St.push(temp); //add popped element to stack
		}

		//print the tree elements
		while (!St.empty()) {
			treeNode *temp1 = St.top();
			St.pop();
			cout << temp1->val << " ";
		}
	}

	static void printTheLevelOrderDataInZigZagOrder(treeNode * rootNode) {

		int flag = 1; //flag for visit left-->right

		//define a stack ADT
		stack<treeNode*> currentLevel;
		//define a stack ADT
		stack<treeNode*> nextLevel;

		//define a queue to store final elements to display
		queue<treeNode*> Q;

		// add root node to currentLevel
		currentLevel.push(rootNode);

		//till currentLevel stack is not empty
		while (!currentLevel.empty()) {
			treeNode * temp = currentLevel.top();

			if (temp) {
				//add popped element to stack
				Q.push(temp); //you can print this value here also instead of adding to queue
				//pop top element from currentLevel stack
				currentLevel.pop();

				if (flag) {
					if (temp->leftChild)
						//traverse the left child of root node
						nextLevel.push(temp->leftChild);
					if (temp->rightChild)
						//then traverse the right child of root node
						nextLevel.push(temp->rightChild);
				} else {
					if (temp->rightChild)
						//traverse the right child of root node
						nextLevel.push(temp->rightChild);
					if (temp->leftChild)
						//then traverse the left child of root node
						nextLevel.push(temp->leftChild);
				}

				//swap elements from next level to current level if currentLevel stack is empty
				if (currentLevel.empty()) {
					flag = 1 - flag; //flag changed to visit right-->left
					swap(currentLevel, nextLevel); //swap stack values
				}
			}
		}

		//print the tree elements in zigzag order
		while (!Q.empty()) {
			treeNode *temp1 = Q.front();
			cout << temp1->val << " ";
			Q.pop();

		}
	}

	//calculate height of tree using recursion
	static int heightOfBinaryTree(treeNode *rootNode) {

		if (rootNode == NULL)
			return 0;
		else {
			//get the height of left child
			int leftHeight = tree::heightOfBinaryTree(rootNode->leftChild);

			//get the height of right child
			int rightHeight = tree::heightOfBinaryTree(rootNode->rightChild);

			//return max(leftHeight,rightHeight)+1
			if (leftHeight > rightHeight)
				return leftHeight + 1;
			else
				return rightHeight + 1;
		}

	}

	//calculate height of tree without recursion
	static int heightOfBinaryTreeWithoutRecursion(treeNode *rootNode) {
		int height = 0;
		//create queues to store current and next level nodes
		queue<treeNode*> Q1;
		queue<treeNode*> Q2;

		//add top rootNode to Q1
		Q1.push(rootNode);

		while (!Q1.empty()) { //for each level
			treeNode * temp = Q1.front();
			Q1.pop();

			if (temp->leftChild)
				Q2.push(temp->leftChild);

			if (temp->rightChild)
				Q2.push(temp->rightChild);

			if (Q1.empty()) {
				//increase height when move to another level
				height++;
				//swap elements from next level to current level
				swap(Q1, Q2);
			}
		}
		return height; //final height of tree
	}

	//get deepest node in the tree
	static int deepestNodeInTheTree(treeNode *rootNode) {

		treeNode * temp;

		// create two queues to store tree current and next level elements
		queue<treeNode*> Q1;
		queue<treeNode*> Q2;

		Q1.push(rootNode);

		while (!Q1.empty()) { //for each level
			temp = Q1.front();
			Q1.pop();

			if (temp->leftChild)
				Q2.push(temp->leftChild);
			if (temp->rightChild)
				Q2.push(temp->rightChild);

			//swap next level elements to current level
			if (Q1.empty()) {
				swap(Q1, Q2);
			}
		}

		//last node of Q1 will be the deepest node
		return temp->val;
	}

	//count of leaf nodes

	static int countOfLeafNodes(treeNode *rootNode) {

		//create queue to traverse level order
		queue<treeNode *> Q1;

		//define count for leaf nodes
		int count = 0;

		Q1.push(rootNode);
		while (!Q1.empty()) {
			treeNode * temp = Q1.front();
			Q1.pop();

			//count of leafNodes
			if (temp->leftChild == NULL && temp->rightChild == NULL)
				count++;

			//for full nodes
			//if (temp->leftChild != NULL && temp->rightChild != NULL)

			//for half nodes
			//if ((temp->leftChild != NULL && temp->rightChild == NULL) || (temp->leftChild == NULL && temp->rightChild != NULL) )

			if (temp->leftChild)
				Q1.push(temp->leftChild);
			if (temp->rightChild)
				Q1.push(temp->rightChild);

		}
		return count; //final count
	}

	//

	static int countOfLeafNodesUsingRecursion(treeNode *rootNode) {

		//leaf node property
		if (rootNode->leftChild == NULL && rootNode->rightChild == NULL)
			return 1;
		//if both children are not null then get sum of their leaf nodes
		else if (rootNode->leftChild && rootNode->rightChild)
			return (tree::countOfLeafNodesUsingRecursion(rootNode->leftChild)
					+ tree::countOfLeafNodesUsingRecursion(rootNode->rightChild));
		//if right child is null
		else if (rootNode->leftChild)
			tree::countOfLeafNodesUsingRecursion(rootNode->leftChild);
		// if left child is null
		else
			tree::countOfLeafNodesUsingRecursion(rootNode->rightChild);

	}

	//check to binary tree is identical

	static bool isBinaryTreeIdentical(treeNode *rootNode1,
			treeNode *rootNode2) {

		if (rootNode1 == NULL && rootNode2 == NULL)
			return true;
		else if (rootNode1 == NULL || rootNode2 == NULL)
			return false;
		else
			return (rootNode1->val == rootNode2->val
					&& isBinaryTreeIdentical(rootNode1->leftChild,
							rootNode2->leftChild)
					&& isBinaryTreeIdentical(rootNode1->rightChild,
							rootNode2->rightChild));

	}

	static int DaimeterOfBinaryTree(treeNode *rootNode, int *height) {

		int leftHeight;
		int rightHeight;
		if (!rootNode)
			return 0;  //root nod is null diameter will be 0
		else {
			//calculate the diameter of left subTree
			leftHeight = tree::DaimeterOfBinaryTree(rootNode->leftChild,
					height);

			//calculate the diameter of right subTree
			rightHeight = tree::DaimeterOfBinaryTree(rootNode->rightChild,
					height);

			if (leftHeight + rightHeight + 1 > *height)

				//if current node diameter is greater then previous nodes diameter
				*height = leftHeight + rightHeight + 1;

			//current node diameter will max(leftHeight,rightHeight)+1
			int returnValue =
					leftHeight > rightHeight ? leftHeight : rightHeight;

			//current node diameter
			return returnValue + 1;
		}

	}

	static int levelWithMaxSum(treeNode *rootNode) {

		//variable store to level with max sum
		int maxLevel = 0;

		//store the max sum
		int maxSum = 0;

		//temp variables
		int tempSum = 0;
		int tempLevel = 0;

		//queues to store current and next level nodes
		queue<treeNode*> Q1;
		queue<treeNode*> Q2;

		Q1.push(rootNode);
		while (!Q1.empty()) {
			treeNode * temp = Q1.front();
			Q1.pop();
			tempSum = tempSum + temp->val;

			if (temp->leftChild) {
				Q2.push(temp->leftChild);
			}
			if (temp->rightChild) {
				Q2.push(temp->rightChild);
			}

			if (Q1.empty()) {
				tempLevel++;  //increase levels
				//if current level sum is greater then max sum
				if (tempSum > maxSum) {
					maxSum = tempSum;
					maxLevel = tempLevel;
				}
				//swap Queues element next level to current level
				swap(Q1, Q2);
				//again set tempsum to zero
				tempSum = 0;
			}
		}
		//final max level
		return maxLevel;
	}

	static void printLeafNodePathFromRoot(treeNode *rootNode, int path[],
			int pathLength) {

		if (rootNode == NULL)  //if root node is null
			return;

		path[pathLength] = rootNode->val; //add root node value to path array
		pathLength++; //increase the path length by 1

		//if root node is a leaf node then print path from root to that node
		if (rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
			//printArray is function which just print the array values
			printArray(path, pathLength);
			cout << endl;
		}
		//if root node is not leaf node
		else {

			//call function for left child
			if (rootNode->leftChild)
				tree::printLeafNodePathFromRoot(rootNode->leftChild, path,
						pathLength);

			//call function for right child
			if (rootNode->rightChild)
				tree::printLeafNodePathFromRoot(rootNode->rightChild, path,
						pathLength);
		}

	}

	static bool hasPathWithGivenSum(treeNode *rootNode, int sum) {

		// if we check complete tree and sum is zero  then return true
		if (rootNode == NULL)
			return (sum == 0);

		//remaining sum
		int remainingSum = sum - rootNode->val;

		// if root node have both child or both are null i.e. leaf Node
		if ((rootNode->leftChild && rootNode->rightChild)
				|| (!rootNode->leftChild && !rootNode->rightChild)) {

			return (hasPathWithGivenSum(rootNode->leftChild, remainingSum)
					|| hasPathWithGivenSum(rootNode->rightChild, remainingSum));

			//if right child is null
		} else if (rootNode->leftChild)
			return hasPathWithGivenSum(rootNode->leftChild, remainingSum);

		//if left child is null
		else
			return hasPathWithGivenSum(rootNode->rightChild, remainingSum);

	}

	static int sumOfAllBinaryTreeElements(treeNode *rootNode) {

		if (rootNode == NULL)
			return 0;
		else
			return sumOfAllBinaryTreeElements(rootNode->leftChild)
					+ rootNode->val
					+ sumOfAllBinaryTreeElements(rootNode->rightChild);

	}

	static int printAllAncestorsOfANode(treeNode *rootNode, treeNode * givenNode) {

		if (rootNode == NULL)
			return 0;
		if (rootNode->leftChild == givenNode
				|| rootNode->rightChild == givenNode
				|| printAllAncestorsOfANode(rootNode->leftChild, givenNode)
				|| printAllAncestorsOfANode(rootNode->rightChild, givenNode))
		{
			cout<< rootNode->val << "  ";
			return 1;
		}
		return 0;

	}


	void static printArray(int arr[], int length) {

		for (int i = 0; i < length; i++)
			cout << arr[i] << " ";

	}

};

int main() {
	tree T, T2;
	T.insert(1);
	T.insert(2);
	T.insert(3);
	T.insert(4);
	T.insert(5);
	T.insert(6);
	T.insert(7);
	T.insert(8);
	T.insert(9);
	T.insert(10);
	T.insert(11);
	T.insert(12);
	T.insert(13);
	T.insert(14);

//add elements in T2

	T2.insert(1);
	T2.insert(2);
	T2.insert(3);
	T2.insert(4);

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

//size of tree

	cout << "size of tree is " << tree::sizeOfBinaryTree(T.getRootNode());
	cout << endl;
	cout << "again size of tree is "
			<< tree::sizeOfBinaryTreeWithoutRecursion(T.getRootNode());

	cout << endl;
//display elements in order level (reverse order)
	tree::printTheLevelOrderDataInReversOrder(T.getRootNode());
	cout << endl;

	tree::printTheLevelOrderDataInZigZagOrder(T.getRootNode());
	cout << endl;

	cout << "Height of Tree: " << tree::heightOfBinaryTree(T.getRootNode());
	cout << endl;

	cout << "Again Height of Tree: "
			<< tree::heightOfBinaryTreeWithoutRecursion(T.getRootNode());
	cout << endl;

	cout << "deepest node of tree: "
			<< tree::deepestNodeInTheTree(T.getRootNode());
	cout << endl;

	cout << "count of leaf nodes " << tree::countOfLeafNodes(T.getRootNode());
	cout << endl;

	cout << "again count of leaf nodes "
			<< tree::countOfLeafNodesUsingRecursion(T.getRootNode());
	cout << endl;

	bool test = tree::isBinaryTreeIdentical(T.getRootNode(), T2.getRootNode());
	if (test)
		cout << "Yes man both binary trees are identical enjoy !!! ";
	else
		cout << "No man both binary trees are not identical so sad !!! ";

	cout << endl;
	int height = 0;
	tree::DaimeterOfBinaryTree(T2.getRootNode(), &height);
	cout << "Diameter of Binary Tree:" << height;

	cout << endl;
	int maxLevelAndSum = tree::levelWithMaxSum(T.getRootNode());

	cout << "Max sum level is: " << maxLevelAndSum;
	cout << endl;
	int a[100];

	tree::printLeafNodePathFromRoot(T.getRootNode(), a, 0);

	bool aa = tree::hasPathWithGivenSum(T.getRootNode(), 15);
	if (aa)
		cout << "yes! there is path for given sum";
	else
		cout << "No! there is no path for given sum";

	cout << endl;
	cout << "sum of all elements: "
			<< tree::sumOfAllBinaryTreeElements(T2.getRootNode());

	cout << endl;

	//print all ancestors of node

	//first get that node ex. want to find 10th node ancestors
	treeNode *givenNode = tree::FindAElementInTheTreeAndReturnThatNode(T.getRootNode(),10);

	//now print all ancestors of node
	tree::printAllAncestorsOfANode(T.getRootNode(), givenNode);

	cout<<endl;
	return 0;
}
