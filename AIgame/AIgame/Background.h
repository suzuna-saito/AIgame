#pragma once

/* 背景制御 */
class Background :public UIBase
{
public:
	// コンストラクタ
	Background();
	// デストラクタ
	~Background();

	/// <summary>
	/// 背景の更新処理
	/// </summary>
	/// <param name="_deltaTime"></param>
	void Update(float _deltaTime) override {};

	/// <summary>
	/// 背景の描画
	/// </summary>
	void Draw()override;
};

