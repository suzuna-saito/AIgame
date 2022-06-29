#include "pch.h"

Title::Title()
	: SceneBase(SceneBase::Scene::eTitle)
{
}

Title::~Title()
{
}

void Title::Input()
{
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		mSceneTransitionFlag = true;  // 遷移フラグを上げる
	}
}

SceneBase* Title::Update()
{
	// 遷移フラグが上がっていたら
	if (mSceneTransitionFlag)
	{
		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return new Play();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}