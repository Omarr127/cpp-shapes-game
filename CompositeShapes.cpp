#include "CompositeShapes.h"
#include "gameConfig.h"
#include <cmath>
#include<fstream>




void IceCream::move(point p) 
{
	top->move(p);
	bottom->move(p);
}

void Castle::move(point p)
{
	base->move(p);
	c_circle->move(p);
	l_triangle->move(p);
	r_triangle->move(p);
}

void Butterfly::move(point p)
{
	body->move(p);
	Lwing->move(p);
	Rwing->move(p);
	head->move(p);
}
void Tree::move(point p)
{
	base->move(p);
	triangle1->move(p);
	triangle2->move(p);
	triangle3->move(p);
}
void Car::move(point p)
{
	base->move(p);
	top->move(p);
	leftwheel->move(p);
	rightwheel->move(p);
}
void House::move(point p)
{
	building->move(p);
	roof->move(p);


}
void Sign::move(point p)
{
	base->move(p);
	top->move(p);
}










////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}
void Sign::draw() const
{
	base->draw();
	top->draw();
}
void Sign::resize(double size)
{		
point newbase;
newbase = { (base->getref().x - top->getref().x) * size + top->getref().x, (base->getref().y - top->getref().y) * size + top->getref().y};
base->setRefPoint(newbase);
top->resize(size);
base->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) {
		resizeDownCount++;
	 };
	}
void Sign::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (base->getref().x - top->getref().x) * rotcos - (base->getref().y - top->getref().y) * rotsin + top->getref().x;
	newrefp.y = (base->getref().y - top->getref().y) * rotcos + (base->getref().x - top->getref().x) * rotsin + top->getref().y;

	base->setRefPoint(newrefp);
	base->rotate();
	top->rotate();
	rotateCount++;
}
void Sign::VerticalFlip()
{
	rotate(); rotate();
	flipCount++;
	
}



House::House(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point buildingRef = ref;
	point roofRef = { ref.x, ref.y - config.HouseShape.baseHeight / 2 - config.HouseShape.topHeight / 2 };


	building = new Rect(pGame, buildingRef, config.HouseShape.baseHeight, config.HouseShape.baseWidth);
	roof = new Triangle(pGame, roofRef, config.HouseShape.topWidth, config.HouseShape.topHeight);

}
void House::draw() const
{
	building->draw();
	roof->draw();


}
void House::resize(double size)
{
point newroof, newWindow;
newroof = { (roof->getref().x - building->getref().x) * size + building->getref().x, (roof->getref().y - building->getref().y) * size + building->getref().y};
roof->setRefPoint(newroof);;
roof->resize(size);
building->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) {
		resizeDownCount++;
	};

}
void House::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (roof->getref().x - building->getref().x) * rotcos - (roof->getref().y - building->getref().y) * rotsin + building->getref().x;
	newrefp.y = (roof->getref().y - building->getref().y) * rotcos + (roof->getref().x - building->getref().x) * rotsin + building->getref().y;

	roof->setRefPoint(newrefp);
	roof->rotate();
	building->rotate();
	rotateCount++;

}
void House::VerticalFlip()
{
	rotate(); rotate();
	flipCount++;

}


