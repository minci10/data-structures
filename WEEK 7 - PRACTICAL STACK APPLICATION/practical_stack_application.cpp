/*
Write a program which checks whether in a string given by the user all parentheses, brackets
and braces are balanced. For example, the following strings contain balanced parentheses:
([]())
([])([]{}{()}[])
Examples of imbalanced ones are:
([)]
([])([]{}{())}[])
To solve the problem use an unbounded stack as a template structure.
*/

#include "stdafx.h"
#include "stack_template.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;	

int main()
{

	string str;
	cout << "Type the parantheses : " << endl;
	cin >> str;
	Stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '(' && str[i] != '[' && str[i] != '{' && str[i] != ')' && str[i] != ']' && str[i] != '}')
		{
			throw logic_error("Unknown character has been typed");
		}
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}

		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (s.empty())
			{
				s.push(str[i]);
				break;
			}
			else if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{'))
			{
				s.pop();
			}
			else {
				break;
			}

		}

	}


	if (s.empty() == true)
	{
		cout << "Given string contains balanced paranheses" << endl;
	}

	else {

		cout << "Not balanced" << endl;

	}


    return 0;
}

