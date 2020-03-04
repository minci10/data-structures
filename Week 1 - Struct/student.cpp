/*
Define the Student structure with the following fields: a forename, a surname (being strings), an index number being an integer number 
and an array/list of his marks (empty by default, you are allowed to limit the number of students's marks). 
Implement the following methods of the structure:
• the constructor with parameters for the first three fields of the student with some empty/zero default values,
• set & get methods for the first three fields of the student (i.e., getSurname, setSurname, etc.),
• addMark – adding a new mark (given as a parameter) for the student (check if the mark is correct, e.g. between 2 and 5),
• avgGrade – computing the average grade for the student by calculating the arithmetic mean of his marks,
• print – printing all the data of the student.
Test all the structure capabilities – create an array of the students and let the user manage them.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

struct Student {
private:
	std::string forename;
	std::string surname;
	int index;
	int mark_counter;
	int marks[10];
public:
	Student(std::string="",std::string="",int = 0);
	void setForename(std::string);
	std::string getForename()const;
	void setSurname(std::string);
	std::string getSurname()const;
	void setIndex(int);
	int getIndex()const;
	void setMarkcounter(int);
	void addMark(int);
	void avgGrade();
	void print();
};

Student::Student(std::string fn, std::string sn, int idx) {
	forename = fn;
	surname = sn;
	index = idx;
	mark_counter = 1;
	for (int i = 0; i < 10; i++)
	{
		marks[i] = 0;
	}

}

void Student::setForename(std::string s1) {
	forename = s1;
}

std::string Student::getForename()const {
	return forename;
}

void Student::setSurname(std::string s2) {
	surname = s2;
}

std::string Student::getSurname()const {
	return surname;
}

void Student::setIndex(int n1) {
	index = n1;
}

int Student::getIndex()const {
	return index;
}

void Student::setMarkcounter(int n1) {
	mark_counter = n1;
}


void Student::addMark(int n2) {

		if (mark_counter > 0)
		{
			if (n2 <= 5 && n2>=2)
			{
             marks[mark_counter-1] = n2;
			}
			else {
				marks[mark_counter-1] = 0;
			}
		}
		mark_counter--;
}

void Student::avgGrade() {

	double sum = 0;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (marks[i] == 0)
		{
			break;
		}
		 sum += marks[i];
	}
	double avg = sum / i;
	std::cout << "Average : " << avg << std::endl;
}

void Student::print() {

	std::cout << forename << " " << surname << std::endl;
	std::cout << "Marks: " << std::endl;
	for (int i = 0; i < sizeof(marks) ; i++)
	{
		if (marks[i] == 0)
		{
			break;
		}
		std::cout << marks[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	Student std[5];
	std[0].setForename("Muhammet");
	std[0].setSurname("Inci");
	std[0].setMarkcounter(3);
	std[0].addMark(3);
	std[0].addMark(4);
	std[0].addMark(4);
	std[0].print();
	std[0].avgGrade();
    return 0;
}

