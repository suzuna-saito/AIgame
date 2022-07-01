#include "pch.h"

Background::Background()
	: UIBase(SceneBase::mIsScene)
{
	const char* file = nullptr;  // 使いたいファイル名

	if (SceneBase::mIsScene == SceneBase::Scene::eTitle)
	{
		file = "data/images/TitleScene/Char.png";
	}
	else if(SceneBase::mIsScene == SceneBase::Scene::eResult)
	{
		file = "data/images/ResultScene/Result.png";
	}

	Image::UseImages(ImageType::eBackGround, file);
}

void Background::Draw()
{
	// 試し@@@
	DrawGraph(0, 0, Image::mNowUseImages[(int)ImageType::eBackGround], TRUE);
}
