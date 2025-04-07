#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	double x, y;
};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign

	//TODO: Add more types
};
enum direction
{
	Right,
	Up,
	Left,
	Down
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	point Position;    // position of the shape
	int gridHeight, gridWidth;
	int rotateCount = 0;
	int flipCount = 0;
	int resizeUpCount=0;
	int resizeDownCount=0;
	int moveCount;
public:
    shape(game* r_pGame, point ref);
    virtual void draw() const=0;//for a shape to draw itself on the screen

	void setRefPoint(point p);
								  
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	
	shape* getActiveShape()const;
	virtual void rotate() = 0;	//Rotate the shape
	virtual void resize(double) = 0;	//Resize the shape
	virtual void VerticalFlip() = 0;	// VerticalFlip of the shape
	virtual void move(point p) = 0;		/***////Move the shape
	void save(ofstream& OutFile);	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	
};

