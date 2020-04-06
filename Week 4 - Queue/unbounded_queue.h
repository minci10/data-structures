/*
Write a program which implements an unbounded queue (a First-In-First-Out structure using
sequential memory storage), aimed at storing real numbers, and a set of methods operating
on this structure:
• the default constructor (with some starting memory allocation),
• the destructor (with memory deallocation),
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• push – adding a real number to the queue (with memory allocation if necessary),
• pop – removig from the queue a real number placed there as first or throwing an
empty queue exception,
• front – returning the first number or throwing an empty queue exception,
• back – returning the last number or throwing an empty queue exception,
• print – printing the values which are in the queue currently in the order of placement,
• empty – informing whether the queue is empty,
• size – returning the number of items in the queue,
• clear – removing all the items from the queue.
/*

#include <iostream>
#include <stdexcept>

struct Queue {

private:
	int *data = nullptr;
	int capacity = 10;
	int counter = 0;
	int first = 0;
	int last = 0;

public:
	Queue();
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
	bool operator==(const Queue&)const;
	Queue& operator=(const Queue&);

};

Queue::Queue() {

	data = new int[capacity];

}

Queue::~Queue() {

	delete [] data;

}


void Queue::push(int value) {

	if (last == capacity)
	{
		if (counter < capacity)
		{
			for (int i = 0; i < counter; i++)
			{
				data[i] = data[first+i];
				first = 0;
				last = counter;
			}
		}
		else {

			capacity *= 2;
			int* tmp = new int[capacity];
			for (int i = 0; i < counter; i++)
			{
				tmp[i] = data[i];
			}
			delete[] data;
			data = tmp;

		}
	}
	
	data[last++] = value;
	counter++;

}

void Queue::print()const {

	if (counter == 0)
	{
		std::cout << "empty" << std::endl;
	}
	else {

		for (int i = 0	; i < counter; i++)
		{

		std::cout << data[first+i] << " ";
	
		}

		std::cout << std::endl;

	}

}

int Queue::pop() {

	if (counter==0)
	{
		throw std::logic_error("Queue is empty");
	}

	else {

		int value = data[first++];
		counter--;

		if (counter < capacity * 0.2)
		{

			capacity /= 2;
			int* tmp2 = new int[capacity];
			for (int i = 0; i < counter; i++)
			{
				tmp2[i] = data[first + i];
			}
			delete[] data;
			data = tmp2;
			first = 0;
			last = first + counter;
				
		}

		return value;

	}
}

int Queue::front()const {

	if (counter==0)
	{
		std::cout << "Queue is empty." << std::endl;
	}

	else {

		return data[first];

	}
}

int Queue::back()const {
	
	if (counter == 0)
	{
		std::cout << "Queue is empty." << std::endl;
	}

	else {

		return data[last - 1];

	}
}

int Queue::size()const {

	return counter;

}

bool Queue::empty()const {

	if (counter == 0)
	{
		return true;
	}
	else {

		return false;

	}

}

void Queue::clear() {

	delete[] data;
	first = 0;
	last = 0;
	counter = 0;
	data = new int[capacity];

}

Queue::Queue(const Queue& q) {

	capacity = q.capacity;
	first = q.first;
	last = q.last;
	counter = q.counter;
	int* tmp4 = new int[capacity];
	for (int i = 0; i < last; i++)
	{
		tmp4[i] = q.data[i];
	}
	delete[] data;
	data = tmp4;

}

bool Queue::operator==(const Queue& q)const {

	if (counter == q.counter)
	{
		bool equality = true;
		for (int i = first; i < last; i++)
		{
			if (data[i] != q.data[i])
			{
				equality = false;
			}
		}

		return equality;

	}

	else {

		return false;

	}
}

Queue& Queue::operator=(const Queue& q) {

	capacity = q.capacity;
	first = q.first;
	last = q.last;
	counter = q.counter;
	int* tmp3 = new int[capacity];
	for (int i = 0; i < last; i++)
	{
		tmp3[i] = q.data[i];
	}
	delete[] data;
	data = tmp3;
	return *this;

}