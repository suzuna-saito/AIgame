#include "pch.h"

Background::Background()
	: UIBase(SceneBase::mIsScene)
{
	const char* file = nullptr;

	if (SceneBase::mIsScene == SceneBase::Scene::eTitle)
	{
		file = "data/images/TitleScene/Char.png";
	}
	else if (SceneBase::mIsScene == SceneBase::Scene::ePlay)
	{
		file = "data/images/PlayScene/Play.png";
	}
	else if(SceneBase::mIsScene == SceneBase::Scene::eResult)
	{
		file = "data/images/ResultScene/Result.png";
	}

	Image::UseImages(ImageType::eBackGround, file);
}

Background::~Background()
{
}

void Background::Draw()
{
	// ŽŽ‚µ@@@
	DrawGraph(0, 0, Image::mNowUseImages[(int)ImageType::eBackGround], TRUE);
}
