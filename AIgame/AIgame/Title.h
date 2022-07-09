#pragma once

/* タイトルシーン */
class Title :public SceneBase
{
public:
	// コンストラクタ
	Title();
	// デストラクタ
	~Title();

	// 毎フレームの入力処理
	void Input() override;

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase::Scene Update()override;

private:
};