Car::Car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point topRef = { ref.x - config.CarShape.baseWidth / 6, ref.y - config.CarShape.baseHeight/1.2 };
	point leftwheelRef = { ref.x - config.CarShape.baseWidth / 4, ref.y + config.CarShape.baseHeight/2 };
	point rightwheelRef = { ref.x + config.CarShape.baseWidth / 4, ref.y + config.CarShape.baseHeight/2 };

	base = new Rect(pGame, baseRef, config.CarShape.baseHeight, config.CarShape.baseWidth);
	top = new Triangle(pGame, topRef, config.CarShape.topHeight, config.CarShape.topWidth);
	leftwheel = new Circle(pGame, leftwheelRef, config.CarShape.wheelRadius);
	rightwheel = new Circle(pGame, rightwheelRef, config.CarShape.wheelRadius);
}
void Car::draw() const
{
	base->draw();
	top->draw();
	leftwheel->draw();
	rightwheel->draw();
}
void Car::resize(double size)
{

	point newtop;
	newtop = { (top->getref().x - base->getref().x * size + base->getref().x, (top->getref().y - base->getref().y) * size + base->getref().y) };
	top->setRefPoint(newtop);
	top->resize(size);
	point newleftwheel;
	newleftwheel = { (leftwheel->getref().x - base->getref().x) * size + base->getref().x, (leftwheel->getref().y - base->getref().y) * size + base->getref().y };
	leftwheel->setRefPoint(newleftwheel);
	leftwheel->resize(size);
	point newrightwheel;
	newrightwheel = { (rightwheel->getref().x - base->getref().x) * size + base->getref().x, (rightwheel->getref().y - base->getref().y) * size + base->getref().y };
	rightwheel->setRefPoint(newrightwheel);
	rightwheel->resize(size);

	base->resize(size);
	rightwheel->resize(*config.CarSize);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) { resizeDownCount++;;
	};
}
void Car::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point nlwheel;
	nlwheel.x = (leftwheel->getref().x - base->getref().x) * rotcos - (leftwheel->getref().y - base->getref().y) * rotsin + base->getref().x;
	nlwheel.y = (leftwheel->getref().y - base->getref().y) * rotcos + (leftwheel->getref().x - base->getref().x) * rotsin + base->getref().y;

	leftwheel->setRefPoint(nlwheel);
	leftwheel->rotate();

	point nrwheel;
	nrwheel.x = (rightwheel->getref().x - base->getref().x) * rotcos - (rightwheel->getref().y - base->getref().y) * rotsin + base->getref().x;
	nrwheel.y = (rightwheel->getref().y - base->getref().y) * rotcos + (rightwheel->getref().x - base->getref().x) * rotsin + base->getref().y;

	rightwheel->setRefPoint(nrwheel);
	rightwheel->rotate();
	base->rotate();

	point ntop;
	ntop.x = (top->getref().x - base->getref().x) * rotcos - (top->getref().y - base->getref().y) * rotsin + base->getref().x;
	ntop.y = (top->getref().y - base->getref().y) * rotcos + (top->getref().x - base->getref().x) * rotsin + base->getref().y;

	top->setRefPoint(ntop);
	top->rotate();
	rotateCount++;
}
void Car::VerticalFlip()
{
	rotate(); rotate();
	flipCount++;
	
}




IceCream::IceCream(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point topRef = ref;
	point bottomRef = { ref.x, ref.y + config.iceCreamShape.bottomHeight / 1.5 };

	top = new Circle(pGame, topRef, config.iceCreamShape.topRadius);
	bottom = new Triangle(pGame, bottomRef, config.iceCreamShape.bottomWidth, -config.iceCreamShape.bottomHeight);

}
void IceCream::draw() const
{
	top->draw();
	bottom->draw();
}
void IceCream::resize(double size)
{
	point newbottom;
	newbottom = { (bottom->getref().x - top->getref().x) * size + top->getref().x, (bottom->getref().y - top->getref().y) * size + top->getref().y};
	bottom->setRefPoint(newbottom);
	bottom->resize(size);
	top->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) { resizeDownCount++; 
	};
}
void IceCream::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newbottom;
	newbottom.x = (bottom->getref().x - top->getref().x) * rotcos - (bottom->getref().y - top->getref().y) * rotsin + top->getref().x;
	newbottom.y = (bottom->getref().y - top->getref().y) * rotcos + (bottom->getref().x - top->getref().x) * rotsin + top->getref().y;
	bottom->setRefPoint(newbottom);

	bottom->rotate();
	rotateCount++;

}
void IceCream::VerticalFlip()
{

	rotate(); rotate();
	flipCount++;
	
}





Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point triangle1Ref = { ref.x, ref.y - config.TreeShape.baseHeight/1.5 };
	point triangle2Ref = { ref.x, ref.y - config.TreeShape.baseHeight / 1.2 };
	point triangle3Ref = { ref.x, ref.y - config.TreeShape.baseHeight / 0.99 };

	base = new Rect(pGame, baseRef, config.TreeShape.baseHeight, config.TreeShape.baseWidth);
	triangle1 = new Triangle(pGame, triangle1Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
	triangle2 = new Triangle(pGame, triangle2Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
	triangle3 = new Triangle(pGame, triangle3Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
}
void Tree::draw() const
{
	base->draw();
	triangle1->draw();
	triangle2->draw();
	triangle3->draw();
}
void Tree::resize(double size)
{
	point newtriangle3;
	newtriangle3 = { (triangle3->getref().x - base->getref().x) * size + base->getref().x, (triangle3->getref().y - base->getref().y) * size + base->getref().y};
	triangle3->setRefPoint(newtriangle3);
	triangle3->resize(size);

	point newtriangle2;
	newtriangle2 = { (triangle2->getref().x - base->getref().x) * size + base->getref().x, (triangle2->getref().y - base->getref().y) * size + base->getref().y };
	triangle2->setRefPoint(newtriangle2);
	triangle2->resize(size);

	point newtriangle1;
	newtriangle1 = { (triangle1->getref().x - base->getref().x) * size + base->getref().x, (triangle1->getref().y - base->getref().y) * size + base->getref().y };
	triangle1->setRefPoint(newtriangle1);
	triangle1->resize(size);

	base->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) { resizeDownCount++;
	}
}
void Tree::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newtriangle1;
	newtriangle1.x = (triangle1->getref().x - base->getref().x) * rotcos - (triangle1->getref().y - base->getref().y) * rotsin + base->getref().x;
	newtriangle1.y = (triangle1->getref().y - base->getref().y) * rotcos + (triangle1->getref().x - base->getref().x) * rotsin + base->getref().y;
	triangle1->setRefPoint(newtriangle1);
	triangle1->rotate();

	point newtriangle2;
	newtriangle2.x = (triangle2->getref().x - base->getref().x) * rotcos - (triangle2->getref().y - base->getref().y) * rotsin + base->getref().x;
	newtriangle2.y = (triangle2->getref().y - base->getref().y) * rotcos + (triangle2->getref().x - base->getref().x) * rotsin + base->getref().y;
	triangle2->setRefPoint(newtriangle2);

	triangle2->rotate();

	point newtriangle3;
	newtriangle3.x = (triangle3->getref().x - base->getref().x) * rotcos - (triangle3->getref().y - base->getref().y) * rotsin + base->getref().x;
	newtriangle3.y = (triangle3->getref().y - base->getref().y) * rotcos + (triangle3->getref().x - base->getref().x) * rotsin + base->getref().y;
	triangle3->setRefPoint(newtriangle3);

	triangle3->rotate();
	base->rotate();
	rotateCount++;
}
void Tree::VerticalFlip()
{
	rotate(); rotate();
	flipCount++;
}





