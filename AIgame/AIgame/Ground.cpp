#include "pch.h"

Ground::Ground()
	: ActorBase(SceneBase::mIsScene,ActorBase::Tag::eGround)
{
	mModel = MV1LoadModel("data/models/Ground/RedGround.mv1");

	MV1SetScale(mModel, VGet(100.0f, 10.0f, 100.0f));
	//MV1SetPosition(mImage, VGet(1000.0f, 500.0f, -500.0f));
}

void Ground::Update(float _deltaTime)
{
	MV1DeleteModel(mModel);
}

void Ground::Draw()
{
	MV1DrawModel(mModel);
}
