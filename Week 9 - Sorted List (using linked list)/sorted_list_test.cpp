/*
The program should use all these methods to make the operations as follows:
1) create an ordered list of integers containing the numbers given by the user,
2) print the greatest number,
3) remove the greatest value from the list,
4) print the greatest number,
5) print the number of values in the list if it is nonempty, or an appropriate message otherwise,
6) clear the list.
Compare your implementation of the container with the built-in container priority_queue
delivered in the <queue> library.
*/

#include "stdafx.h"
#include <iostream>
#include "sorted_list_template.h"
//#include <queue> 
//this example can be run using priority_queue as well

using namespace std;

int main()
{

	SortedList<int> s1;

	s1.push(3);
	s1.push(2);
	s1.push(3);
	s1.push(1);
	s1.push(4);

	s1.print(); //4 3 3 2 1
	cout << "Size: " << s1.size() << endl; //5
	cout << "Greatest: " << s1.top() << endl; //4
	s1.pop();
	s1.print(); //3 3 2 1
	cout << "Size: " << s1.size() << endl; //4
	cout << "Greatest: " << s1.top() << endl; //3

	SortedList<int> s2 = s1;

	s2.print(); //3 3 2 1
	s2.push(2);
	s2.print(); //3 3 2 2 1

	s1 = s2;

	if (s1 == s2)
		cout << "The lists are equal." << endl; //yes

	s1.pop();
	s1.print(); //3 2 2 1
	s2.print(); //3 3 2 2 1

	s2.clear();
	s1.print(); //3 2 2 1
	s2.print(); //empty
    return 0;
}

