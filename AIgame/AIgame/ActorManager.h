#pragma once

/* すべてのActorの更新を行う */
class ActorManager
{
public:
	// コンストラクタ
	ActorManager();
	// デストラクタ
	~ActorManager() {};

	// インスタンスを作成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	/// <summary>
	/// アクターの追加
	/// </summary>
	/// <param name="_actor">追加するActorBaseクラスのポインタ</param>
	static void AddActor(ActorBase* _actor);
	/// <summary>
	/// アクターの削除
	/// </summary>
	static void DeleteActor();

	/// <summary>
	/// アクターの更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	static void UpdateActor(float _deltaTime);

	/// <summary>
	/// アクターの描画
	/// </summary>
	static void DrawActor();

private:
	// ActorManagerの実体（アプリ内に唯一存在）
	static ActorManager* mManager;

	// 全てのアクターを格納するコンテナ
	std::vector<ActorBase*>mActors;
	// Update中に追加されたアクターを一時的に保存するコンテナ
	std::vector<ActorBase*>mPendingActors;

	// Update中かどうか
	bool mUpdatingActor;
};