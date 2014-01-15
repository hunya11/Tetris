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

	//実行中のエフェクトを終了
	vector<Effect*>::iterator it = effList.begin();
	while( it != effList.end() ){
		it = effList.erase(it);	
	}
}

void Page::UpData(void){
	key->UpData();
	localNowCount = GetNowCount() - startNowCount;

	//エフェクトの更新処理
	for(unsigned int i=0;i<effList.size();i++){
		if(effList[i] != NULL){
			effList[i]->UpData();
		}
	}

	//エフェクトの実行管理
	this->EffectManager();
}

void Page::Draw(void){

	//エフェクト表示
	for(unsigned int i=0;i<effList.size();i++){
		if(effList[i] != NULL){
			effList[i]->Draw();
		}
	}

}

void Page::NowPage(FRAME_PAGE::Type fp){
	Page::nowPage = fp;
}

FRAME_PAGE::Type Page::NowPage(void){
	return Page::nowPage;
}

void Page::EffectManager(void){
	vector<Effect*>::iterator it = effList.begin();
	while( it != effList.end() ){
		Effect* p = *it;
		if(p->IsDrawEnd() == true){
			delete p;
			it = effList.erase(it);			
		}else{
			it++;
		}
	}	

	//領域の縮小
	if(effList.size() == 0 && effList.capacity() != 0)	{
		vector<Effect*>(effList).swap(effList);
	}

}


void Page::RunEffect(Effect* eff){
	effList.push_back(eff);
}