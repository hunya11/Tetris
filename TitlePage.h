#pragma once
class TitlePage : public Page
{
private:
	// Summary : 親クラス
	typedef Page base;
	
	// Summary : スタートメニュー
	SelectionMenu menu;

public:
	// Summary : コンストラクタ
	TitlePage(void);
	
	// Summary : デストラクタ
	~TitlePage(void);
	
	// Summary : 初期化処理
	void Init(void);
	
	// Summary : 更新処理
	void UpData(void);
	
	// Summary : 描画処理
	void Draw(void);

	// Summary : リソース読み込み
	void LoadResource(void);
};

