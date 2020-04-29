/*
The program should use all these methods to make the operations as follows:
1) create a queue of integers containing the numbers given by the user (placing them at
the beginning or at the end of the queue, according to the user's decision),
2) print the first and the last number,
3) remove the first or the last value from the queue,
4) print the first and the last number,
5) print the number of values in the queue if it is nonempty, or an appropriate message otherwise,
6) clear the queue.
Compare your implementation of the container with the built-in containers delivered in
<deque> and <list> libraries.
*/

#include "stdafx.h"
#include "double_ended_queue.h"
#include <iostream>
//#include <list>
//#include <deque>

using namespace std;

int main()
{
	
	DQueue<int> q1;

	q1.push_back(1);
	q1.push_back(2);
	q1.push_back(3);
	q1.push_front(4);
	q1.push_front(5);
	//5 4 1 2 3

	cout << "First: " << q1.front() << endl; //5
	cout << "Last: " << q1.back() << endl; //3
	cout << "Size: " << q1.size() << endl; //5
	q1.pop_back();
	cout << "First: " << q1.front() << endl; //5
	cout << "Last: " << q1.back() << endl; //2
	cout << "Size: " << q1.size() << endl; //4
	q1.pop_front();
	cout << "First: " << q1.front() << endl; //4
	cout << "Last: " << q1.back() << endl; //2
	cout << "Size: " << q1.size() << endl; //3

	DQueue<int> q2 = q1;
	//4 1 2

	q2.push_back(6);
	//4 1 2 6
	cout << "First: " << q2.front() << endl; //4
	cout << "Last: " << q2.back() << endl; //6
	cout << "Size: " << q2.size() << endl; //4

	q1 = q2;

	if (q1 == q2)
		cout << "The queues are equal." << endl; //yes

	q1.pop_front();
	//1 2 6
	cout << "First: " << q1.front() << endl; //1
	cout << "Last: " << q1.back() << endl; //6
	cout << "Size: " << q1.size() << endl; //3
	cout << "First: " << q2.front() << endl; //4
	cout << "Last: " << q2.back() << endl; //6
	cout << "Size: " << q2.size() << endl; //4

	q2.clear();
	cout << "First: " << q1.front() << endl; //1
	cout << "Last: " << q1.back() << endl; //6
	cout << "Size: " << q1.size() << endl; //3
	cout << "Size: " << q2.size() << endl; //0
	
    return 0;
}

