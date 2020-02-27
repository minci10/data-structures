
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

