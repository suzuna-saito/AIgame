#include "pch.h"

Image::Image()
{
	TitleImageFile();
	PlayImageFile();
	ResultImageFile();

	Load();
}

Image::~Image()
{
	UnLoad();

	// vectorデータのクリア
	mFiles[SceneBase::Scene::eTitle].clear();
	mFiles[SceneBase::Scene::ePlay].clear();
	mFiles[SceneBase::Scene::eResult].clear();

	// map構造体のクリア
	mFiles.clear();
}

void Image::Load()
{
	// 先に使わない画像データを解放
	UnLoad();

	// 現在のシーンで使う画像データを
	for (auto file : mFiles[SceneBase::mIsScene])
	{
		mNowUseImages.emplace_back(LoadGraph(file));  // mNowUseImagesに格納
	}
}

void Image::UnLoad()
{
	for (auto images : mNowUseImages)  // 使っていた画像データをメモリ上から削除する
	{
		DeleteGraph(images);
	}

	mNowUseImages.clear();            // mNowUseImagesを空っぽにする
}

void Image::TitleImageFile()
{
	mFiles[SceneBase::Scene::eTitle].emplace_back("data/images/TitleScene/Char.png");
}

void Image::PlayImageFile()
{
	mFiles[SceneBase::Scene::ePlay].emplace_back("data/images/PlayScene/Play.png");
}

void Image::ResultImageFile()
{
	mFiles[SceneBase::Scene::eResult].emplace_back("data/images/ResultScene/Result.png");
}
