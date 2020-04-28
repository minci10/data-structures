/*
Write a program which implements an unbounded vector container (using sequential
memory storage) as a template structure (aimed at storing values of any type), and a set of
methods operating on this structure:
• the default constructor (with some starting memory allocation),
• the destructor (with memory deallocation),
• the copy-constructor (with memory allocation),
• the assignment operator= (with memory dellocation and allocation),
• the comparison operator==,
• the indexing operator[],
• push_back – adding a value to the vector (with memory allocation if necessary),
• pop_back – removig the last value from the vector or throwing an empty vector exception,
• front – returning the first value or throwing an empty vector exception,
• back – returning the last value or throwing an empty vector exception,
• empty – informing whether the vector is empty,
• size – returning the number of items in the vector,
• clear – removing all the items from the vector.
*/

#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
struct Vector {

private:
	T* data = nullptr;
	int capacity = 1;
	int counter = 0;

public:
	Vector();

	~Vector();

	Vector(const Vector&);

	void push_back(T);

	void pop_back();

	T front() const;

	T back() const;

	bool empty() const;

	int size() const;

	void clear();

	Vector& operator=(const Vector&);

	bool operator==(const Vector&) const;

	T& operator[](int) const;


};

template<typename T>
Vector<T>::Vector() {

	data = new T[capacity];

}

template<typename T>
Vector<T>::~Vector() {

	delete[] data;

}

template<typename T>
void Vector<T>::push_back(T value) {

	if (counter==capacity)
	{
		capacity *= 2;
		T* tmp = new T[capacity];
		for (int i = 0; i < counter; i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
	}

	data[counter++] = value;

}

template<typename T>
void Vector<T>::pop_back() {

	if (counter == 0)
	{
		throw logic_error("Vector is empty");
	}
	counter--;

}

template<typename T>
T Vector<T>::front() const {

	if (counter == 0)
	{
		throw logic_error("Vector is empty");
	}
	return data[0];

}

template<typename T>
T Vector<T>::back() const {

	if (counter == 0)
	{
		throw logic_error("Vector is empty");
	}
	return data[counter-1];

}

template<typename T>
int Vector<T>::size() const {

	return counter;
	
}

template<typename T>
T& Vector<T>::operator[](int index) const {

	if (index < 0 || index >= counter)
	{
		throw out_of_range("Out of vector range");
	}

	return data[index];

}

template<typename T>
bool Vector<T>::empty()const {

	if (counter > 0)
	{
		return true;
	}

	else return false;

}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& v)const {

	bool eq = true;
	if (counter != v.counter)
	{
		eq = false;
	}
	else {

		for (int i = 0; i < counter; i++)
		{
			if (data[i] != v.data[i])
			{
				eq = false;
			}
		}

	}
	return eq;
}



template<typename T>
Vector<T>::Vector(const Vector<T>& v) {


	data = new T[capacity];

	for (int i = 0; i < v.counter; i++)
	{
		push_back(v.data[i]);
	}


}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {

	delete[] data;
	capacity = 1;
	counter = 0;
	data = new T[capacity];
	for (int i = 0; i < v.counter; i++)
	{
		push_back(v.data[i]);
	}

	return *this;

}

template<typename T>
void Vector<T>::clear() {

	delete[] data;
	counter = 0;
	capacity = 1;
	data = new T[capacity];

}
