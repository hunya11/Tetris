#include "Root.h"


Block::Block(void)
{
	this->Init();
}


Block::~Block(void)
{
}


void Block::Init(void){
	this->SizeX(36.0);
	this->SizeY(36.0);
	this->status = STATUS::NONE;
	this->blockType = BLOCK::NONE;
}


void Block::UpData(void){
	if(status == STATUS::NONE){
		Texture(GetColor(255,255,255));
	}else{
		switch(blockType){
		case BLOCK::I:
			Texture(GetColor(0,255,255));
			break;
		case BLOCK::O:
			Texture(GetColor(255,212,0));
			break;
		case BLOCK::S:
			Texture(GetColor(191,255,0));
			break;
		case BLOCK::Z:
			Texture(GetColor(255,0,0));
			break;
		case BLOCK::J:
			Texture(GetColor(0,0,255));
			break;
		case BLOCK::L:
			Texture(GetColor(243,152,0));
			break;
		case BLOCK::T:
			Texture(GetColor(139,0,139));
			break;
		default:
			Texture(GetColor(255,255,255));
			break;
		}
	}
}


void Block::Draw(void){
	DrawBox((int)X(),(int)Y(),(int)X() + (int)SizeX()-3,(int)Y() + (int)SizeY()-3,GetColor(0,0,0),TRUE);
	DrawBox((int)X() + 3,(int)Y() + 3,(int)X() + (int)SizeX()-6,(int)Y() + (int)SizeY()-6,GetColor(255,255,255),TRUE);
	if(/*status == STATUS::MOVE ||*/ status == STATUS::GHOST) SetDrawBlendMode(DX_BLENDMODE_ALPHA,96);
	DrawBox((int)X() + 3,(int)Y() + 3,(int)X() + (int)SizeX()-6,(int)Y() + (int)SizeY()-6,Texture(),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}


void Block::Status(Block::STATUS::Type type){
	this->status = type;
}


Block::STATUS::Type Block::Status(void){
	return this->status;
}


void Block::BlockType(BLOCK::Type type){
	this->blockType = type;
}


BLOCK::Type Block::BlockType(void){
	return this->blockType;
}