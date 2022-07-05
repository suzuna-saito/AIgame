#include "pch.h"

Ground::Ground()
	: ActorBase(SceneBase::mIsScene,ActorBase::Tag::eGround)
{
	mModel = MV1LoadModel("data/models/Ground/RedGround.mv1");

	MV1SetScale(mModel, VGet(100.0f, 10.0f, 100.0f));
	MV1SetPosition(mModel, VGet(0.0f, 0.0f, 0.0f));
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
