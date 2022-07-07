#include "pch.h"

Play::Play()
	: SceneBase(SceneBase::Scene::ePlay)
{
	mMapCreate = new Map();

	if (!mMapCreate->OpenFile())
	{
		mMapCreate->GroundCreate();
		mMapCreate->PlayerCreate();
	}
}

Play::~Play()
{
	delete mMapCreate;
}

void Play::Input()
{
	// シーン遷移条件(spaceを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		mSceneTransitionFlag = true;  // 遷移フラグを上げる
	}
}

SceneBase* Play::Update()
{
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (mSceneTransitionFlag)
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new Result();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}