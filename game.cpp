#include "game.h"
#include "gameConfig.h"
#include <ctime>

game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);
	
	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	string itemName;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		itemName = "sign";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_House:
		op = new operAddHouse(this);
		itemName = "Home";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Icecream:
		op = new operAddIceCream(this);
		itemName = "Icecream";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Car:
		op = new operAddCar(this);
		itemName = "Car";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Tree:
		op = new operAddTree(this);
		itemName = "Tree";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Castle:
		op = new operAddCastle(this);
		itemName = "Castle";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Butterfly:
		op = new operAddButterfly(this);
		itemName = "Tent";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Rotate:
		itemName = "Rotate";
		printMessage("Clicked item:" + itemName);
		op = new operRotate(this);
		break;
	case ITM_Refresh:
		itemName = "Refresh";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Hint:
		itemName = "Hint";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Delete:
		itemName = "Delete";
		printMessage("Clicked item:" + itemName);
		op = new operDeleteShape(this);
		break;
	case ITM_Level:
		itemName = "next level";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_Save:
		itemName = "save";
		printMessage("Clicked item:" + itemName);
		op=new operSave(this);
		break;
	case ITM_Zoomin:
		itemName = "operresize";
		printMessage("Clicked item:" + itemName);
		op = new operresizeup(this);
		break;
	case ITM_Zoomout:
		itemName = "opersizedwn";
		printMessage("Clicked item:" + itemName);
		op = new operresizedwn(this);
		break;
	case ITM_EXIT:
		itemName = "exit";
		printMessage("Clicked item:" + itemName);
		break;
	case ITM_FLIP:
		itemName = "FLIP";
		printMessage("Clicked item:" + itemName);
		op = new operverticalFlip(this);
		break;

	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}
void game::detectK(char k)
{
	shape* movingshape = shapesGrid->getActiveShape();
	if (movingshape != nullptr)
	{
		switch (k)
		{
		case 8: //up
			movingshape->move({ 0,-20 });
			break;
		case 2:// down
			movingshape->move({ 0,20 });
			break;
		case 4: // left
			movingshape->move({ -20,0 });
			break;
		case 6: //right
			movingshape->move({ 20,0 });
			break;

		}
		shapesGrid->draw();
	}
}


////////////////////////////////////////////////////////////////////////
void game::run()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem = ITM_CNT;
	char k;
	//pWind->DrawString(30, 80, "lives=  " + lives + "score=" + score + " level=" + level);
	do
	{
		while (pWind->GetKeyPress(k))
		{
			detectK(k);
		}
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			shapesGrid->draw();

		}

	} while (clickedItem != ITM_EXIT);
}


//void game::Timer() {
//	static time_t start = time(NULL);
//
//	int tim = (60 * 3 - (level * 10)) * 1000;
//	time_t cu = time(NULL);
//	int elapsed = cu - start;
//
//	tim -= elapsed;
//
//	int minutes = tim / 60000;
//	int seconds = (tim) % 60;
//
//
//	if (tim <= 0) {
//		counter--;
//	}
//
//
//	if (seconds == tim % 60) {
//		clearStatusBar();
//		pWind->SetPen(config.penColor, 50);
//		pWind->SetFont(16, BOLD, BY_NAME, "Arial");
//		string timerText = "Time Left: " + to_string(minutes) + ":" + to_string(seconds);
//		pWind->DrawString(config.windWidth - 150, config.windHeight - (int)(0.85 * config.statusBarHeight), timerText);
//	}
int game:: getscore()
{
	return score;
}
int game::getlevel()
{
	return level;
}
int game::getlives()
{
	return lives;
}
void game::levelup()
{
	if (shapesGrid->checkList())
	{
		level += 1;
	}
}