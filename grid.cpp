#include "grid.h"
#include "game.h"
#include "gameConfig.h"


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}


void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}
shape* grid::getActiveShape() 
{
	return activeShape;
}
//void grid::deleteshape(shape* pShape)
//{
//	for (int i = 0; i < shapeCount; i++)
//	{
//		if (shapeList[i] == pShape)
//		{
//			// Delete the shape from the list by shifting elements
//			for (int j = i; j < shapeCount - 1; j++)
//			{
//				shapeList[j] = shapeList[j + 1];
//			}
//			shapeList[shapeCount - 1] = nullptr; // Clear the last element
//			shapeCount--; // Decrement shape count
//			break; // Exit the loop once shape is found and deleted
//		}
//	}
//}  

//Delete function
void grid::clearGrid()
{
	delete activeShape;
	activeShape = nullptr;
	this->draw();

}

//void grid::resize()
//{
//	clearGridArea();
//	window* pWind = pGame->getWind();
//
//	pWind->SetPen(config.gridDotsColor, 1);
//	pWind->SetBrush(config.gridDotsColor);
//
//	//draw dots showing the grid reference points
//	for (int r = 1; r < rows; r++)
//		for (int c = 0; c < cols; c++)
//			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
//	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);
//
////Draw ALL shapes
//	for (int i = 0; i < shapeCount; i++)
//		if (shapeList[i])
//			shapeList[i]->draw();	//draw each shape
//
//	//Draw the active shape
//	if (activeShape)
//		activeShape->resize(*config.SignSize);
//}



void grid::rotate()
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->rotate();
}
void grid::verticalFlip()
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if (activeShape)
		activeShape->rotate();
}
int grid::getshapecount()
{
	return shapeCount;
}

 shape** grid::shapelist()
{
	return shapeList;
}
 bool grid::checkList() const
 {
	 int c = 0;
	 for (int i = 0; i < shapeCount; i++)
	 {
		 if (shapeList[i] == nullptr)
		 {
			 c++;
		 }
	 }
	 if (c == shapeCount)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }