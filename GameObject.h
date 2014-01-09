#pragma once
class GameObject : public DrawableComponent
{
private:
	double x;
	double y;

	double sizeX;
	double sizeY;

	int texture;
public:
	GameObject(void);
	virtual ~GameObject(void);

	virtual void Init(void);

	void X(double num);
	double X(void);

	void Y(double num);
	double Y(void);

	void SizeX(double num);
	double SizeX(void);

	void SizeY(double num);
	double SizeY(void);

	void Texture(int num);
	int Texture(void);

};
