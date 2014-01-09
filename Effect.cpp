#include "Root.h"

Effect::Effect(void)
{
	this->Init();
}


Effect::~Effect(void)
{
}


void Effect::Init(void){
	this->isDrawEnd = false;
}


void Effect::IsDrawEnd(bool flag){
	this->isDrawEnd = flag;
}


bool Effect::IsDrawEnd(void){
	return this->isDrawEnd;
}
