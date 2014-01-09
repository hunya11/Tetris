#pragma once
class Fps : public BaseComponent
{
private:
	// Summary : 親クラス
	typedef BaseComponent base;

	// Summary : 測定開始時刻
	int startTime;

	// Summary : カウンタ
	int count;

	// Summary : fps
	float fps;

	// Summary : 平均を取るサンプル数
	static int N;

	// Summary : 設定したFPS
	static int FPS;
public:
	// Summary : コンストラクタ
	Fps(void);

	// Summary : デストラクタ
	~Fps(void);

	// Summary : 初期化処理
	void Init(void);

	// Summary : 更新処理
	void UpData(void);

	// Summary : 待機処理
	void Wait();

	float GetFps(void);
};

