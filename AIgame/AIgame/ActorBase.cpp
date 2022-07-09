#include "pch.h"

ActorBase::ActorBase(const SceneBase::Scene& _nowScene, const Tag& _actorTag)
	: mState(State::eActive)
	, mDirthplaceScene(_nowScene)
	, mTag(_actorTag)
	, mPos(VGet(0.0f,0.0f,0.0f))
	, mScale(VGet(0.0f, 0.0f, 0.0f))
	, mRotation(Quaternion::Identity)
	, mModel(0)
{
	// アクターを追加する
	ActorManager::AddActor(this);
}

void ActorBase::UpdateActor(float _deltaTime)
{
	// アクターの状態がアクティブだったら
	if (mState == State::eActive)
	{
		// アクター独自の更新
		Update(_deltaTime);
	}
}

void ActorBase::AddComponent(Component* _component)
{
	// Componentの格納
	mComponents.emplace_back(_component);
}

void ActorBase::RemoveComponent(Component* _component)
{
	// 引数の値を検索し、一致したものを消す
	auto itr = std::find(mComponents.begin(), mComponents.end(), _component);
	if (itr != mComponents.end())
	{
		mComponents.erase(itr);
	}
}
