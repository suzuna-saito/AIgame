#include "pch.h"

ActorBase::ActorBase(const SceneBase::Scene& _nowScene, const Tag& _actorTag)
	: mState(State::eActive)
	, mDirthplaceScene(_nowScene)
	, mTag(_actorTag)
	, mPos(VGet(0.0f,0.0f,0.0f))
	, mScale(VGet(0.0f, 0.0f, 0.0f))
	, mRotation(Quaternion::Identity)
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
