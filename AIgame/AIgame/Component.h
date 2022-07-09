#pragma once

/* 全てのコンポーネントの管理を行うクラス */
class Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_owner">アタッチするゲームオブジェクトのポインタ</param>
	Component(ActorBase* _owner);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Component();

	/// <summary>
	/// フレーム毎の処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	virtual void Update(float _deltaTime) {}

	/// <summary>
	/// 入力処理
	/// </summary>
	/// <param name="_state">InputState構造体</param>
	virtual void ProcessInput(const struct InputState& _state) {}

protected:
	class ActorBase* mOwner; //アタッチしているゲームオブジェクトのポインタ

};

