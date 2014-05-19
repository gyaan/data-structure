#include<iostream>

//add std library for stack and queue
#include<stack>
#include<queue>
using namespace std;

int main() {

	//define queue and stack ADT
	queue <int> Q;
	stack <int> st;

	//enqueue Q
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	Q.push(5);
	Q.push(6);
	Q.push(7);
	Q.push(8);
	Q.push(9);
	Q.push(10);

	//dequeue Q & push elements to st
	while (!Q.empty()){
		st.push(Q.front());
		Q.pop();
	}

   //pop elements from st and enQueue again Q
	while (!st.empty()){
		Q.push(st.top());
		st.pop();
	}

	//finally print queue elements in reverse order
	while (!Q.empty()){
		cout << Q.front();
		Q.pop();
	}
	return 0;

}
