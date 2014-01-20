#pragma once
class GamePage : public Page
{
private:

	// Summary : 親クラス
	typedef Page base;

	// Summary : 得点
	struct SCORE_POINT{
		enum Point{
			LINE1 = 100,
			LINE2 = 250,
			LINE3 = 625,
			LINE4 = 1500,
		};
	};

	// Summary : ミノ
	struct MINO{
		// Summary : x座標
		int x;
		// Summary : y座標
		int y;
		// Summary : 形
		BLOCK::Type type;
	};


	// Summary : ブロック
	Block* block[20][10];

	// Summary : ホールド
	Block* hold[4][3];

	// Summary : ストック
	Block* stock[3][4][3];
	
	// Summary : 操作するミノ
	MINO mino[4];

	// Summary : 操作するミノのゴースト
	MINO ghost[4];

	// Summary : 順番待ちミノの形
	BLOCK::Type minoNextStock[3];
	
	// Summary : ホールドしたミノの形
	BLOCK::Type minoHold;

	// Summary : 乱数管理
	RandomNum* rand;
	
	// Summary : ミノが接地しているか
	bool isGrounding;
	
	// Summary : アイドルタイム中か
	bool isIdletime;
	
	// Summary : ハードドロップを使ってるか
	bool isHardDrop;
	
	// Summary : ミノが動けるか
	bool isCanMove;
	
	// Summary : ミノが回ったか
	bool isSpin;
	
	// Summary : ホールドを使ったか
	bool isHold;
	
	// Summary : すでにホールドしているか
	bool isAlreadyHold;
	
	// Summary : 
	int OldIdleSeconds;
	
	// Summary : 
	int OldDropSeconds;
	
	int NowIdleSeconds;

	// Summary : アイドルタイムの最大時間
	int IdleMax;
	
	// Summary : 落下待機の最大時間
	int DropMax;

	// Summary : 落としたブロックの分布
	int dropBlock[7];

	// Summary : スコア
	int numScore;
	
	// Summary :　消したラインの数
	int numDelLine;

	// Summary :　ゲームレベル
	int numGameLevel;

	// Summary : ゲームオーバーかどうか
	bool isGameOver;
	


	//オプション
	// Summary : ミノが時間で落下するか
	bool isOptionMinoDrop;

	// Summary : ゴーストを表示するか
	bool isOptionDrawGMino;

	// Summary : ハードドロップを使えるか
	bool isOptionUseHardDrop;

	// Summary : ミノを回転できるか
	bool isOptionUseSpin;

	// Summary : ホールドを使用できるか
	bool isOptionUseHold;

	// Summary : ネクストブロックを確認できるか
	bool isOptionShowNext;


public:
	// Summary : コンストラクタ
	GamePage(void);
	
	// Summary : デストラクタ
	~GamePage(void);
	
	// Summary : 初期化処理
	void Init(void);
	
	// Summary : 更新処理
	void UpData(void);
	
	// Summary : 描画処理
	void Draw(void);
	
	// Summary : リソース読み込み
	void LoadResource(void);

	void SetMinoPos(MINO* buf);

	// Summary : 指定されたブロックを生成
	// Param   : BLOCK::Type type = 生成するブロック
	void MinoFactory(BLOCK::Type type);

	// Summary : ランダムなミノを取得
	// Returns : BLOCK::Type型
	BLOCK::Type GetRandMino(void);
	
	// Summary : ストックを更新
	void PushMinoStock(void);
	
	// Summary : ミノの回転
	// Param   : bool clockwise = true：時計回り,false:反時計回り
	void SpinMino(bool clockwise);

	// Summary : ゴーストの生成
	void MakeGhost(void);

	void SetDrawHoldMinoPos(void);

	void SetDrawStockMinoPos(void);


};


