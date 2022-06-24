#pragma once

/* 
リザルトシーン
*/
class Result :public SceneBase
{
public:
	// コンストラクタ
	Result();
	// デストラクタ
	~Result();

	// 毎フレームの入力処理
	void Input() override;

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase* Update()override;

	/// <summary>
	/// シーンの描画
	/// </summary>
	void Draw()override;
};

