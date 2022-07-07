#include "pch.h"

Player::Player(const VECTOR& _pos)
	: ActorBase(SceneBase::mIsScene, ActorBase::Tag::ePlayer)
{
	mModel = MV1LoadModel("Data/Models/Ground/RedGround.mv1");
	// プレイヤーのポジションを設定
	mPos = _pos;

	// プレイヤーのサイズを設定
	MV1SetScale(mModel, VGet(25.0f, 10.0f, 25.0f));
}

Player::~Player()
{
	MV1DeleteModel(mModel);
}

void Player::Update(float _deltaTime)
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPos.x += 10.0f;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPos.x -= 10.0f;
	}
	
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mPos.z -= 10.0f;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPos.z += 10.0f;
	}

	// プレイヤーのポジションを設定
	MV1SetPosition(mModel, mPos);
}

void Player::Draw()
{
	MV1DrawModel(mModel);
}
