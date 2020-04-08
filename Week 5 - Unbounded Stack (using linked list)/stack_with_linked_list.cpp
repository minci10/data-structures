/*
The program should use all these methods to make the operations as follows:
1) create a stack containing the numbers given by the user,
2) print the contents of the stack,
3) remove two values from the stack and print them,
4) print the top number,
5) print the number of values on the stack if it is nonempty, or an appropriate message
otherwise,
6) clear the stack.
*/


#include "stack_with_linked_list.h"


int main()
{

	Stack s1;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

	s1.print(); //5 4 3 2 1
	std::cout << "Size: " << s1.size() << std::endl; //5
	std::cout << "Pop: " << s1.pop() << std::endl; //5
	std::cout << "Size: " << s1.size() << std::endl; //4
	std::cout << "Top: " << s1.top() << std::endl; //4
	s1.print(); //4 3 2 1

	Stack s2 = s1;

	s2.print(); //4 3 2 1
	s2.push(6);
	s2.print(); //6 4 3 2 1

	s1 = s2;

	if (s1 == s2)
		std::cout << "The stacks are equal." << std::endl; //yes

	std::cout << "Pop: " << s1.pop() << std::endl; //6
	s1.print(); //4 3 2 1
	s2.print(); //6 4 3 2 1

	s2.clear();
	s1.print(); //4 3 2 1
	s2.print(); //empty

	
    return 0;
}

