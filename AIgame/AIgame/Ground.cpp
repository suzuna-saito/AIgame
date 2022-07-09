#include "pch.h"

Ground::Ground(const VECTOR& _pos)
	: ActorBase(SceneBase::mIsSceneTag,ActorBase::Tag::eGround)
{
	mModel = MV1LoadModel("Data/Models/Ground/Ground.mv1");

	// 床のサイズを設定
	MV1SetScale(mModel, VGet(50.0f, 10.0f, 50.0f));
	// 床のポジションを設定
	MV1SetPosition(mModel, _pos);
}

Ground::~Ground()
{
	MV1DeleteModel(mModel);
}

void Ground::Update(float _deltaTime)
{
}

void Ground::Draw()
{
	MV1DrawModel(mModel);
}
