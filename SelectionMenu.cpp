#include "Root.h"


SelectionMenu::SelectionMenu(void)
{
	this->Init();
}


SelectionMenu::~SelectionMenu(void)
{
}


void SelectionMenu::Init(void){
	x = 0.0;
	y = 0.0;
	numCursor = 0;
}


void SelectionMenu::UpData(void){
}


void SelectionMenu::Draw(void){	
	list<string>::iterator it = menuList.begin();
	DrawFormatString( (int)(x),(int)(y+17*numCursor), GetColor( 255 , 255 , 255 ),"->");
	for(int i=0; it != menuList.end();i++,++it){
		DrawFormatString( (int)(x+20),(int)(y+17*i), GetColor( 255 , 255 , 255 ),(*it).c_str());
	}
}


void SelectionMenu::Add(string str){
	menuList.push_back(str);
}


void SelectionMenu::NumCursor(int num){
	if(num < 0) this->numCursor = menuList.size() -1;
	else if((unsigned)num >= menuList.size()) numCursor = 0;
	else numCursor = num;
}


int SelectionMenu::NumCursor(void){
	return this->numCursor;
}


void SelectionMenu::X(double num){
	this->x = num;
}


double SelectionMenu::X(void){
	return this->x;
}


void SelectionMenu::Y(double num){
	this->y = num;
}


double SelectionMenu::Y(void){
	return this->y;
}