//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth, initialHght, initialWdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw() const;
	virtual void rotate();
	virtual void resize(double);
	void VerticalFlip();
	void flip();
	point getref() const;
	virtual void move(point p);
};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class Circle :public shape
{
	//Add data memebrs for class circle
	int radius;
	int initialRadius;
	int rad;
	double centerx, centery;
public:	
	Circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	virtual void draw() const;
	virtual void rotate();
	virtual void resize(double);
	virtual void VerticalFlip();
	point getref() const;
	virtual void move(point p);
 
};



////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//Reference point of the triangle is its centroid
class Triangle :public shape
{
	//Add data memebrs for class traingle
	int height;  // the height length equalls the base length
	int width;
	point vertex_1, vertex_2, vertex_3;
	//int orientation = 0; 
	int angle; 
	//double vertex1x, vertex1y; // Coordinates of first vertex
	//double vertex2x, vertex2y; // Coordinates of second vertex
	//double vertex3x, vertex3y; // Coordinates of third vertex
public:
	Triangle(game* r_pGame, point ref, int hght,int wdth);	//add more parameters for the constructor if needed
	virtual void draw() const;
	virtual void rotate();
	virtual void resize(double);
	void VerticalFlip();
	point getref() const;
	virtual void move(point p);
};
