#include "Root.h"

int Fps::N = 60;
int Fps::FPS = 60;

Fps::Fps(void)
{
	this->Init();
}


Fps::~Fps(void)
{
}

void Fps::Init(void){
	startTime = 0;
	count = 0;
	fps = 0;
}

void Fps::UpData(void){

	if( count == 0 ){ //1フレーム目なら時刻を記憶
		startTime = GetNowCount();
	}
	if( count == N ){ //60フレーム目なら平均を計算する
		int t = GetNowCount();
		fps = 1000.f/((t-startTime)/(float)N);
		count = 0;
		startTime = t;
	}
	count++;

}


void Fps::Wait(void){
	int tookTime = GetNowCount() - startTime;	//かかった時間
	int waitTime = count*1000/FPS - tookTime;	//待つべき時間
	if( waitTime > 0 ){
		Sleep(waitTime);	//待機
	}
}


float Fps::GetFps(void){
	return this->fps;
}