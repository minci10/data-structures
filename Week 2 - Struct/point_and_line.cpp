/*
. Define and implement two structures – the Point and the Line being geometric structures in
two-dimensional space. The structure Point should contain at least the following public methods:
• the default constructor assigning zero to all the coordinates of the point,
• the constructor with two parameters for the coordinates of the point,
• getX – returning the x-coordinate of the point,
• getY – returning the y-coordinate of the point,
• setX – setting the x-coordinate of the point,
• setY – setting the y-coordinate of the point,
• distance - computing the distance between this point and the second one given as the parameter.
The structure Line should contain at least the following public methods:
• the default constructor assigning zero to all the coefficients of the line,
• the constructor with two parameters for the directional (a) and the free coefficient (b) 
of the line in form of y=ax+b,
• the constructor with two points as the parameters,
• distance – computing the distance between the line and a point given as the parameter,
• isOnLine – checking wheter a point given as the parameter belongs to the line,
• orthogonalLine – returning a new line orthogonal to this line and containing a point given as the parameter.
Write the testing program which should create at least two points and one line given by the
user and test all the capabilities of the structures.
*/

#include "stdafx.h"
#include <iostream>

struct Point {

private:

	float x;
	float y;

public:

	Point(float = 0,float = 0);
	float getX()const;
	void setX(float);
	float getY()const;
	void setY(float);
	float distance(const Point &p)const;

};

Point::Point(float a,float b) {

	x = a;
	y = b;

}

void Point::setX(float crdx) {

	x = crdx;

}

void Point::setY(float crdy) {

	y = crdy;

}

float Point::getX() const {

	return x;

}

float Point::getY() const {

	return y;

}

float Point::distance(const Point &p)const {

	return sqrt(pow((p.y-y),2)+pow((p.x-x),2));
	
}


struct Line {

private:

	float a;
	float b;

public:

	Line(float=0,float=0);
	void print();
	float distance(const Point &p)const;
	bool isOnLine(const Point &p)const;
	Line orthogonalLine(const Point &p)const;

};


Line::Line(float k,float l) {
                  
	a = k;     
	b = l;

}

void Line::print() {

	std::cout << a << "x+(" << b << ")" << std::endl;

}

float Line::distance(const Point &p)const {

	return abs(a*p.getX() - p.getY() + b) / sqrt(pow(a, 2) + 1);

}

bool Line::isOnLine(const Point &p) const{

	return p.getY() == a*p.getX() + b;

}

Line Line::orthogonalLine(const Point &p) const {

	float c1 = (-1) / a;
	float c2 = p.getY() - c1 * p.getX();
	return Line(c1,c2);

}


int main()
{

	Point p1,p2(2),p3(-3, -4);
	std::cout << "coordinats of p2: " << "(" << p2.getX() << "," << p2.getY() << ")" << std::endl;
	float dist = p1.distance(p3);
	std::cout << "distances between p1 and p3: " << dist << std::endl;
	Line l1(2,-4);
	l1.print();
	float dist2 = l1.distance(p3);
	std::cout << "distances between l1 and p3: " << dist2 << std::endl;
	if (l1.isOnLine(p2))
	{
		std::cout << "p2 is on the l1" << std::endl;
	}
	Line l2(5,3);
	Point p4(3,0);
	Line ln = l2.orthogonalLine(p4);
	ln.print();
	return 0;


}
 
