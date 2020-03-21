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

#include "stdafx.h"
#include "bounded_stack.h"


int main()
{

	Stack s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.print();
	s1.pop();
	s1.pop();
	s1.print();
	std::cout << "The top element is " << s1.top() << std::endl;
	if (!s1.empty())
	{
		std::cout << "Stack is not empty and has " << s1.size() << " element" <<std::endl;
	}
	Stack s2 = s1;
	s2.print();
	if (s1==s2)
	{
		std::cout << "These two stacks are equal" << std::endl;
	}
	s2.pop();
	s2.print();
	s1.clear();
	s2.clear();
	
    return 0;
}

