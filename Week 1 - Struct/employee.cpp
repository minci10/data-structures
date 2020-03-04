/* 
Define and implement a structure of an employee with the following fields: a forename, a surname,
a position (being strings) and a salary being a real number. Implement the following methods of the structure:
• the constructor with parameters for the all necessary fields of the employee (some of them may have the default values),
• set & get methods for all the fields of the employee (i.e., getSalary, setSalary, etc.),
• incSalary – increasing the salary of the employee by the value given as a parameter,
• print – printing all the data of the employee.
Test all the structure capabilities – create an array of the employees and let the user manage them.
*/

#include "Stdafx.h";
#include <iostream>
#include <string>

struct Employee {

private:
	
	std::string forename;
	std::string surname;
	std::string position;
	double salary;


public:
	
	Employee(std::string,std::string,std::string);
	void setSalary(double);
	double getSalary()const;
	void setForename(std::string);
	std::string getForename()const;
	void setSurname(std::string);
	std::string getSurname()const;
	void setPosition(std::string);
	std::string getPosition()const;
	void incSalary(double);
	void print()const;

};

Employee::Employee(std::string name="",std::string secondname="",std::string pos="") {

	forename = name;
	surname = secondname;
	position = pos;
	salary = 0;

}

void Employee::setSalary(double slr) {

	if (slr >= 0)
	{
     salary = slr;
	}
}

double Employee::getSalary()const {

	return salary;

}

void Employee::setForename(std::string frn) {
	
		forename = frn;

}

std::string Employee::getForename()const {

	return forename;

}

void Employee::setSurname(std::string srn) {

	surname = srn;

}

std::string Employee::getSurname()const {

	return surname;

}

void Employee::setPosition(std::string pst) {

	position = pst;

}

std::string Employee::getPosition()const {

	return position;

}

void Employee::incSalary(double inc) {

	salary += inc;

}

void Employee::print()const {

	std::cout << "Name : " << forename << std::endl;
	std::cout << "Surname : " << surname << std::endl;
	std::cout << "Position : " << position << std::endl;
	std::cout << "Salary : " << salary << std::endl;

}


int main()
{

	Employee emp[5];
	emp[0].setForename("Muhammet");
	emp[0].setSurname("Inci");
	emp[0].setPosition("CEO");
	emp[0].setSalary(15000);
	emp[0].print();

	return 0;
}

