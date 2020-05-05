/*
Write a program which implements an unbounded sorted set (using the single or doublelinked list) as a template structure (aimed at storing unique 
values of any type and ordering them in ascending order - from the lowest to the greatest), and the methods operating on this structure:
• the default constructor,
• the destructor (with memory deallocation),
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• insert – adding a value to the set in ascending order only if it doesn't exist in the set(with memory allocation),
• erase – removig the given value from the set if exists (with memory deallocation) and returning the number of items removed (0 or 1),
• count – returning the number of occurences of a value (0 or 1),
• empty – informing whether the set is empty,
• size – returning the number of items in the set,
• clear – removing all the items from the set (with memory deallocation).
*/
#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>	
struct Set {


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


	Set() = default;

	Set(const Set&);

	~Set();

	void insert(T);

	int erase(T);

	void clear();

	int count(T) const;

	int size() const;

	void print() const;

	bool empty() const;

	Set& operator=(const Set&);

	bool operator==(const Set&) const;


};



template<typename T>
Set<T>::~Set() {

	clear();

}

template<typename T>
void Set<T>::print() const {

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

template<typename T>
void Set<T>::clear() {

	
	while (head != nullptr)
	{
		Node* killer = head;
		head = killer->next;
		delete killer;
		
	}
	counter = 0;


}

template<typename T>
Set<T>::Set(const Set<T> &s) {

	Node* walker = s.head;
	while (walker != nullptr)
	{
		insert(walker->value);
		walker = walker->next;
	}
	
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T> &s) {

	clear();
	Node* walker = s.head;
	while (walker != nullptr)
	{
		insert(walker->value);
		walker = walker->next;
	}
	return *this;

}

template<typename T>
int Set<T>::size()const {

	return counter;
}

template<typename T>
bool Set<T>::empty()const {

	if (counter == 0)
	{
		return true;
	}

	else return false;
}


template<typename T>
void Set<T>::insert(T value) {

	Node* pred = nullptr;
	Node* succ = head;
	while (succ != nullptr && succ->value < value)
	{
		pred = succ;
		succ = succ->next;
	}
	if (succ == nullptr || value < succ->value)
	{
		Node* creator = new Node(value,succ);
		if (pred != nullptr)
		{
			pred->next = creator;
		}
		else {
			head = creator;
		}
		counter++;
	}

}


template<typename T>
int Set<T>::erase(T value) {

	Node* pred = nullptr;
	Node* succ = head;
	while (succ != nullptr && succ->value < value)
	{
		pred = succ;
		succ = succ->next;
	}
	if (succ != nullptr && succ-> value == value)
	{
		Node* killer = succ;
		succ = succ->next;
		if (pred != nullptr)
		{
			pred->next = succ;
		}
		else {
			head = succ;
		}
		delete killer;
		counter--;
		return 1;
		
	}
	return 0;
}

template<typename T>
int Set<T>::count(T value) const {

	
	Node* walker = head;
	while (walker != nullptr)
	{
		if (walker->value == value)
		{
			return 1;
		}
		walker = walker->next;
	}
	return 0;
	
}

template<typename T>
bool Set<T>::operator==(const Set<T> &s) const {

	if (counter != s.counter)
	{
		return false;
	}
	else {
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
	

}