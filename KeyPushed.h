#pragma once


class KeyPushed : public BaseComponent
{
private:
	// Summary : 親クラス
	typedef BaseComponent base;

	// Summary : 現在keyを押したか
	static bool NowKeysPushed[256];
	
	// Summary : 前回keyを押したか
	static bool PreviousKeysPushed[256];

	// Summary : キーボードの状態
	static char KeyState[256];


public:
	// Summary : コンストラクタ
	KeyPushed(void);

	// Summary : デストラクタ
	~KeyPushed(void);

	// Summary : 初期化処理
	void Init(void);

	// Summary : 更新処理
	void UpData(void);

	// Summary : キーボードが押された瞬間かどうか判断
	// Param   : int KeyCode = 判断するキー
	// Returns : bool型(true:押された瞬間,false:押された瞬間ではない)
	bool CheckKeyPushed(int KeyCode);

	// Summary : キーボードが押されているかどうか判断
	// Param   : int KeyCode = 判断するキー
	// Returns : bool型(true:押されている,false:押されていない)
	bool GetKeyState(int KeyCode);

};

