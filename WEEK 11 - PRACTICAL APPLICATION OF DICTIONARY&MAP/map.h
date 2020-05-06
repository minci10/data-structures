#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template<typename K,typename T>
struct Map {

private:

	struct Node{

		K key;
		T value;
		Node* next;
		Node(K k, T v, Node* n = nullptr) {

			key = k;
			value = v;
			next = n;	

		}

	};
	Node* head = nullptr;
	int counter = 0;


public:

	Map() = default;

	~Map();

	Map(const Map&);

	Map& operator=(const Map&);

	bool operator== (const Map&) const;

	int erase(K);

	int count(K) const;

	bool empty() const;

	int size() const;

	void clear();

	void print() const;

	T& operator[] (K);
};


template<typename K,typename T>
Map<K, T>::~Map() {

	clear();

}

template<typename K,typename T>
T& Map<K, T>::operator[](K key) {

	Node* pred = nullptr;
	Node* succ = head;
	while (succ != nullptr && succ->key < key)
	{
		pred = succ;
		succ = succ->next;
	}
	
	if (succ == nullptr ||  key < succ->key)
	{
		Node* creator = new Node(key,T(),succ);
		if (pred != nullptr)
		{
			pred->next = creator;
		}
		else {
			head = creator;
		}
		counter++;
		succ = creator;
	}

	 return succ->value;

}

template<typename K,typename T>
int Map<K,T>::erase(K key) {

	Node* pred = nullptr;
	Node* succ = head;
	while (succ != nullptr && succ->key < key)
	{
		pred = succ;
		succ = succ->next;
	}
	if (succ != nullptr && succ->key == key)
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

template<typename K, typename T>
int Map<K, T>::size() const {

	return counter;

}


template<typename K,typename T>
bool Map<K, T>::empty() const {

	if (counter == 0)
	{
		return true;
	}
	else return false;

}

template<typename K,typename T>
void Map<K, T>::print() const {

	if (counter == 0)
	{
		cout << "empty";
	}
	Node* walker = head;
	while (walker != nullptr)
	{
		cout << walker->key << "->" << walker->value << endl;
		walker = walker->next;
	}
	cout << endl;

}

template<typename K,typename T>
void Map<K, T>::clear() {

	while (head != nullptr)
	{
		Node* killer = head;
		head = head->next;
		delete killer;
	}
	counter = 0;
}

template<typename K,typename T>
Map<K, T>::Map(const Map<K,T> &m) {

	Node* walker = m.head;
	while (walker != nullptr)
	{
		(*this)[walker->key] = walker->value;
	//  operator[](walker->key) = walker->value;
		walker = walker->next;
	}

}

template<typename K,typename T>
Map<K, T>& Map<K, T>::operator=(const Map<K, T> &m) {

	clear();
	Node* walker = m.head;
	while (walker != nullptr)
	{
		(*this)[walker->key] = walker->value;
	//  operator[](walker->key) = walker->value;
		walker = walker->next;
	}
	return *this;
}

template<typename K,typename T>
int Map<K, T>::count(K key)const {

	Node* walker = head;
	while (walker != nullptr && walker->key <= key)
	{
		if (walker->key == key)
		{
			return 1;
		}
		walker = walker->next;
	}
	return 0;

}

template<typename K,typename T>
bool Map<K, T>::operator==(const Map<K,T> &m) const {

	if (counter != m.counter)
	{
		return false;
	}
	else {
		Node* walker = head;
		Node* walker2 = m.head;
		while (walker != nullptr)
		{
			if (walker->key != walker2->key || walker->value != walker2->value  )
			{
				return false;
			}
			walker = walker->next;
			walker2 = walker2->next;
		}
	}
	return true;
}
