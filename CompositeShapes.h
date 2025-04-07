#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	virtual void rotate();
	/*virtual void verticalFlip();*/
	virtual void VerticalFlip();
	virtual void move(point p);
	


};


////////////////////////////////////////////////////  class House  ///////////////////////////////////////
class House :public shape
{
	Triangle* roof;
	Rect* building;

public:
	House(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	virtual void VerticalFlip(); 
	/*virtual void move();*/
	virtual void rotate();
	virtual void move(point p);

};


////////////////////////////////////////////////////  class Car  ///////////////////////////////////////
class Car :public shape
{
	Triangle* top;
	Rect* base;
	Circle* leftwheel;
	Circle* rightwheel;
public:
	Car(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	/*virtual void move(int dx, int dy);*/
	virtual void rotate();
	virtual void VerticalFlip();
	virtual void move(point p);
};


////////////////////////////////////////////////////  class iceCream  ///////////////////////////////////////
class IceCream :public shape
{
	Circle* top;
	Triangle* bottom;
public:
	IceCream(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	/*virtual void move(int dx, int dy);*/
	virtual void rotate();
	virtual void VerticalFlip();
	virtual void move(point p);
};


////////////////////////////////////////////////////  class Tree  ///////////////////////////////////////
class Tree :public shape
{
	Triangle* triangle1;
	Triangle* triangle2;
	Triangle* triangle3;
	Rect* base;
public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	/*virtual void move(int dx, int dy);*/
	virtual void rotate();
	virtual void VerticalFlip();
	virtual void move(point p);
};


////////////////////////////////////////////////////  class Shape5  ///////////////////////////////////////
class Butterfly :public shape
{
	Triangle* Lwing;
	Triangle* Rwing;
	Rect* body;
	Circle* head;

public:
	Butterfly (game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	virtual void rotate();
	virtual void VerticalFlip();
	virtual void move(point p);
};


////////////////////////////////////////////////////  class Shape6  ///////////////////////////////////////
class Castle :public shape
{
	Rect* base;
	Triangle* l_triangle;
	Triangle* r_triangle;
	Circle* c_circle;
public:
	Castle(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void resize(double);
	virtual void rotate();
	virtual void VerticalFlip();
	virtual void move(point p);
	
};
