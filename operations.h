#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)

class operAddSign :public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};


/////////////////////////////////// class operAddhouse  //////////////////
class operAddHouse :public operation
{
public:
	operAddHouse(game* r_pGame);
	virtual void Act();
};


/////////////////////////////////// class operAddcar  //////////////////
class operAddCar :public operation
{
public:
	operAddCar(game* r_pGame);
	virtual void Act();
};


/////////////////////////////////// class operAddicecream  //////////////////
class operAddIceCream :public operation
{
public:
	operAddIceCream(game* r_pGame);
	virtual void Act();
};

/////////////////////////////////// class operAddtree  //////////////////
class operAddTree :public operation
{
public:
	operAddTree(game* r_pGame);
	virtual void Act();
};


/////////////////////////////////// class operAddTent  //////////////////
class operAddButterfly :public operation
{
public:
	operAddButterfly(game* r_pGame);
	virtual void Act();
};
class operAddCastle :public operation
{
public:
	operAddCastle(game* r_pGame);
	virtual void Act();
};



/////////////////////////////////// class operAddDelete  //////////////////
class operDeleteShape : public operation
{
public:
	operDeleteShape(game* r_pGame);
	virtual void Act();
};




//class operResizeUp : public operation {
//public:
//	operResizeUp(game* r_pGame);
//	virtual void Act();
//};


/////////////////////////////////// operResizeDown  //////////////////
class operresizeup : public operation {
public:
	operresizeup(game* r_pGame);
	virtual void Act();
};
class operresizedwn : public operation {
public:
	operresizedwn(game* r_pGame);
	virtual void Act();
};
//class operResizeDown : public operation {
//public:
//	operResizeDown(game* r_pGame);
//	virtual void Act();
//};
class operRotate : public operation {
public:
	operRotate(game* r_pGame);
	virtual void Act();
};
class operverticalFlip : public operation {
public:
	operverticalFlip(game* r_pGame);
	virtual void Act();
};

/////////////////////////////////// oper exit  //////////////////
class operExit : public operation
{
public:
	operExit(game* r_pGame) : operation(r_pGame) {}
	virtual void Act();
};

    


class operSave : public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();
};
