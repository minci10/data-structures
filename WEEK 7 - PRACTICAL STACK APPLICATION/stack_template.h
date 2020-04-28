#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
struct Stack {

private:

	struct Node {

		T value;
		Node* next;

		Node(T v, Node* n = nullptr) {
			value = v;
			next = n;
		}


	};
	Node* head = nullptr;
	int counter = 0;

public:

	Stack() = default;
	Stack(const Stack&);
	~Stack();
	void push(T);
	T pop();
	void clear();
	int size() const;
	bool empty() const;
	void print() const;
	T top() const;
	Stack operator=(const Stack& s);
	bool operator==(const Stack& s)const;

};


template<typename T>
Stack<T>::Stack(const Stack& s) {


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

template<typename T>
Stack<T>::~Stack() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer;

	}

}

template<typename T>
void Stack<T>::push(T value) {

	Node* creator = new Node(value, head);
	head = creator;
	counter++;

}

template<typename T>
void Stack<T>::print()const {

	if (counter == 0)
	{
		cout << "stack is empty." << endl;
	}
	else {

		Node* walker = head;
		while (walker != nullptr)
		{
			cout << walker->value << " ";
			walker = walker->next;
		}

		cout << endl;


	}

}

template<typename T>
T Stack<T>::pop() {

	if (counter == 0)
	{
		throw logic_error("stack is empty.");
	}

	Node* killer = head;
	T value = killer->value;
	head = killer->next;
	delete killer;
	counter--;
	return value;

}

template<typename T>
int Stack<T>::size()const {

	return counter;

}

template<typename T>
T Stack<T>::top()const {

	if (counter == 0)
	{
		throw logic_error("stack is empty.");
	}
	return head->value;

}

template<typename T>
bool Stack<T>::empty()const {

	if (counter == 0)
	{
		return true;
	}
	else return false;

}

template<typename T>
void Stack<T>::clear() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer;

	}
	counter = 0;
}

template<typename T>
bool Stack<T>::operator==(const Stack& s)const {

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

template<typename T>
Stack<T> Stack<T>::operator=(const Stack& s) {

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