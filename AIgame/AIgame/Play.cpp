#include "pch.h"

Play::Play()
	: SceneBase(SceneBase::Scene::ePlay)
{
}

Play::~Play()
{
}

void Play::Input()
{
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_RETURN))
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

void Play::Draw()
{
}
