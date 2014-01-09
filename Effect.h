#pragma once
class Effect : public GameObject
{
private:
	typedef GameObject base;
	bool isDrawEnd;
	
public:
	Effect(void);
	virtual ~Effect(void);

	virtual void Init(void);

	void IsDrawEnd(bool flag);
	bool IsDrawEnd(void);
};

