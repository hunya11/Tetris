#pragma once
class Frame
{
private:
	Page* page;
	FRAME_PAGE::Type nowPage;
	FRAME_PAGE::Type oldPage;
	int backgroundColor;

public:
	Frame(void);
	~Frame(void);

	void Init(void) throw(int);
	void Main(void) throw(int);

};

