#pragma once
class Page : public DrawableComponent
{
private:
	// Summary : 親クラス
	typedef DrawableComponent base;

	// Summary : ページを起動したときの時間
	int startNowCount;

	//エフェクトリスト
	vector<Effect*> effList;

	//エフェクトマネージャー
	void EffectManager(void);

protected:
	// Summary : キー入力管理
	static KeyPushed* key;
	
	// Summary : 操作するページ
	static FRAME_PAGE::Type nowPage;
	
	// Summary : ページを起動してからの時間
	int localNowCount;
public:
	// Summary : コンストラクタ
	Page(void);
	
	// Summary : デストラクタ
	virtual ~Page(void) = 0;

	// Summary : 更新処理
	virtual void UpData(void);
	
	// Summary : 描画処理
	virtual void Draw(void);

	// Summary : リソース読み込み
	virtual void LoadResource(void) = 0;

	//エフェクトの実行
	void RunEffect(Effect* eff);

	/*プロパティ*/
	void static NowPage(FRAME_PAGE::Type fp);
	FRAME_PAGE::Type static NowPage(void);

};

