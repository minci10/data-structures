/*
Write a program which implements an unbounded stack (a Last-In-First-Out structure using
non-sequential memory storage – the linked list), aimed at storing real numbers, and a set of
methods operating on this structure:
• the default counstructor,
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• the destructor (with memory deallocation),
• push – adding a real number to the stack (with memory allocation),
• pop – removig from the stack a real number pushed there most recently or throwing
an empty stack exception (with memory deallocation),
• top – returning the most recently pushed number or throwing an empty stack
exception,
• print – printing the values which are on the stack currently, starting from the one
pushed recently,
• empty – informing whether the stack is empty,
• size – returning the number of the items on the stack,
• clear – removing all the items from the stack (with memory deallocation).
*/

#include <iostream>
#include <stdexcept>

struct Stack {

private:

	struct Node{

		int value;
		Node* next;

		Node(int v, Node* n = nullptr) {
			value = v;
			next = n;
		}

		//~Node() { std::cout << value << " destroyed" << std::endl; }

	};
	Node* head = nullptr;
	int counter = 0;

public:

	Stack() = default;	
	Stack(const Stack&);
	~Stack();
	void push(int);
	int pop();
	void clear();
	int size() const;
	bool empty() const;
	void print() const;
	int top() const;
	Stack& operator=(const Stack& s);
	bool operator==(const Stack& s)const;

};



Stack::Stack(const Stack& s) {

	
	Node* end = nullptr;
	Node* walker = s.head;
	while (walker != nullptr)
	{
		Node* creator = new Node(walker->value);
		if (end != nullptr)
			end->next = creator;
		else
			head = creator;
		end = creator;
		walker = walker->next;
	}

	counter = s.counter;

}

Stack::~Stack() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer; 
		
	}

}

void Stack::push(int value) {

	Node* creator = new Node(value,head);
	head = creator;
	counter++;

}

void Stack::print()const {

	if (counter == 0)
	{
		std::cout << "stack is empty." << std::endl;
	}
	else {

		Node* walker = head;
		while(walker != nullptr)
		{
			std::cout << walker->value << " ";	
			walker = walker->next;
		}

		std::cout << std::endl;

	
	}
	
}

int Stack::pop() {

	if (counter == 0)
	{
		throw std::logic_error("stack is empty.");
	}

	Node* killer = head;
	int value = killer->value;
	head = killer->next;
	delete killer;
	counter--;
	return value;

}

int Stack::size()const {

	return counter;

}

int Stack::top()const {

	if (counter==0)
	{
		throw std::logic_error("stack is empty.");
	}
	return head->value;

}

bool Stack::empty()const {

	if (counter==0)
	{
		return true;
	}
	else return false;

}

void Stack::clear() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer;

	}
	counter = 0;
}

bool Stack::operator==(const Stack& s)const {

	if (counter == s.counter)
	{
		Node* walker = head;
		Node* walker2 = s.head;
		while (walker != nullptr)
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

Stack& Stack::operator=(const Stack& s) {

	clear();
	Node* end = nullptr;
	Node* walker = s.head;
	while (walker != nullptr)
	{
		Node* creator = new Node(walker->value);
		if (end != nullptr)
			end->next = creator;
		else
			head = creator;
		end = creator;
		walker = walker->next;
	}
	counter = s.counter;
	return *this;
}

