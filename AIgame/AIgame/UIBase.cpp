#include "pch.h"

UIBase::UIBase(const SceneBase::Scene& _nowScene)
	: mGeneratedScene(_nowScene)
	, mPos()
	, mImages()
{
	// UI‚ð’Ç‰Á‚·‚é
	UIManager::AddUI(this);
}

UIBase::~UIBase()
{
}