#include "Root.h"


Effect_DelBlock::Effect_DelBlock(void){
	this->Init();
}


Effect_DelBlock::Effect_DelBlock(double x,double y,int tex){
	this->X(x);
	this->Y(y);
	this->Texture(tex);
	this->Init();	
}

Effect_DelBlock::~Effect_DelBlock(void)
{
}


void Effect_DelBlock::Init(void){
	this->r = 0;
	this->numAlpha = 0;
	this->rMax = 100;
}


void Effect_DelBlock::UpData(void){
	this->r += 1.5;	
	if(this->r >= rMax) this->IsDrawEnd(true);

	this->numAlpha = 255*(100-r/rMax*100)/100;
}


void Effect_DelBlock::Draw(void){
	for(int i=0;i<4;i++){
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,(int)(numAlpha+0.5));
		DrawCircle((int)(this->X() + 0.5) , (int)(this->Y() + 0.5) , (int)(this->r - i + 0.5) , this->Texture() , FALSE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
}