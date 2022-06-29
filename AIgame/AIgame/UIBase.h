#pragma once

/* UIの基底クラス */
class UIBase : public Image
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nowScene">生成された時のシーン</param>
	UIBase(const SceneBase::Scene& _nowScene);
	// デストラクタ
	~UIBase();

	/// <summary>
	/// UIの更新処理
	/// </summary>
	virtual void Update(float _deltaTime) {};

	/// <summary>
	/// UIの描画
	/// </summary>
	virtual void Draw() = 0;

protected:
	std::vector<VECTOR> mPos;  // すべてのUIポジション
	std::vector<int> mImages;  // すべてのUI画像データを格納

private:
	SceneBase::Scene mDirthplaceScene;  // 各自のUIを生成したシーン

public: // ゲッター、セッター
	// 各UIが生成された時のシーンを返す
	SceneBase::Scene GetDirthplaceScene() { return mDirthplaceScene; }
};