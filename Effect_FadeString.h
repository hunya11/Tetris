#pragma once
class Effect_FadeString : public Effect
{
private:
	typedef Effect base;
	string drawStr;

	double hight;
	double hightMax;
	double numAlpha;
	int fontSize;
public:
	Effect_FadeString(void);
	Effect_FadeString(double x,double y,int size,string str);
	Effect_FadeString(double x,double y,string str);
	Effect_FadeString(double x,double y,string str,int tex);
	~Effect_FadeString(void);
	
	void Init(void);
	void UpData(void);
	void Draw(void);
};

