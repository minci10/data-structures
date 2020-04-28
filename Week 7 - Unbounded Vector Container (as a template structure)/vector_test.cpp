/*
The program should use all these methods to make the operations as follows:
1) create a vector of integers containing the numbers given by the user,
2) print the contents of the vector (with the help of the indexing operator),
3) remove the last value from the vector,
4) print the first and the last number,
5) print the number of values in the vector if it is nonempty, or an appropriate message otherwise,
6) clear the vector.
Compare your implementation of the container with the built-in container delivered in <vector> library
*/

#include "stdafx.h"
#include <iostream>
#include "unbounded_vector.h"
//#include <vector>

using namespace std;

template<typename T>
void print(Vector<T>& v) {

	if (v.size() == 0 )
	{
		cout << "empty";
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		
	}
	cout << endl;

}

int main()
{
	
	Vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	print(v1); //1 2 3 4 5
	cout << "Size: " << v1.size() << endl; //5
	v1.pop_back();
	cout << "First: " << v1.front() << endl; //1
	cout << "Last: " << v1.back() << endl; //4
	cout << "Size: " << v1.size() << endl; //4
	print(v1); //1 2 3 4

	Vector<int> v2 = v1;

	print(v2); //1 2 3 4
	v2.push_back(6);
	print(v2); //1 2 3 4 6

	v1 = v2;

	if (v1 == v2)
		cout << "The vectors are equal." << endl; //yes

	v1.pop_back();
	cout << "Last: " << v1.back() << endl; //4
	print(v1); //1 2 3 4
	print(v2); //1 2 3 4 6

	v2.clear();
	print(v1); //1 2 3 4
	print(v2); //empty
	
    return 0;
}

