#include "pch.h"

// 自身のインスタンスの初期化
Image* Image::mImage = nullptr;
// 静的メンバ変数の初期化
std::vector<int> Image::mNowUseImages;

Image::Image()
{
}

Image::~Image()
{
	UnLoad();
}

void Image::CreateInstance()
{
	if (mImage == nullptr)
	{
		mImage = new Image();  // インスタンスを生成
	}
}

void Image::DeleteInstance()
{
	if (mImage != nullptr)
	{
		delete mImage;  // 削除
	}
}

void Image::Load()
{
	// 先に使わない画像データを解放
	mImage->UnLoad();

	// 現在のシーンで使う画像データを
	for (auto type : mImage->mUseTypes)
	{
		mImage->mNowUseImages.emplace_back(LoadGraph(mImage->mFile[type]));  // mNowUseImagesに格納
	}
}

void Image::UseImages(ImageType _type, const char* _file)
{
	// 今使いたい画像の種類を格納
	mImage->mUseTypes.emplace_back(_type);
	std::sort(mImage->mUseTypes.begin(), mImage->mUseTypes.end());                                                      // mTypeの中身をソート
	mImage->mUseTypes.erase(std::unique(mImage->mUseTypes.begin(), mImage->mUseTypes.end()), mImage->mUseTypes.end());  // 重複している要素を削除

	// 読み込みたいファイルと画像の種類を関連付け
	mImage->mFile[_type] = _file;

	// この画像ファイルと生成した時のシーンを関連付ける
	mImage->mGeneratedScene.insert({ _file,SceneBase::mIsSceneTag });
}

void Image::UnLoad()
{
	// 使っていた画像データをメモリ上から削除する
	for (auto images : mNowUseImages)
	{
		DeleteGraph(images);
	}
	// mNowUseImagesを空っぽにする
	mNowUseImages.clear();

	// 現在のシーンで使う画像の種類のみmUseTypesに格納
	for (auto type : mUseTypes)
	{
		if (mGeneratedScene[mFile[type]] == SceneBase::mIsSceneTag)
		{
			mPendingType.emplace_back(type);  // 使う画像のタイプをmPendingTypeに格納
		}
	}
	mUseTypes = mPendingType;                 // mUseTypesに格納
	mPendingType.clear();

	mGeneratedScene.clear();                  // mGeneratedSceneを空っぽにする
}
