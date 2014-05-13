//complete program for singly link list
#include<iostream>
#include<map>
#include<string>
#include "stackUsingLinkList.h"
using namespace std;

//create a class for Link
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
	void insertAElement(int value, int position) {

		//insert value at staring of the linkList
		if (position == 1) { //storing at first
			Link *newlink = new Link(value);
			newlink->next = this->head;
			this->head = newlink;
		}

		//insert value at somewhere in middle of the link list
		else if (position > 1 && position <= lengthOfLinkList()) {
			// new link
			Link *newLink = new Link(value);

			//store head to current
			Link *current = this->head;
			Link *prev;
			int currentPostion = 1;

			while (current->next != NULL && currentPostion < position) {
				prev = current;
				current = current->next;
				currentPostion++;
			}
			prev->next = newLink;
			newLink->next = current;
		}

		//insert at the end of the linkList
		else if (position == lengthOfLinkList() + 1) {
			Link * newlink = new Link(value);
			//store head to current
			Link * current = this->head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newlink;
			newlink->next = NULL;
		} else {
			cout << "position culdn't found";
		}
	}

	int lengthOfLinkList() {
		Link * current = this->head;

		if (current == NULL) {
			cout << "list is empty";
		}

		int length = 0;
		while (current != NULL) {
			current = current->next;
			length++;
		}
		return length;
	}

	void displayLinkList() {
		Link * current = this->head;
		if (this->head == NULL) {
			cout << "list is empty";
		}
		while (current != NULL) {
			cout << "-->" << current->data;
			current = current->next;
		}
	}

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
			int k = 0;
			Link *previous;
			while (current->next != NULL && k < position) {
				previous = current;
				current = current->next;
				k++;
			}
			if (current == NULL) {
				cout << "given position not found";
			} else {
				previous->next = current->next;
				delete (current);
			}
		}
	}

	void deleteCompleteLinkList() {
		Link * temp = this->head;
		while (temp != NULL) {
			Link * next = temp->next;
			delete (temp);
			temp = next;
		}
		this->head = NULL;
	}
	int findNthElementFromLast(int n) {
		Link * temp = this->head;
		Link *temp2;

		while (temp->next != NULL) {
			temp2 = temp;
			int count = 0;
			while (temp2->next != NULL) {
				count++;
				temp2 = temp2->next;
			}
			if (count == n - 1) { //yes you found that Link;
				return temp->data;
			}
			temp = temp->next;
		}
		return 0; //given nth value is more then the no. of elements in linkList

	}

	int findNthElementFromLastUsingHashMap(int n) {
		map<int, Link*> tempMap;
		Link *temp = this->head;
		int i = 0;
		int elementCount = 0;
		while (temp->next != NULL) {
			tempMap[i] = temp;
			temp = temp->next;
			i++;
			elementCount++;
		}
		if (tempMap[elementCount - n + 1])
			return tempMap[elementCount - n + 1]->data;
		else
			return 0; //given nth value is more then the no. of elements in linkList
	}

	int findNthElementFromLastUsingTwoPointer(int n) {

		Link * temp = this->head;
		Link * pTemp = this->head;
		int count = 0;
		while (temp->next != NULL) {
			count++;
			if (count >= n) {
				pTemp = pTemp->next;
			}
			temp = temp->next;
		}
		if (count < n)
			return 0; //given nth value is more then the no. of elements in linkList
		else
			return pTemp->data;
	}

	static bool isListHaveALoopUsingHashMap(Link *headLink) {
		map<Link*, int> tempMap;
		Link * temp;
		temp = headLink;
		while (temp->next != NULL) {
			if (tempMap.find(temp) == tempMap.end()) {
				tempMap[temp] = 1;
			} else {
				return 0;
			}
			temp = temp->next;
		}
		return 1;
	}

	bool isListHaveALoopUsingTwoPointerMethod() {

		//for testing this function creating a loop in the linklist
		// make sure linkList have enough elements

		Link *temp = this->head;
//		temp->next->next->next = temp->next;

		Link *slow = this->head;
		Link *fast = this->head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				;
			return 1;
		}
		return 0;
	}

	void reverseALinkList() {
		Link *current = this->head;
		Link *previous = NULL;
		Link *temp;
		while (current != NULL) {
			temp = current->next;
			current->next = previous;
			previous = current;
			current = temp;
		}
		this->head = previous;
	}

	static Link * reverseALinklist(Link *headLink) {
		Link *current = headLink;
		Link *previous = NULL;
		Link *temp;
		while (current != NULL) {
			temp = current->next;
			current->next = previous;
			previous = current;
			current = temp;
		}
		return previous;
	}

	string checkLinkListLenghtIsEvenOrOdd() {

		Link *temp = this->head;
		while (temp != NULL && temp->next != NULL) {
			temp = temp->next->next;
		}

		if (temp == NULL)
			return "Even";
		if (temp->next == NULL)
			return "Odd";
	}

	static bool isLinkListIspalinDram(Link *headLink) {

		Link *reversHead;
		reversHead = LinkedList::reverseALinklist(headLink);
		while (headLink != NULL && reversHead != NULL) {

			if (headLink->data != reversHead->data)
				return 0;
			headLink = headLink->next;
			reversHead = reversHead->next;
		}
		return 1;
	}

	static bool isLinkListPalinDramUsingStack(Link *headLink) {
		Link * fast = headLink;
		Link * slow = headLink;

		Stack s; //create a stack

		while (fast != NULL && fast->next != NULL) {
			s.push(slow->data);
			slow = slow->next;
			fast = fast->next->next;
		}
		while (slow->next != NULL) {
			if (slow->next->data != s.pop()) {
				return 0;
			}
			slow = slow->next;
		}
		return 1;
	}

	Link * getFirstElement() {
		return this->head;
	}

};
int main() {
	LinkedList link;

	//insert elements in the linkList
	link.insertAElement(1, 1);
	link.insertAElement(2, 2);
	link.insertAElement(3, 3);
	link.insertAElement(4, 4);
	link.insertAElement(3, 5);
	link.insertAElement(2, 6);
	link.insertAElement(1, 7);
//	link.insertAElement(8, 8);

	//display length of list
	cout << "length of the list:" << link.lengthOfLinkList();

	cout << "get a fifth element from end " << endl;
	cout << "using brute force method: " << link.findNthElementFromLast(5)
			<< endl;
	cout << "using brute Hash Map: "
			<< link.findNthElementFromLastUsingHashMap(5) << endl;
	cout << "using brute two pointer: "
			<< link.findNthElementFromLastUsingTwoPointer(5) << endl;

	cout << endl;
	link.displayLinkList();
	link.reverseALinkList();

	cout << endl << "linkList after reverse" << endl;
	//display link list
	link.displayLinkList();
	cout << endl;

	//display length of list
	cout << "length of the list:" << link.lengthOfLinkList();

	//delte a elements in linklist
//	link.deleteAElement(5);
//	link.deleteAElement(5);
	cout << endl;

	//display linkList
//	link.displayLinkList();
//	cout << endl;

	//display linkList
	link.displayLinkList();
	cout << endl;

//	bool test = LinkedList::isLinkListIspalinDram(link.getFirstElement());
//	if(test)
//		cout<<"link list is palindrom"<<endl;
//	else
//		cout<<"link list is not palindrom"<<endl;

//	link.deleteCompleteLinkList();
	int a = link.lengthOfLinkList();
	cout << "length of the linkList:" << a << endl;

	//check linklist length is even or odd
//	string check;
//	check = link.checkLinkListLenghtIsEvenOrOdd();
//	cout<<"length of linkList is :"<<check<<endl;

	//check if linkList have loop
	bool aa = link.isListHaveALoopUsingTwoPointerMethod();
	if (aa)
		cout << "link have loop" << endl;
	else
		cout << "link don't have loop" << endl;

	//check linklist is palindrom or not

	bool jj = LinkedList::isLinkListPalinDramUsingStack(link.getFirstElement());

	if (jj) {
		cout << "link list is palindrom"<<endl;
	} else {
		cout << "link list is not palindrom"<<endl;
	}

	return 0;
}
