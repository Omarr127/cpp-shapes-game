#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <iostream>
#include<fstream>
#include "grid.h"
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddTree::operAddTree(game* r_pGame) : operation(r_pGame)
{}

//void operAddTree::Act()
//{
//	window* pw = pGame->getWind();
//
//
//	int xGrid = config.RefX - config.RefX % config.gridSpacing;
//	int yGrid = config.RefY - config.RefX % config.gridSpacing;
//
//	point treeShapeRef = { xGrid, yGrid };
//
//	shape* psh = new Tree(pGame, treeShapeRef);
//
//	grid* pGrid = pGame->getGrid();
//	pGrid->setActiveShape(psh);
//}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();*/
	/*if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddHouse::operAddHouse(game* r_pGame) : operation(r_pGame)
{
}
void operAddHouse::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new House(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddCar::operAddCar(game* r_pGame) : operation(r_pGame)
{
}

void operAddCar::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Car(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddIceCream::operAddIceCream(game* r_pGame) : operation(r_pGame)
{
}
void operAddIceCream::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new IceCream(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Tree(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

operAddButterfly::operAddButterfly(game* r_pGame) : operation(r_pGame)
{
}

void operAddButterfly::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Butterfly(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddCastle::operAddCastle(game* r_pGame) : operation(r_pGame)
{
}
void operAddCastle::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Castle(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



operDeleteShape::operDeleteShape(game* r_pGame) : operation(r_pGame)
{
}


void operDeleteShape::Act()
{
	// Get the grid from the game
	grid* pGrid = pGame->getGrid();
	pGrid->clearGrid();
}






	// Get the active shape from the grid
	/*shape* pActiveShape = pGrid->getActiveShape();*/

	//if (pActiveShape)
	//{
	//	// Delete the active shape from the grid
	//	pGrid->deleteShape(pActiveShape);

	//	// Optionally, you may want to delete the shape object from memory
	//	delete pActiveShape;

	//	// Clear the active shape pointer in the grid
	//	pGrid->setActiveShape(nullptr);
	//}


operresizeup::operresizeup(game* r_pGame):operation(r_pGame)
{
}

void operresizeup::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	activeShape->resize(2);
}


operresizedwn::operresizedwn(game* r_pGame) :operation(r_pGame)
{
}

void operresizedwn::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	activeShape->resize(0.5);
}

	// Check if there is an active shape selected
	/*shape* activeShape = pGrid->getActiveShape();
	if (activeShape) {*/
		// Resize the active shape up by a factor of 2
		/*activeShape->resize();*/

		//// Redraw the grid to reflect the changes
		//pGrid->draw();
	/*}*/

//operResizeUp::operResizeUp(game* r_pGame) : operation(r_pGame) {}
//void operResizeUp::Act() {
//	// Get the window and grid pointers from the game
//	window* pW = pGame->getWind();
//	grid* pGrid = pGame->getGrid();
//
//	// Check if there is an active shape selected
//	shape* activeShape = pGrid->getActiveShape();
//	if (activeShape) {
//		// Resize the active shape up by a factor of 2
//		activeShape->ResizeUp(2.0);
//
//		// Redraw the grid to reflect the changes
//		pGrid->draw();
//	}
//}
//operResizeDown::operResizeDown(game* r_pGame) : operation(r_pGame) {}
//void operResizeDown::Act() {
//	// Get the window and grid pointers from the game
//	window* pW = pGame->getWind();
//	grid* pGrid = pGame->getGrid();
//
//	// Check if there is an active shape selected
//	shape* activeShape = pGrid->getActiveShape();
//	if (activeShape) {
//		// Resize the active shape up by a factor of 2
//		activeShape->resizeDown(2.0);
//
//		// Redraw the grid to reflect the changes
//		pGrid->draw();
//	}
//}

// operations.cpp
operRotate::operRotate(game* r_pGame) : operation(r_pGame) {}

void operRotate::Act() {
	// Get the window and grid pointers from the game
	window* pW = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	/*
	// Check if there is an active shape selected
	//shape* activeShape = pGrid->getActiveShape();
	//if (activeShape) {
		//activeShape->rotate();   
		// Implement the rotation logic here
		// Example: activeShape->rotate(angle);

		// Redraw the grid to reflect the changes

	//}
	*/
	config.SignRotation = config.SignRotation + 1;
	pGrid->rotate();

}
operverticalFlip::operverticalFlip(game* r_pGame) : operation(r_pGame) {}

void operverticalFlip::Act() {
	// Get the window and grid pointers from the game
	window* pW = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	/*
	// Check if there is an active shape selected
	//shape* activeShape = pGrid->getActiveShape();
	//if (activeShape) {
		//activeShape->rotate();
		// Implement the rotation logic here
		// Example: activeShape->rotate(angle);

		// Redraw the grid to reflect the changes

	//}
	*/
	config.SignRotation = config.SignRotation + 1;
	pGrid->rotate();
	pGrid->rotate();  /*this is the additional line where shape rotates by 180 degree where it  means that it is vertically flipped*/

}


////operMoveShape: This class represents the operation to move a shape to a new position by clicking on the grid.

//operMoveShape::operMoveShape(game* r_pGame) : operation(r_pGame)
//{
//}
//



void operExit::Act()
{
	// Exit the game
	exit(0);
}





operSave::operSave(game* r_pGame) : operation(r_pGame) {}
void operSave::Act()
{
	ofstream OutFile("savefile.txt");
	if (OutFile.is_open()) {
		OutFile << pGame->getlevel();
		OutFile << pGame->getscore();
		OutFile << pGame->getlives() << endl;
		grid* pGrid = pGame->getGrid();
		shape** shapelist = pGrid->shapelist();
		int shapecount = pGrid->getshapecount();

		// Save active shape if any
		shape* activeShape = pGrid->getActiveShape();
		if (activeShape) {
			activeShape->save(OutFile);
		}

		// Save all shapes in the grid
		for (int i = 0; i < shapecount; ++i) {
			if (shapelist[i]) {
				shapelist[i]->save(OutFile);
			}
		}

		OutFile.close();
		pGame->printMessage("Game saved successfully.");
	}
	else {
		pGame->printMessage("Failed to open save file.");


	}
}
