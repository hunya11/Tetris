#include "Root.h"


GameObject::GameObject(void)
{
	this->Init();
}


GameObject::~GameObject(void)
{
}


void GameObject::Init(void){
	x = 0.0;
	y = 0.0;

	sizeX = 0.0;
	sizeY = 0.0;

	texture = 0;
}


void GameObject::X(double num){
	this->x = num;
}


double GameObject::X(void){
	return this->x;
}


void GameObject::Y(double num){
	this->y = num;
}


double GameObject::Y(void){
	return this->y;
}


void GameObject::SizeX(double num){
	this->sizeX = num;
}


double GameObject::SizeX(void){
	return this->sizeX;
}


void GameObject::SizeY(double num){
	this->sizeY = num;
}


double GameObject::SizeY(void){
	return this->sizeY;
}


void GameObject::Texture(int num){
	this->texture = num;
}


int GameObject::Texture(void){
	return this->texture;
}