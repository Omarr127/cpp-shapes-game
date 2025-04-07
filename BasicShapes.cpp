#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include <fstream>

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	initialHght = r_hght;
	initialWdth = r_wdth;
	hght = r_hght;
	wdth = r_wdth;

}

void Circle::move(point p)
{
	RefPoint.x += p.x;
	RefPoint.y += p.y;
}
void Triangle::move(point p)
{
	RefPoint.x += p.x;
	RefPoint.y += p.y;
	rotate(); rotate(); rotate(); rotate();
}
void Rect::move(point p)
{
	RefPoint.x += p.x;
	RefPoint.y += p.y;
}



void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerRight;
	upperLeft.x = RefPoint.x - wdth / 2.0;
	upperLeft.y = RefPoint.y - hght / 2.0;
	lowerRight.x = RefPoint.x + wdth / 2.0;
	lowerRight.y = RefPoint.y + hght / 2.0;
	pW->DrawRectangle((int)upperLeft.x, (int)upperLeft.y, (int)lowerRight.x, (int)lowerRight.y, FILLED);
}
point Rect::getref() const {
	return RefPoint;
}
void Rect::rotate()
{
	int temp;
	temp = hght;
	hght = wdth;
	wdth = temp;
}
void Rect::resize(double size)
{
	hght *= size;
	wdth *= size;
}

void Rect::VerticalFlip()
{
	draw();
}

////////////////////////////////////////////////////  class Circle  ///////////////////////////////////////
Circle::Circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	radius = r;
	initialRadius = r;

}
void Circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle((int)RefPoint.x, (int)RefPoint.y, (int) radius, FILLED);
}

void Circle::rotate()
{
	draw();
}
void Circle::resize(double size)
{
	radius *= size;
}
void Circle::VerticalFlip()
{
	draw();
}
point Circle::getref() const {
	return RefPoint;
}


//////////////////////////////////////////////////  class Triangle  ///////////////////////////////////////
Triangle::Triangle(game* r_pGame, point ref, int wdth, int hght) :shape(r_pGame, ref)
{
	height = hght;
	width = wdth;
	angle = 0;

	vertex_1 = { RefPoint.x - width / 2, RefPoint.y + height / 2 };
	vertex_2 = { RefPoint.x, RefPoint.y - height / 2 };
	vertex_3 = { RefPoint.x + width / 2, RefPoint.y + height / 2 };


}
void Triangle::draw() const
{

	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawTriangle(vertex_1.x, vertex_1.y, vertex_2.x, vertex_2.y, vertex_3.x, vertex_3.y, FILLED);
}
void Triangle::rotate() {
	
	angle += 90.0;
	double a = angle * 0.017453292519943295769236907684886127134428718885417254560971914401710091146034494436822415696345094822123044925073790592483854692275281012398474218934047117319168245015010769561697553581238605305168789;
	double cos90 = cos(a);
	double sin90 = sin(a);

	point vertices[3] = { {RefPoint.x - width / 2, RefPoint.y + height / 2 },  {RefPoint.x, RefPoint.y - height / 2 },{RefPoint.x + width / 2, RefPoint.y + height / 2} };

	for (int i = 0; i < 3; ++i) {
		double newX = cos90 * (vertices[i].x - RefPoint.x) - sin90 * (vertices[i].y - RefPoint.y) + RefPoint.x;
		double newY = sin90 * (vertices[i].x - RefPoint.x) + cos90 * (vertices[i].y - RefPoint.y) + RefPoint.y;

		vertices[i].x = newX;
		vertices[i].y = newY;

	}
	vertex_1 = vertices[0];
	vertex_2 = vertices[1];
	vertex_3 = vertices[2];

}
void Triangle::resize(double size)
{
	height *= size;
	width *= size; rotate(); rotate(); rotate(); rotate();
}
point Triangle::getref() const {
	return RefPoint;
}
void Triangle::VerticalFlip()
{

}
