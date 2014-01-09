#include "Root.h"


Effect_FadeString::Effect_FadeString(void)
{
	this->Init();
}


Effect_FadeString::Effect_FadeString(double x,double y,string str){
	this->Init();
	this->X(x);
	this->Y(y);
	this->drawStr = str;
}


Effect_FadeString::Effect_FadeString(double x,double y,int size,string str){
	this->Init();
	this->X(x);
	this->Y(y);
	this->drawStr = str;
	this->fontSize = size;
}


Effect_FadeString::Effect_FadeString(double x,double y,string str,int tex){
	this->Init();
	this->X(x);
	this->Y(y);
	this->drawStr = str;
	this->Texture(tex);
}


Effect_FadeString::~Effect_FadeString(void)
{
}


void Effect_FadeString::Init(void){
	this->hight = 0;
	this->hightMax = -100;
	this->numAlpha = 0;
	this->Texture(GetColor(255,255,255));
	this->fontSize = 16;
}


void Effect_FadeString::UpData(void){
	hight -= 1.5;
	if(this->hight < this->hightMax) this->IsDrawEnd(true);
	
	this->numAlpha = 255*(100-hight/hightMax*100)/100;
}


void Effect_FadeString::Draw(void){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,(int)(numAlpha + 0.5));
	SetFontSize(fontSize);
	DrawFormatString((int)(this->X() + 0.5) , (int)(this->Y() + this->hight + 0.5) , this->Texture() , drawStr.c_str());
	SetFontSize(16);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}