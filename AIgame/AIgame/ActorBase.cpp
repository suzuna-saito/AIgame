#include "pch.h"

ActorBase::ActorBase(const SceneBase::Scene& _nowScene, const Tag& _actorTag)
	: mState(State::eActive)
	, mDirthplaceScene(_nowScene)
	, mTag(_actorTag)
	, mPos(Vector3::Zero)
	, mScale(Vector3::Zero)
	, mRotation(Quaternion::Identity)
{
	// アクターを追加する
	ActorManager::AddActor(this);
}

void ActorBase::Update(float _deltaTime)
{
	// アクターの状態がアクティブだったら
	if (mState == State::eActive)
	{
		// アクター独自の更新
		UpdateActor(_deltaTime);
	}
}
