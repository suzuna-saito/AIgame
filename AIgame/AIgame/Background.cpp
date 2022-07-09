#include "pch.h"

Background::Background()
	: UIBase(SceneBase::mIsSceneTag)
{
	// シーンによって使うファイルを変える
	const char* file = nullptr;
	if (SceneBase::mIsSceneTag == SceneBase::Scene::eTitle)      // タイトル
	{
		file = "data/images/TitleScene/Char.png";
	}
	else if(SceneBase::mIsSceneTag == SceneBase::Scene::eResult) // リザルト
	{
		file = "data/images/ResultScene/Result.png";
	}

	mImage = LoadGraph(file);
}

void Background::Draw()
{
	// 試し@@@
	DrawGraph(0, 0, mImage, TRUE);
}
