/*
The program should use all these methods to make the operations as follows:
1) create a set of integers containing the numbers given by the user,
2) print the number of items stored in the set,
3) remove a value from the set,
4) print the number of items stored in the set,
5) check if a given value is in the set,
6) clear the set.
Compare your implementation of the container with the built-in container set delivered in the <set> library
*/

#include "stdafx.h"
#include "unbounded_sorted_set.h"
//#include <set>

using namespace std;


int main()
{
	
    Set<int> s1;

    s1.insert(3);
    s1.insert(2);
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);

    s1.print(); //1 2 3 4
    cout << "Size: " << s1.size() << endl; //4
    cout << s1.erase(7) << endl; //0
    cout << s1.erase(3) << endl; //1
    s1.print(); //1 2 4
    cout << "Size: " << s1.size() << endl; //3

    Set<int> s2 = s1;

    s2.print(); //1 2 4
    s2.insert(5);
    s2.print(); //1 2 4 5

    s1 = s2;

    if(s1 == s2)
       cout << "The sets are equal." << endl; //yes
	
    cout << s1.count(7) << endl; //0
    cout << s1.count(2) << endl; //1
    cout << s1.erase(2) <<endl; //1
    s1.print(); //1 4 5
    s2.print(); //1 2 4 5
				
    s2.clear();
    s1.print(); //1 4 5
    s2.print(); //empty

    return 0;
}

