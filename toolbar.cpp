#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_Tree] = "images\\toolbarItems\\toolbar_Tree.jpg.jpeg";
	toolbarItemImages[ITM_Car] = "images\\toolbarItems\\toolbar_Car.jpg.jpeg";
	toolbarItemImages[ITM_Icecream] = "images\\toolbarItems\\toolbar_Icecream.jpg.jpeg";
	toolbarItemImages[ITM_House] = "images\\toolbarItems\\toolbar_House.jpg.jpeg";
	toolbarItemImages[ITM_Castle] = "images\\toolbarItems\\toolbar_Castle.jpg.jpeg";
	toolbarItemImages[ITM_Butterfly] = "images\\toolbarItems\\toolbar_butterfly.jpg";
	toolbarItemImages[ITM_Rotate] = "images\\toolbarItems\\toolbar_Rotate.jpg.jpeg";
	toolbarItemImages[ITM_Zoomin] = "images\\toolbarItems\\toolbar_Zoomin.jpg.jpeg";
	toolbarItemImages[ITM_Zoomout] = "images\\toolbarItems\\toolbar_Zoomout.jpg.jpeg";
	toolbarItemImages[ITM_Refresh] = "images\\toolbarItems\\toolbar_Refresh.jpg.jpeg";
	toolbarItemImages[ITM_Hint] = "images\\toolbarItems\\toolbar_Hint.jpg.jpeg";
	toolbarItemImages[ITM_Save] = "images\\toolbarItems\\toolbar_Save.jpg (2).jpeg";
	toolbarItemImages[ITM_Delete] = "images\\toolbarItems\\toolbar_Delete.jpg.jpeg";
	toolbarItemImages[ITM_Level] = "images\\toolbarItems\\toolbar_Nextlevel.jpg.jpeg";
	toolbarItemImages[ITM_FLIP] = "images\\toolbarItems\\FLIP.jpg";
	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

