#pragma once

/* Actorの基底クラス */
class ActorBase
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
		ePlayer,    // プレイヤー
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
	/// 更新処理(アクターの状態を確認)
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	void UpdateActor(float _deltaTime);

	/// <summary>
	/// アクター独自の更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	virtual void Update(float _deltaTime) {};

	/// <summary>
	/// アクターの描画
	/// </summary>
	virtual void Draw() {};

	/// <summary>
	/// コンポーネントを追加する
	/// </summary>
	/// <param name="_component">追加するコンポーネントのポインタ</param>
	void AddComponent(Component* _component);
	/// <summary>
	/// コンポーネントを削除する
	/// </summary>
	/// <param name="_component">削除するコンポーネントのポインタ</param>
	void RemoveComponent(Component* _component);

protected:
	State mState;          // 各自のアクターの状態

	// Transform
	VECTOR mPos;           // ポジション
	VECTOR mScale;         // 大きさ
	Quaternion mRotation;  // 回転

	int mModel;            // アクターモデルデータ

private:
	SceneBase::Scene mDirthplaceScene;      // 各自のアクターを生成したシーン
	Tag mTag;                               // 各自のアクターが持つタグ

	std::vector<Component*>mComponents; //アタッチされているコンポーネント
public:  // ゲッター、セッター
	// アクターが生成された時のシーンを取得
	SceneBase::Scene GetScene()const { return mDirthplaceScene; }
	// アクターのタグを取得
	Tag GetTag()const { return mTag; }
	// アクターの状態を取得
	State GetState()const { return mState; }

	//// アクターのポジションを取得
	//const VECTOR& GetPosition()const { return mPos; }
	//// アクターの向きを取得
	//const Quaternion& GetRotation()const { return mRotation; }
};

