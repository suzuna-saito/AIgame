#include "pch.h"

Ground::Ground()
	: ActorBase(SceneBase::mIsScene,ActorBase::Tag::eGround)
{
	mImage = MV1LoadModel("data/models/Ground/Ground.mv1");
	mPos = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(mImage, mPos);
}

void Ground::Update(float _deltaTime)
{
}

void Ground::Draw()
{
	MV1DrawModel(mImage);
}
