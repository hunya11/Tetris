#include "Root.h"

KeyPushed* Page::key = 0;

FRAME_PAGE::Type Page::nowPage;

Page::Page(void)
{
	if(key == 0) key = new KeyPushed();
	startNowCount =  GetNowCount();
}


Page::~Page(void)
{
}

void Page::UpData(void){
	key->UpData();
	localNowCount = GetNowCount() - startNowCount;
}

void Page::NowPage(FRAME_PAGE::Type fp){
	Page::nowPage = fp;
}

FRAME_PAGE::Type Page::NowPage(void){
	return Page::nowPage;
}