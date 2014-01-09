#pragma once
class SelectionMenu : public DrawableComponent
{
private:
	
	// Summary : 選択肢リスト
	list<string> menuList;
	
	// Summary : カーソル位置
	int numCursor;
	
	// Summary : 表示位置X座標
	double x;
	
	// Summary : 表示位置y座標
	double y;
public:
	
	// Summary : コンストラクタ
	SelectionMenu(void);
	
	// Summary : デストラクタ
	~SelectionMenu(void);
	
	// Summary : 初期化処理
	void Init(void);
	
	// Summary : 更新処理
	void UpData(void);

	// Summary : 描画処理
	void Draw(void);

	// Summary : 表示する選択肢に加える
	// Param   : string str = 加える選択肢
	void Add(string str);


	/*プロパティ*/
	void NumCursor(int num);
	int NumCursor(void);

	void X(double num);
	double X(void);

	void Y(double num);
	double Y(void);
};

