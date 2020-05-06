/*
The program should use all these methods to make the operations as follows:
1) create a dictionary of integers containing the numbers given by the user together
with the counters of the repetitions of that numbers,
2) print the number of items stored in the dictionary,
3) remove a number from the dictionary,
4) print the number of items stored in the dictionary,
5) check if a given value is in the dictionary,
6) clear the dictionary.
Compare your implementation of the container with the built-in container map delivered in
the <map> library
*/

#include "stdafx.h"
#include "map.h"
#include <iostream>
//#include <map>

using namespace std;

int main()
{

	Map<int, unsigned> s1;

	s1[3];
	s1[2]++;
	s1[3]++;
	s1[1] = 5;
	s1[4];

	s1.print(); //1->5 2->1 3->1 4->0
	cout << "Size: " << s1.size() << endl; //4
	cout << s1.erase(7) << endl; //0
	cout << s1.erase(2) << endl; //1
	s1.print(); //1->5 3->1 4->0
	cout << "Size: " << s1.size() << endl; //3

	Map<int, unsigned> s2 = s1;

	s2.print(); //1->5 3->1 4->0
	s2[5] = 3;
	s2.print(); //1->5 3->1 4->0 5->3

	s1 = s2;
	
	if (s1 == s2)
		cout << "The sets are equal." << endl; //yes

	cout << s1.count(7) << endl; //0
	cout << s1.count(4) << endl; //1
	cout << s1.erase(4) << endl; //1
	s1.print(); //1->5 3->1 5->3
	s2.print(); //1->5 3->1 4->0 5->3

	s2.clear();
	s1.print(); //1->5 3->1 5->3
	s2.print(); //empty

	return 0;
}

