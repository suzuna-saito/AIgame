#include "pch.h"

// 自身のインスタンスの初期化
ActorManager* ActorManager::mManager = nullptr;

ActorManager::ActorManager()
	: mUpdatingActor(false)
{
}

void ActorManager::CreateInstance()
{
	if (mManager == nullptr)
	{
		mManager = new ActorManager();  // インスタンスを生成
	}
}

void ActorManager::DeleteInstance()
{
	// 残ってるアクターを全て削除する
	for (auto actor : mManager->mActors)
	{
		delete actor;
	}

	if (mManager != nullptr)
	{
		delete mManager;                // 削除
		mManager = nullptr;
	}
}

void ActorManager::AddActor(ActorBase* _actor)
{
	// アクターの更新中なら待ちに追加
	if (mManager->mUpdatingActor)
	{
		mManager->mPendingActors.emplace_back(_actor);
	}
	else
	{
		mManager->mActors.emplace_back(_actor);
	}
}

// @@@ 後で見直したい
void ActorManager::DeleteActor()
{
	// 消すアクターを判別
	std::vector<ActorBase*> deleteActors;
	for (auto actor : mManager->mActors)
	{
		// このアクターが生成されたシーンと現在のシーンが異なれば
		// カメラは消さない
		if (actor->GetScene() != SceneBase::mIsScene &&
			actor->GetTag() != ActorBase::Tag::eCamera)
		{
			deleteActors.emplace_back(actor);
		}
	}
	// アクターを消す(mActorsから削除される)
	for (auto actor : deleteActors)
	{
		delete actor;
	}
}

void ActorManager::UpdateActor(float _deltaTime)
{
	mManager->mUpdatingActor = true;

	for (auto actor : mManager->mActors)
	{
		// 各アクターを更新
		actor->UpdateActor(_deltaTime);
	}

	mManager->mUpdatingActor = false;

	// 待ちになっていたアクターをmActorObjectsに移動
	for (auto pending : mManager->mPendingActors)
	{
		mManager->mActors.emplace_back(pending);
	}

	// 待ちの要素を削除
	mManager->mPendingActors.clear();

	// 死んだアクターを一時配列に追加
	std::vector<ActorBase*> deadActors;
	for (auto actor : mManager->mActors)
	{
		if (actor->GetState() == ActorBase::State::eDead)
		{
			deadActors.emplace_back(actor);
		}
	}
	// 死んだアクターを消す(mActorsから削除される)
	for (auto actor : deadActors)
	{
		delete actor;
	}
}

void ActorManager::DrawActor()
{
	for (auto actor : mManager->mActors)
	{
		actor->Draw();               // 各アクターを描画
	}
}
