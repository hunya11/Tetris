#include "Root.h"


RandomNum::RandomNum(void)
{
	random_device rd;
	mt = new mt19937(rd);
}


RandomNum::~RandomNum(void)
{
	if(mt != 0)delete mt;
}


int RandomNum::GetRand(int max){
	return this->GetRand(0,max);
}


int RandomNum::GetRand(int min,int max){
	uniform_int_distribution<int> dist(min, max);
	return dist(*mt);
}


int RandomNum::GetRand(int min,int max,list<int> del) throw(int){
	if(max+1 <= del.size()) throw -1;
	if(del.empty() == true) return this->GetRand(min,max);

	bool isLoop = false;
	int num = 0;
	do{
		list<int>::iterator it = del.begin();
		isLoop = false;
		uniform_int_distribution<int> dist(min, max);
		num = dist(*mt);
		while(it != del.end()){
			if(*it == num){
				isLoop = true;
				break;
			}
			++it;
		}
	}while(isLoop == true);

	return num;
}

int RandomNum::GetRand(int max,list<int> del) throw(int){
	int num = 0;
	try{
		num =  this->GetRand(0,max,del);
	}catch(int ex){
		throw ex;
	}
	return num;
}

