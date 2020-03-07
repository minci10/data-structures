/*
Define the Fraction structure representing vulgar fractions.
Implement the following public methods of the structure:
• the default constructor creating the fraction being the zero value,
• the constructor with two parameters for the nominator and the denominator of the
fraction (the denominator should have a default value),
• the printing method,
• the comparison operators <, <=, >, >=, == and !=,
• the arithmetic operators +, - (unary and binary) , * and /,
• the method converting the fraction to a real value.
Write a program which tests all the structure capabilities.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>

struct Fraction {

private:
	int nom;
	int denom; 

public:
	Fraction(int = 0, int = 1);
	void print() const;
	bool operator==(const Fraction &right) const;
	bool operator<(const Fraction &right) const;
	bool operator>(const Fraction &right) const;
	bool operator>=(const Fraction &right) const;
	bool operator<=(const Fraction &right) const;
	bool operator!=(const Fraction &right) const;
	Fraction operator*(const Fraction &right) const;
	Fraction operator+(const Fraction &right) const;
	Fraction operator-(const Fraction &right) const;
	Fraction operator/(const Fraction &right) const;
	void realValue();
	int gcd_Finder(int,int) const;

};

Fraction::Fraction(int n, int d) {

	if (d == 0) throw std::invalid_argument("Wrong denominator");
	if (d<0) {

		d = -d;
		n = -n;

	}

	nom = n;
	denom = d;

}

void Fraction::print() const {

	int gcd = gcd_Finder(nom,denom);
	std::cout << nom/gcd << "/" << denom/gcd << std::endl;

}

bool Fraction::operator== (const Fraction &right) const {

	return nom * right.denom == denom * right.nom;

}

bool Fraction::operator< (const Fraction &right) const {

	return nom * right.denom < denom * right.nom;

}

bool Fraction::operator> (const Fraction &right) const {

	return nom * right.denom > denom * right.nom;

}

bool Fraction::operator>= (const Fraction &right) const {

	return nom * right.denom >= denom * right.nom;

}

bool Fraction::operator<= (const Fraction &right) const {

	return nom * right.denom <= denom * right.nom;

}

bool Fraction::operator!= (const Fraction &right) const {

	return nom * right.denom != denom * right.nom;

}

Fraction Fraction::operator* (const Fraction &right) const {

	int res_nom = nom*right.nom;
	int res_denom = denom*right.denom;
	int gcd = gcd_Finder(res_nom, res_denom);
	return Fraction(res_nom / gcd, res_denom / gcd);

}

Fraction Fraction::operator+ (const Fraction &right) const {

	int res_nom = (right.denom*nom) + (denom*right.nom);
	int res_denom = denom*right.denom;
	int gcd = gcd_Finder(res_nom,res_denom);
	return Fraction(res_nom/gcd,res_denom/gcd);

}

Fraction Fraction::operator- (const Fraction &right) const {

	int res_nom = (right.denom*nom) - (denom*right.nom);
	int res_denom = denom*right.denom;
	int gcd = gcd_Finder(res_nom, res_denom);
	return Fraction(res_nom / gcd, res_denom / gcd);

}

Fraction Fraction::operator/ (const Fraction &right) const {

	int res_nom = nom*right.denom;
	int res_denom = denom*right.nom;
	int gcd = gcd_Finder(res_nom, res_denom);
	return Fraction(res_nom / gcd, res_denom / gcd);

}

void Fraction::realValue() {

	std::cout << (float)nom/(float)denom << std::endl;

}

int Fraction::gcd_Finder(int a , int b) const {

	if (a == 0 || b == 0)
	{
		return 1;
	}

	a = abs(a);
	b = abs(b);

	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;

}


int main()
{

	Fraction f1, f2(5), f3(1, 3), f4(2, 4) , f5(3,-5);

	f1.print();
	f2.print();
	f4.print();
	f1.realValue();
	f2.realValue();
	f3.realValue();
	if (f3 == f4) {
		//if(f3.operator==(f4))
		std::cout << "f3 is equal to f4" << std::endl;
	}
	if (f3 < f4)
	{
		std::cout << "f3 is less than f4" << std::endl;
	}
	if (f2 >= f3)
	{
		std::cout << "f2 is greater than or equal to f3" << std::endl;
	}
	if (f4 != f5)
	{
		std::cout << "f4 is not equal to f5" << std::endl;
	}
	f1 = f3 + f5;
	f1.print();
	f1 = f3 - f2;
	f1.print();
	f1 = f4 * f5;
	f1.print();
	f1 = f2 * f3;
	f1.print();
	f1 = f2 / f5;
	f1.print();
	return 0;

}

