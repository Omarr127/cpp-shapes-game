#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	// rotation angles
	double pi = 22.0 / 7.0;
	double RotationAngles[5] = { 0, pi / 2.0, pi, 3.0 * pi / 2.0, 2.0 * pi };
	
	// size options
	double SizeOptions[3] = { 0.5, 1.0, 2.0 };

	// composite shapes sizes
	double* SignSize = SizeOptions + 1;
	double* HouseSize = SizeOptions + 1;
	double* CarSize = SizeOptions + 1;
	double* IceCreamSize = SizeOptions + 1;
	double* TreeSize = SizeOptions + 1;
	double* TentSize = SizeOptions + 1;
	double* CastleSize = SizeOptions + 1;

	// composite shapes rotation angles

	double* SignRotation = RotationAngles;
	double* HouseRotation = RotationAngles;
	double* CarRotation = RotationAngles;
	double* IceRotation = RotationAngles;
	double* TreeRotation = RotationAngles;
	double* TentRotation = RotationAngles;
	double* CastleRotation = RotationAngles;


	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

	struct {
		int topWidth = 120, topHeight = 32;
		int baseWidth = 120, baseHeight = 70;
		int doorWidth = 12, doorHeight = 32;
		int windowRadius = 6;
	}HouseShape;

	struct {
		int baseWidth = 129, baseHeight = 45;
		int topWidth = 30, topHeight = 90;
		int wheelRadius = 25;
	}CarShape;

	struct {
		int topRadius = 25;
		int bottomWidth = 50, bottomHeight = 91;
	}iceCreamShape;

	struct {
		int baseWidth = 20, baseHeight = 91;
		int triangleWidth = 35, triangleHeight = 50;
	}TreeShape;

	struct {
		int bodyWidth = 30, bodyHeight = 120;
		int WingWidth = 90, WingHeight = 140;
		int circleRadius = 20;
	}butterflyShape;

	struct {
		int baseWidth = 180, baseHeight = 80;
		int triangleWidth = 40, triangleHeight = 100;
		int circleRadius = 20;
	}CastleShape;
}config;
struct Color {
	unsigned char ucRed;
	unsigned char ucGreen;
	unsigned char ucBlue;

	Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
		: ucRed(r), ucGreen(g), ucBlue(b) {}
};




enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,//Sign shape item
	ITM_House,//home shape item
	ITM_Icecream,//icecream shape item
	ITM_Car,//car shape item
	ITM_Tree,//tree shape item
	ITM_Castle,//castle shape item
	ITM_Butterfly,//tent shape item
	ITM_Rotate,//Rotate shape item
	ITM_Refresh,//refresh shape item
	ITM_Hint,//hint shape item
	ITM_Delete,//delete shape item
	ITM_Level,//Level shape item
	ITM_Save,//save shape item
	ITM_EXIT,  //Exit item
	ITM_Zoomin,  // zoomin item
	ITM_Zoomout, // zoomout item
	ITM_FLIP,
	//TODO: Add more items names here
	ITM_CNT  //no. of toolbar items ==> This should be the last line in this enum

};