Butterfly::Butterfly(game* r_pGame, point ref) :shape(r_pGame, ref)
{

	point bodyRef = ref;
	point LwingRef = { ref.x - (config.butterflyShape.bodyHeight / 4)    , ref.y  };
	point RwingRef = { ref.x + (config.butterflyShape.bodyHeight / 4)    , ref.y };
	point headRef = { ref.x, ref.y - config.butterflyShape.bodyWidth - 20 };

	
	body = new Rect(pGame, bodyRef, config.butterflyShape.bodyHeight, config.butterflyShape.bodyWidth);
	Lwing = new Triangle(pGame, LwingRef, config.butterflyShape.WingHeight, config.butterflyShape.WingWidth);
	Rwing = new Triangle(pGame, RwingRef, config.butterflyShape.WingHeight, config.butterflyShape.WingWidth);
	head = new Circle(pGame, headRef, config.butterflyShape.circleRadius);
	Rwing->rotate(); Rwing->rotate(); Rwing->rotate();	Lwing->rotate();
}
void Butterfly::draw() const
{
	body->draw();
	Lwing->draw();
	Rwing->draw();
	head->draw();
}
void Butterfly::resize(double size)
{
	point newLwing;
	newLwing = { (Lwing->getref().x - body->getref().x) * size + body->getref().x, (Lwing->getref().y - body->getref().y) * size + body->getref().y };
	Lwing->setRefPoint(newLwing);
	Lwing->resize(size);

	point newRwing;
	newRwing = { (Rwing->getref().x - body->getref().x) * size + body->getref().x, (Rwing->getref().y - body->getref().y) * size + body->getref().y };
	Rwing->setRefPoint(newRwing);
	Rwing->resize(size);

	point newhead;
	newhead = { (head->getref().x - body->getref().x) * size + body->getref().x, (head->getref().y - body->getref().y) * size + body->getref().y };
	head->setRefPoint(newhead);
	head->resize(size);

	body->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) { resizeDownCount++; 
	};
}
void Butterfly::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newLwing;
	newLwing.x = (Lwing->getref().x - body->getref().x) * rotcos - (Lwing->getref().y - body->getref().y) * rotsin + body->getref().x;
	newLwing.y = (Lwing->getref().y - body->getref().y) * rotcos + (Lwing->getref().x - body->getref().x) * rotsin + body->getref().y;
	Lwing->setRefPoint(newLwing);
	Lwing->rotate();

	point newRwing;
	newRwing.x = (Rwing->getref().x - body->getref().x) * rotcos - (Rwing->getref().y - body->getref().y) * rotsin + body->getref().x;
	newRwing.y = (Rwing->getref().y - body->getref().y) * rotcos + (Rwing->getref().x - body->getref().x) * rotsin + body->getref().y;
	Rwing->setRefPoint(newRwing);
	Rwing->rotate();
	

	point newhead;
	newhead.x = (head->getref().x - body->getref().x) * rotcos - (head->getref().y - body->getref().y) * rotsin + body->getref().x;
	newhead.y = (head->getref().y - body->getref().y) * rotcos + (head->getref().x - body->getref().x) * rotsin + body->getref().y;
	head->setRefPoint(newhead);
	head->rotate();

	body->rotate();
	rotateCount++;
}
void Butterfly::VerticalFlip()
{
	rotate(); rotate();
	flipCount++;
}





