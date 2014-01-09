#pragma once
class BaseComponent
{
public:
	// Summary : デストラクタ
	virtual ~BaseComponent(void) = 0;

	// Summary : 初期化処理
	virtual void Init(void) = 0;

	// Summary : 更新処理
	virtual void UpData(void) = 0;
};

