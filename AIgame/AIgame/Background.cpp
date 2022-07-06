#include "pch.h"

Background::Background()
	: UIBase(SceneBase::mIsScene)
{
	// シーンによって使うファイルを変える
	const char* file = nullptr;
	if (SceneBase::mIsScene == SceneBase::Scene::eTitle)      // タイトル
	{
		file = "data/images/TitleScene/Char.png";
	}
	else if(SceneBase::mIsScene == SceneBase::Scene::eResult) // リザルト
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
