#include "pch.h"

// 現在のシーンの初期化
SceneBase::Scene SceneBase::mIsScene = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	// 現在のシーンタグを更新
	mIsScene = _nowScene;
}