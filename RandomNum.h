#pragma once
class RandomNum
{
private:
	mt19937* mt;
public:

	// Summary : コンストラクタ
	RandomNum(void);

	// Summary : デストラクタ
	~RandomNum(void);

	// Summary : 0~maxまでの乱数を取得
	// Param   : int max = 最大値
	// Returns : int型乱数
	int GetRand(int max);

	// Summary : min~maxまでの乱数を取得
	// Param   : int min = 最小値
	// param   : int max = 最大値
	// Returns : int型乱数
	int GetRand(int min,int max);

	// Summary : 0~maxまでの乱数を取得.また,delで指定した整数を除外
	// Param   : int max = 最大値
	// param   : list<int> del = 除外する選択肢
	// Returns : int型乱数
	// Exception : max+1 <= del.size()
	// ExReturns : -1
	int GetRand(int max,list<int> del) throw(int);

	// Summary : min~maxまでの乱数を取得.また,delで指定した整数を除外
	// param   : int min = 最小値
	// Param   : int max = 最大値
	// Param   : list<int> del = 除外する選択肢
	// Returns : int型乱数
	// Exception : max+1 <= del.size()
	// ExReturns : -1
	int GetRand(int min,int max,list<int> del) throw(int);

};

