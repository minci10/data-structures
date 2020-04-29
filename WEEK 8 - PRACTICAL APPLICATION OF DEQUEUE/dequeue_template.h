
#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
struct DQueue {

private:

	struct Node {

		T value;
		Node* prev;
		Node* next;

		Node(T v, Node* p = nullptr, Node* n = nullptr) {

			value = v;
			prev = p;
			next = n;

		}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int counter = 0;


public:

	DQueue() = default;

	DQueue(const DQueue&);

	~DQueue();

	void push_back(T);

	void pop_back();

	void push_front(T);

	void pop_front();

	T front() const;

	T back() const;

	void clear();

	int size() const;

	bool empty() const;

	DQueue& operator=(const DQueue&);

	bool operator==(const DQueue&) const;


};


template<typename T>
T DQueue<T>::front() const {

	if (counter == 0)
	{
		throw logic_error("Empty queue");
	}
	return head->value;

}

template<typename T>
T DQueue<T>::back() const {

	if (counter == 0)
	{
		throw logic_error("Empty queue");
	}
	return tail->value;

}


template<typename T>
DQueue<T>::~DQueue() {

	clear();

}


template<typename T>
int DQueue<T>::size() const {

	return counter;

}


template<typename T>
void DQueue<T>::clear() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer;
	}

	tail = nullptr;
	counter = 0;

}

template<typename T>
DQueue<T>::DQueue(const DQueue<T> &q) {

	Node* walker = q.head;
	while (walker != nullptr)
	{
		push_back(walker->value);
		walker = walker->next;

	}

}

template<typename T>
DQueue<T>& DQueue<T>::operator=(const DQueue<T> &q) {

	clear();
	Node* walker = q.head;
	while (walker != nullptr)
	{
		push_back(walker->value);
		walker = walker->next;
	}

	return *this;

}


template<typename T>
bool DQueue<T>::empty() const {

	if (counter == 0)
	{
		return true;
	}

	else return false;
}


template<typename T>
bool DQueue<T>::operator==(const DQueue<T> &q) const {

	if (counter == q.counter)
	{
		Node* walker = head;
		Node* walker2 = q.head;

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

template<typename T>
void DQueue<T>::push_back(T value) {

	Node* creator = new Node(value, tail, nullptr);
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


template<typename T>
void DQueue<T>::push_front(T value) {

	Node* creator = new Node(value, nullptr, head);
	if (head != nullptr)
	{
		head->prev = creator;
	}
	else {
		tail = creator;
	}
	head = creator;
	counter++;

}

template<typename T>
void DQueue<T>::pop_back() {

	if (counter == 0)
	{
		throw logic_error("Empty Queue");
	}

	if (tail->prev != nullptr)
	{
		tail->prev->next = nullptr;
	}
	else {
		head = nullptr;
	}

	Node* killer = tail;
	tail = tail->prev;
	delete killer;
	counter--;

}


template<typename T>
void DQueue<T>::pop_front() {

	if (counter == 0)
	{
		throw logic_error("Empty Queue");
	}
	if (head->next != nullptr)
	{
		head->next->prev = nullptr;
	}
	else {
		tail = nullptr;
	}

	Node* killer = head;
	head = head->next;
	delete killer;
	counter--;

}