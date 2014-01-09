#pragma once
class DrawableComponent : public BaseComponent
{
public:
	// Summary : デストラクタ
	virtual ~DrawableComponent(void) = 0;
	
	// Summary : 描画処理
	virtual void Draw(void) = 0;
};

