/*
Write a program which implements an unbounded queue (a First-In-First-Out structure using
non-sequential memory storage – the linked list), aimed at storing real numbers, and a set of
methods operating on this structure:
• the default counstructor,
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• the destructor (with memory deallocation),
• push – adding a real number to the queue (with memory allocation),
• pop – removig from the queue a real number placed there as first or throwing an
empty queue exception (with memory deallocation),
• front – returning the first number or throwing an empty queue exception,
• back – returning the last number or throwing an empty queue exception,
• print – printing the values which are in the queue currently in the order of placement,
• empty – informing whether the queue is empty,
• size – returning the number of items in the queue,
• clear – removing all the items from the queue (with memory deallocation)
*/

#pragma once
using namespace std;

struct Queue {

private:

	struct Node {

		int value;
		Node* next;

		Node(int v, Node* n = nullptr) {

			value = v;
			next = n;

		}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int counter = 0;

public:

	Queue() = default;

	Queue(const Queue&);

	~Queue();

	void push(int);

	int pop();

	void clear();

	int front() const;

	int back() const;

	int size() const;

	void print() const;

	bool empty() const;

	Queue& operator=(const Queue&);

	bool operator==(const Queue&) const;

};


void Queue::push(int value) {

	Node* creator = new Node(value);
	if (tail != nullptr)
	{
		tail->next = creator;
	}
	else {
		head = creator;
	}
	tail = creator;
	counter++;

}


int Queue::pop() {

	if (counter == 0)
	{
		throw logic_error("empty queue");
	}

	int value = head->value;
	Node* killer = head;
	head = killer->next;
	if (tail == killer)
	{
		tail = nullptr;
	}
	delete killer;
	counter--;
	return value;
}


Queue::~Queue() {

	clear();

}

int Queue::size() const {

	return counter;

}


void Queue::print()const {

	if (counter==0)
	{
		cout << "empty";
	}

	Node* walker = head;
	while (walker != nullptr)
	{
		cout << walker->value << " ";
		walker = walker->next;
	}
	cout << endl;

}

int Queue::front()const {

	if (counter == 0)
	{
		throw logic_error("empty queue");
	}
	
	return head->value;
	
	

}

int Queue::back()const {

	if (counter == 0)
	{
		throw logic_error("empty queue");
	}
	
	return tail->value;
	

}

void Queue::clear() {

	while (head != nullptr) {

		Node* killer = head;
		head = killer->next;
		delete killer;

	}

	tail = nullptr;
	counter = 0;

}

bool Queue::empty()const {

	if (counter == 0)
	{
		return true;
	}
	else return false;

}

Queue::Queue(const Queue &q) {
	 
	Node* walker = q.head;
	while (walker != nullptr)
	{
		push(walker->value);
		walker = walker->next;
	}

}

Queue& Queue::operator=(const Queue& q) {

	clear();
	Node* walker = q.head;
	while (walker != nullptr)
	{
		push(walker->value);
		walker = walker->next;
	}
	return *this;

}  

bool Queue::operator==(const Queue& q)const {

	if (counter == q.counter)
	{
		Node* walker = head;
		Node* walker2 = q.head;
		if (walker != nullptr)
		{
			if (walker->value != walker2->value)
			{
				return false;
			}

			walker = walker->next;
			walker2 = walker2->next;
		}
		return true;
	}
	else return false;
}