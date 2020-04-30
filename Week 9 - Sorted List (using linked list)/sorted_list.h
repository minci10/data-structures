/*
Write a program which implements an unbounded sorted list (using the single or doublelinked list) as a template structure (aimed at storing values of any type and ordering them in
descending order - from the greatest to the lowest), and a set of methods operating on this structure:
• the default constructor,
• the destructor (with memory deallocation),
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• push – adding a value to the list in descending order (with memory allocation),
• pop – removig the greatest value from the list or throwing an empty list exception (with memory deallocation),
• top – returning the greatest value or throwing an empty list exception,
• count – returning the number of occurences of a value,
• empty – informing whether the list is empty,
• size – returning the number of items in the list,
• clear – removing all the items from the list (with memory deallocation).
*/

#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
struct SortedList {

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

	SortedList() = default;
	
	SortedList(const SortedList&);
	
	~SortedList();
	
	void push(T);
	
	void pop();
	
	T top() const;
	
	int count(T) const;
	
	bool empty() const;
	
	int size() const;
	
	void print() const;
	
	void clear();
	
	bool operator==(const SortedList&) const;
	
	SortedList& operator=(const SortedList&);

};


template<typename T>
SortedList<T>::~SortedList() {

	clear();

}

template<typename T>
void SortedList<T>::push(T value) {

	Node* pred = nullptr;
	Node* succ = head;

	while (succ != nullptr && value < succ->value)
	{
		pred = succ;
		succ = succ->next;	
	}
	Node* creator = new Node(value, succ);
	if (pred != nullptr)
	{
		pred->next = creator;
	}
	else
	{
		head = creator;
	}
	counter++;


}

template<typename T>
void SortedList<T>::pop() {

	if (counter == 0)
	{
		throw logic_error("Empty list");
	}

	Node* killer = head;
	head = head->next;
	delete killer;
	counter--;


}

template<typename T>
int SortedList<T>::count(T value) const {

	int ctr = 0;
	Node* walker = head;
	while (walker != nullptr)
	{
		if (walker->value == value)
		{
			ctr++;
		}
		walker = walker->next;
	}
	return ctr;
}


template<typename T>
T SortedList<T>::top() const {

	if (counter == 0)
	{
		throw logic_error("Empty list");
	}
	return head->value;

}

template<typename T>
int SortedList<T>::size() const {

	return counter;

}

template<typename T>
void SortedList<T>::print() const {

	if (counter == 0)
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

template <typename T>
void SortedList<T>::clear() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = head->next;
		delete killer;
	}
	counter = 0;
}

template<typename T>
bool SortedList<T>::empty() const {

	if (counter == 0)
	{
		return true;
	}

	else return false;

}

template<typename T>
SortedList<T>::SortedList(const SortedList<T> &s) {

	Node* walker = s.head;
	while (walker != nullptr)
	{
		push(walker->value);
		walker = walker->next;
	}

}

template<typename T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T> &s) {

	clear();
	Node* walker = s.head;
	while (walker != nullptr)
	{
		push(walker->value);
		walker = walker->next;
	}
	return *this;
}

template<typename T>
bool SortedList<T>::operator==(const SortedList &s) const {

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