#pragma once
class Effect_DelBlock :	public Effect
{
private:
	typedef Effect base;

	// Summary : ”¼Œa
	double r;
	double rMax;
	double numAlpha;
public:
	Effect_DelBlock(void);
	Effect_DelBlock(double x,double y,int tex);
	~Effect_DelBlock(void);

	void Init(void);
	void UpData(void);
	void Draw(void);

};

