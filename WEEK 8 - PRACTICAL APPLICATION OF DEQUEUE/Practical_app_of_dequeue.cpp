/*
Implement a structure of a process with an identifier (PID), a name, an execution message,
the default constructor and proper setters and gettters for the attributes. Write a program
which implements a queue of processes with attributes given by the user. Allow the user to:
- add a new process to the queue (at the end by default),
- execute the first process from the queue (printing its execution message and removing it from the queue),
- move the lastly added process to the beginning of the queue,
- check the current number of processes in the queue,
- clear the queue.
Use the double-ended queue structure
*/

#include "stdafx.h"
#include "dequeue_template.h"
#include <iostream>
#include <string>

using namespace std;

struct Process {

private:
	int PID = 0;
	string name = "unknown";
	string message = "Process is executed";
	
public:
	Process() = default;
	void setName(string n) { name = n; }
	string getName() const { return name; }

};


int main()
{
	DQueue<Process> q1;

	Process p1;
	p1.setName("Process 1");
	q1.push_back(p1);

	Process p2;
	p2.setName("Process 2");
	q1.push_back(p2);

	Process p3;
	p3.setName("Process 3");
	q1.push_back(p3);

	cout << "There are " << q1.size() << " process in the queue" << endl;
	
	cout << q1.front().getName() << q1.front().getMessage() << endl;
	
	q1.pop_front();

	cout << "There are " << q1.size() << " process in the queue now" << endl;
	
	cout << q1.front().getName() << " is ready for execution" << endl;

	q1.push_front(q1.back());
	q1.pop_back();

	cout << q1.front().getName() << " gets high priority and comes to the front of queue" << endl;


	q1.clear();

	if (q1.empty() == true)
	{
		cout << "Queue cleared, there isn't any process waiting for execution" << endl;
	}

    return 0;
}

