#include "pch.h"

Result::Result()
	: SceneBase(SceneBase::Scene::eResult)
{
	new Background();

}

Result::~Result()
{
}

void Result::Input()
{
	// シーン遷移条件(Aを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_A))
	{
		mSceneTransitionFlag = true;  // 遷移フラグを上げる
	}
}

SceneBase::Scene Result::Update()
{
	// 遷移フラグが上がっていたら
	if (mSceneTransitionFlag)
	{
		// 条件を満たしていたらタイトルシーンを生成してそのポインタを返す
		return Scene::eTitle;
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return mIsSceneTag;
}