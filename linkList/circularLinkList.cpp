/*
 * circularLinkList.cpp
 * Created on: 03-May-2014
 * Author: Gyaneshwar Pardhi
 */

//complete program for circular singly link list
#include<iostream>
#include<map>
using namespace std;

//create a class for Link (Node)
class Link {
public:
	int data;
	Link * next;
	Link(int value) {
		this->data = value;
		this->next = NULL;
	}
};

// class for linkList

class LinkedList {
public:
	Link * head;
	LinkedList() {
		this->head = NULL;
	}
	//insert a value
	void insertAElement(int value, int position) { // insert a element in a given position

		if (position == 1)  //insert value at staring of the linkList
				{
			//create new link
			Link *newlink = new Link(value);
			newlink->next = newlink;

			if (this->head == NULL) {
				this->head = newlink;
			} else {
				Link *current = this->head;
				do {
					current = current->next;
				} while (current->next != this->head);

				current->next = newlink;
				newlink->next = this->head;
				this->head = newlink;
			}
		}
		//insert value at somewhere in middle of the link list
		else if (position > 1 && position < lengthOfLinkList()) {
			// create new link
			Link *newLink = new Link(value);

			//store head to current
			Link *current = this->head;
			Link *prev;

			int currentPostion = 1;
			//find the position
			while (current->next != this->head && currentPostion < position) {
				prev = current;
				current = current->next;
				currentPostion++;
			}
			//current is point to the Link where we want to store the value
			prev->next = newLink; //previous link is pointing to new link
			newLink->next = current; //and new link next will point to current node
		}

		//insert at the end of the linkList
		else if (position == lengthOfLinkList()) {
			Link * newlink = new Link(value);
			newlink->next = newlink;

			//store head to current
			Link * current = this->head;
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = newlink;
			newlink->next = this->head;

		} else {  //if given position didn't find
			cout << "position culdn't found";
		}
	}

	//get the length of the string
	int lengthOfLinkList() {
		Link * current = this->head;
		int length = 0;
		if (current == NULL) {
			return length;
		}
		do {
			current = current->next;
			length++;
		} while (current != this->head);
		return length;
	}

	//display linkList elements

	void displayLinkList() {
		Link * current = this->head;
		if (this->head == NULL) {
			cout << "list is empty";
		}
		do {
			cout << "-->" << current->data;
			current = current->next;
		} while (current != this->head);
	}

	//delete a element from the list
	void deleteAElement(int position) {
		//check if linkList isn't empty
		if (this->head == NULL) {
			cout << "linkList is empty";
		}

		//if position is first
		Link *current = this->head;
		if (position == 1) {
			this->head = current->next;
			delete (current);
		} else {  //if delete some intermediate or last element

			int k = 1;
			Link *previous;

			while (current->next != NULL && k < position) {
				previous = current;
				current = current->next;
				k++;
			}

			if (current == NULL) { //given position doesn't found
				cout << "given position not found";
			} else {
				previous->next = current->next;
				delete (current);
			}
		}
	}

	void deleteCompleteLinkList() {
		Link * temp = this->head;
		while (temp->next != this->head) {
			Link * next = temp->next;
			delete (temp);
			temp = next;
		}
		this->head = NULL;
	}

	static bool isListHaveALoopUsingHashMap(Link *headLink) {
		map<Link*, int> tempMap;
		Link * temp;
		temp = headLink;
		while (temp->next != NULL) {
			if (tempMap.find(temp) == tempMap.end()) {
				tempMap[temp] = 1;
			} else {
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}

	bool isEmpty() {
		return (this->head == NULL);
	}

	Link * getFirstElement() {
		return this->head;
	}

};

int main() {
	LinkedList link;

	//insert elements in linkList
	link.insertAElement(1, 1);
	link.insertAElement(2, 1);
	link.insertAElement(3, 1);
	link.insertAElement(4, 1);
	link.insertAElement(5, 1);
	link.insertAElement(6, 2);
	link.insertAElement(7, 3);
	link.insertAElement(8, 5);

	//display linkList
	cout<<"LinkList:"<<endl;
	link.displayLinkList();
	cout << endl;

	//delete a element from linkList
	link.deleteAElement(5);
	cout << endl;

	//again display linkList
	cout<<"LinkList after deleting fifth element"<<endl;
	link.displayLinkList();
	cout << endl;

	//display linkList length
	int a = link.lengthOfLinkList();
	cout << "Length:" << a << endl;

	//check if linkList have a loop ::obviously it will be because it circular linkList
	bool kk = LinkedList::isListHaveALoopUsingHashMap(link.getFirstElement());
	if (kk)
		cout << "LinkList have loop"<<endl;
	else
		cout << "LinkList don't have loop"<<endl;

//	delete complete linkList
	link.deleteCompleteLinkList();

	//display linkList length after deleting all elements
	int length = link.lengthOfLinkList();
	cout <<"length after deleting all elements: " <<length << endl;

	return 0;
}
