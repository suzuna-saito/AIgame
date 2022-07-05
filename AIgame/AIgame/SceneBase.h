#pragma once

/* シーンの基底クラス */
class SceneBase
{
public:
	// シーンのタグ（種類）
	enum class Scene :unsigned char
	{
		eInit,    // 初期状態
		eTitle,   // タイトル
		ePlay,    // プレイ
		eResult,  // リザルト
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nowScene">現在のシーン</param>
	SceneBase(Scene _nowScene);
	// デストラクタ
	~SceneBase() {};

	// 毎フレームの入力処理
	virtual void Input() = 0;

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	virtual SceneBase* Update() = 0;

	static Scene mIsScene;    // 現在のシーンタグ

protected:
	bool mSceneTransitionFlag;// 次のシーンに遷移するか
};

