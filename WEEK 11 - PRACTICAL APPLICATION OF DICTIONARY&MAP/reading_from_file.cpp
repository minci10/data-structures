/*
Write a program which reads all the words from a text file and counts them (use the
dictionary implemented in task 1 using words as keys and numbers as values associated).
Allow the user to:
- give the input file name,
- print alphabetically the unique words stored in the dictionary together with the number of
their occurences,
- remove a word from the dictionary,
- check if a word is in the dictionary.
Try to change the program to be able to count all the characters included in the text file.
*/

#include "stdafx.h"
#include "map.h"
#include <iostream>
#include <fstream>


int main()
{
	string fileName;
	cout << "Give the name of the file : ";
	// You can use map.h
	cin >> fileName;

	ifstream in(fileName);
	if (!in) return 1;
	/*
	Map<string, int> counting;
	string word;

	while (in >> word)  //!in.eof()
	{
		counting[word]++; 
	}
	if (counting.count("while") != 0)
	{
		counting.erase("while");
	}
	*/
	
	Map<char, int> counting;
	char ch;

	while (in >> ch)  //!in.eof()
	{
		counting[ch]++;
	}
	if (counting.count('a') != 0)
	{
		counting.erase('a');
	}
	

	in.close();
	counting.print();


    return 0;
}

