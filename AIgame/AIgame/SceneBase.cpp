#include "pch.h"

// Œ»İ‚ÌƒV[ƒ“‚Ì‰Šú‰»
SceneBase::Scene SceneBase::mIsScene = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	mIsScene = _nowScene;
}