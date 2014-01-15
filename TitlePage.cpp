#include "Root.h"


TitlePage::TitlePage(void)
{
	this->Init();
}


TitlePage::~TitlePage(void)
{
}


void TitlePage::Init(void){
	menu = SelectionMenu();
	menu.Add("Start!");
	menu.Add("End...");
	menu.X(0);
	menu.Y(500);
}


void TitlePage::UpData(void){	
	base::UpData();

	if(key->CheckKeyPushed(KEY_INPUT_UP ) == true){
		menu.NumCursor(menu.NumCursor()-1);
	}else if(key->CheckKeyPushed(KEY_INPUT_DOWN ) == true){
		menu.NumCursor(menu.NumCursor()+1);
	}else if(key->CheckKeyPushed(KEY_INPUT_SPACE ) == true){
		switch(menu.NumCursor()){
		case 0:
			NowPage(FRAME_PAGE::GAME);
			break;
		case 1:
			NowPage(FRAME_PAGE::END);
			break;
		}
	}

}


void TitlePage::Draw(void){
	DrawFormatString( 0, 0, GetColor( 255 , 255 , 255 ), "TitlePage:%d",localNowCount);
	menu.Draw();

	base::Draw();
}


void TitlePage::LoadResource(void){
}