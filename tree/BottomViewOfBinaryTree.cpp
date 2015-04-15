#include<iostream>
#include<climits>
#include<queue>
#include<map>
using namespace std;
class Node {

public:

	int horizontalHeight;
	int data;
	Node * leftChild;
	Node * rightChild;
	Node(int value) {
		this->data = value;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->horizontalHeight=INT_MAX;
	}

};

class MyTree {

private:Node * root;

public:

	MyTree(Node * myNode) {
		this->root = myNode;
		this->root->horizontalHeight=0;
	}

    void printBottomViewOfBinaryTree(){

         map<int, int>myTrackMap;
         queue<Node*>Q1,Q2;
         Q1.push(this->root);
         myTrackMap[this->root->horizontalHeight]=this->root->data;

         while(!Q1.empty()){

        	 Node *temp = Q1.front();
        	 Q1.pop();
        	 if(temp->leftChild){
        		 myTrackMap[temp->horizontalHeight-1]=temp->leftChild->data;
                 temp->leftChild->horizontalHeight=temp->horizontalHeight-1;
        		 Q2.push(temp->leftChild);
        	 }

        	 if(temp->rightChild){
        		 myTrackMap[temp->horizontalHeight+1]=temp->rightChild->data;
        		 temp->rightChild->horizontalHeight=temp->horizontalHeight+1;
        		 Q2.push(temp->rightChild);
        	 }

        	 if(Q1.empty())
        		 swap(Q1,Q2);

         }

         //print the map elements
         //iterator of a map
         map<int, int>::iterator dis;

         	//display all elements
         	for (dis = myTrackMap.begin(); dis != myTrackMap.end(); dis++) {
         		cout << dis->first<<"-->"<<dis->second<<"\n";
         	}

    }

};

int main(){

    Node * rootNode = new Node(3);
    rootNode->leftChild=new Node(4);
    rootNode->rightChild=new Node(5);

    rootNode->leftChild->leftChild=new Node(6);
    rootNode->leftChild->rightChild=new Node(7);

    rootNode->rightChild->leftChild=new Node(8);
    rootNode->rightChild->rightChild=new Node(9);

    MyTree * t = new MyTree(rootNode);
    t->printBottomViewOfBinaryTree();

	return 0;
}

