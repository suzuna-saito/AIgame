#pragma once

/* Actorの基底クラス */
class ActorBase :public Image
{
public:
	// アクターの状態管理用タグ
	enum class State :unsigned char
	{
		eActive,    // アクティブ
		ePaused,    // 更新停止
		eDead,      // 更新終了
	};

	// アクターの種類判別タグ
	enum class Tag :unsigned char
	{
		eCamera,    // カメラ
		eGround,    // 床
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nowScene">生成された時のシーン</param>
	/// <param name="_actorTag">アクターのタグ</param>
	ActorBase(const SceneBase::Scene& _nowScene, const Tag& _actorTag);
	// デストラクタ
	virtual ~ActorBase() {};

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	void Update(float _deltaTime);

	/// <summary>
	/// アクター独自の更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	virtual void UpdateActor(float _deltaTime) {};

protected:
	State mState;          // 各自のアクターの状態

	// Transform
	Vector3 mPos;          // ポジション
	Vector3 mScale;        // 大きさ
	Quaternion mRotation;  // 回転

private:
	SceneBase::Scene mDirthplaceScene;  // 各自のアクターを生成したシーン
	Tag mTag;                           // 各自のアクターが持つタグ

public:  // ゲッター、セッター
	// アクターが生成された時のシーンを取得
	SceneBase::Scene GetScene()const { return mDirthplaceScene; }
	// アクターのタグを取得
	Tag GetTag()const { return mTag; }
	// アクターの状態を取得
	State GetState()const { return mState; }

	// アクターのポジションを取得
	const Vector3& GetPosition()const { return mPos; }
	// アクターの向きを取得
	const Quaternion& GetRotation()const { return mRotation; }
};

