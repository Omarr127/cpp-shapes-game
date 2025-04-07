#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include<fstream>
#include<vector> 
shape::shape(game* r_pGame, point ref):rotateCount(0), flipCount(0), resizeUpCount(0), resizeDownCount(0), moveCount(0)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
shape* shape::getActiveShape() const
{
	return nullptr;
}
void shape::VerticalFlip()
{}
void shape::resize(double)
{}
void shape::rotate()
{}

//class move_shape :public operation
//{
//public:
//	move_shape(game* r_pGame);
//	virtual void Act();
//};
//void shape::MoveUp()
//{
//    // Check if moving up will keep the shape within the grid
//    if (RefPoint.y - 1 >= 0)
//    {
//        // Move the shape up by decrementing the y-coordinate
//        RefPoint.y -= 1;
//    }
//}
//void shape::MoveDown()
//{
//    // Check if moving down will keep the shape within the grid
//    if (RefPoint.y + 1 < gridHeight)
//    {
//        // Move the shape down by incrementing the y-coordinate
//        RefPoint.y += 1;
//    }
//}
//
//void shape::MoveLeft()
//{
//    // Check if moving left will keep the shape within the grid
//    if (RefPoint.x - 1 >= 0)
//    {
//        // Move the shape left by decrementing the x-coordinate
//        RefPoint.x -= 1;
//    }
//}
//
//void shape::MoveRight()
//{
//    // Check if moving right will keep the shape within the grid
//    if (RefPoint.x + 1 < gridWidth)
//    {
//        // Move the shape right by incrementing the x-coordinate
//        RefPoint.x += 1;
//    }
//}
void shape::save(ofstream& OutFile)
{
	OutFile << RefPoint.x << " " << RefPoint.y << " " << resizeUpCount << " " << resizeDownCount << " " << moveCount << " " << rotateCount;
}

