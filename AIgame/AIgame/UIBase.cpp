#include "pch.h"

UIBase::UIBase(const SceneBase::Scene& _nowScene)
	: mDirthplaceScene(_nowScene)
	, mPos()
	, mImages()
{
	// UI‚ð’Ç‰Á‚·‚é
	UIManager::AddUI(this);
}

UIBase::~UIBase()
{
}