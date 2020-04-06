/*  
Write a program which implements a bounded stack (a Last-In-First-Out structure using
sequential memory storage), aimed at storing real numbers, and a set of methods operating
on this structure:
• the constructor with the size of the stack as a parameter (with memory allocation),
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• the destructor (with memory deallocation),
• push – adding a real number to the stack or throwing a full stack exception,
• pop – removig from the stack a real number pushed there most recently or throwing
an empty stack exception,
• top – returning the most recently pushed number or throwing an empty stack
exception,
• print – printing the values which are on the stack currently, starting from the one
pushed recently,
• empty – informing whether the stack is empty,
• size – returning the number of the items on the stack,
• clear – removing all the items from the stack.
*/

#pragma once
#include <stdexcept>
#include <iostream>

struct Stack {

private:
	int capacity = 0;
	int counter = 0;
	int* data = nullptr;



public:
	Stack(int=10);
	Stack(const Stack&);
	~Stack();
	void push(int);
	int pop();
	void print()const;
	bool empty()const;
	int top()const;
	int size() const;
	bool operator==(const Stack&) const;
	Stack& operator=(const Stack&);
	void clear();


};

Stack::Stack(int max_size) {

	if (max_size < 1)
	{
		throw std::invalid_argument("Wrong stack size");
	}
	capacity = max_size;
	data = new int[capacity];

}

Stack::~Stack() {

	delete[] data;

}

void Stack::push(int num) {

	if (counter == capacity)
	{
		throw std::out_of_range("Stack is full");
	}

	data[counter++] = num;
	
}

int Stack::pop() {

	if (counter <= 0 )
	{
		throw std::logic_error("Stack is empty");
	}

	return data[--counter];

}

void Stack::print()const {

	if (counter == 0)
	{
		std::cout << "Stack is empty" << std::endl;
	}

	for (int i = counter-1; i >= 0; i--)
	{
		std::cout << data[i] << " ";
	}
	
	std::cout << std::endl;

}

bool Stack::empty()const {

	if (counter > 0)
	{
		return false;
	}

	else {

		return true;
	}

}

int Stack::top()const {

	if (counter==0)
	{
		throw std::logic_error("Stack is empty");
	}

	return data[counter - 1];

}

int Stack::size()const {

	return counter;

}

Stack::Stack(const Stack& s) {

	capacity = s.capacity;
	counter = s.counter;
	data = new int[capacity];
	for (size_t i = 0; i < counter; i++)
	{
		data[i] = s.data[i];
	}
	
}

bool Stack::operator==(const Stack& s)const {

	bool equality = true;
	for (int i = 0; i < counter; i++)
	{
		if (data[i] != s.data[i])
		{
			equality = false;
		}
	}
	return equality;

}

 Stack& Stack::operator=(const Stack& s) {

	delete[] data;
	counter = s.counter;
	capacity = s.capacity;
	data = new int[capacity];
	for (int i = 0; i < counter; i++)
	{
		data[i] = s.data[i];
		
	}
	return *this;

}

 void Stack::clear() {

	 delete[] data;
	 counter = 0;
	 data = new int[capacity];

 }