Castle::Castle(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point triangle1Ref = { ref.x - config.CastleShape.baseWidth / 3.5, ref.y - config.CastleShape.baseHeight/1.5 };
	point triangle2Ref = { ref.x + config.CastleShape.baseWidth / 3.5, ref.y - config.CastleShape.baseHeight/1.5 };
	point circleRef = { ref.x, ref.y - config.CastleShape.baseHeight/1.5 };


	base = new Rect(pGame, baseRef, config.CastleShape.baseHeight, config.CastleShape.baseWidth);
	c_circle = new Circle(pGame, circleRef, config.CastleShape.circleRadius);
	l_triangle = new Triangle(pGame, triangle1Ref, config.CastleShape.triangleHeight, config.CastleShape.triangleWidth);
	r_triangle = new Triangle(pGame, triangle2Ref, config.CastleShape.triangleHeight, config.CastleShape.triangleWidth);
}
void Castle::draw() const
{
	base->draw();
	c_circle->draw();
	l_triangle->draw();
	r_triangle->draw();
}
void Castle::resize(double size)
{
	point newc_circle;
	newc_circle = { (c_circle->getref().x - base->getref().x) * size + base->getref().x, (c_circle->getref().y - base->getref().y) * size + base->getref().y};
	c_circle->setRefPoint(newc_circle);
	c_circle->resize(size);
	
	point newl_triangle;
	newl_triangle = { (l_triangle->getref().x - base->getref().x) * size + base->getref().x, (l_triangle->getref().y - base->getref().y) * size + base->getref().y };
	l_triangle->setRefPoint(newl_triangle);
	l_triangle->resize(size);

	point newr_triangle;
	newr_triangle = { (r_triangle->getref().x - base->getref().x) * size + base->getref().x, (r_triangle->getref().y - base->getref().y) * size + base->getref().y };
	r_triangle->setRefPoint(newr_triangle);
	r_triangle->resize(size);

	base->resize(size);
	if (size == 2) { resizeUpCount++; };
	if (size == 0.5) { resizeDownCount++;
	};
}
void Castle::rotate() 
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newc_circle;
	newc_circle.x = (c_circle->getref().x - base->getref().x) * rotcos - (c_circle->getref().y - base->getref().y) * rotsin + base->getref().x;
	newc_circle.y = (c_circle->getref().y - base->getref().y) * rotcos + (c_circle->getref().x - base->getref().x) * rotsin + base->getref().y;
	c_circle->setRefPoint(newc_circle);
	c_circle->rotate();

	point newl_triangle;
	newl_triangle.x = (l_triangle->getref().x - base->getref().x) * rotcos - (l_triangle->getref().y - base->getref().y) * rotsin + base->getref().x;
	newl_triangle.y = (l_triangle->getref().y - base->getref().y) * rotcos + (l_triangle->getref().x - base->getref().x) * rotsin + base->getref().y;
	l_triangle->setRefPoint(newl_triangle);
	l_triangle->rotate();

	point newr_triangle;
	newr_triangle.x = (r_triangle->getref().x - base->getref().x) * rotcos - (r_triangle->getref().y - base->getref().y) * rotsin + base->getref().x;
	newr_triangle.y = (r_triangle->getref().y - base->getref().y) * rotcos + (r_triangle->getref().x - base->getref().x) * rotsin + base->getref().y;
	r_triangle->setRefPoint(newr_triangle);
	r_triangle->rotate();
	base->rotate();
	rotateCount++;
}
void Castle::VerticalFlip()
{
	rotate(), rotate();
	flipCount++;
}
