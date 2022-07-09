#include "pch.h"

// 自身のインスタンスの初期化
UIManager* UIManager::mManager = nullptr;

UIManager::UIManager()
{
}

void UIManager::CreateInstance()
{
	if (mManager == nullptr)
	{
		mManager = new UIManager();  // インスタンスを生成
	}
}

void UIManager::DeleteInstance()
{
	// 残っているUIをすべて削除する
	for (auto UI : mManager->mUI)
	{
		delete UI;
	}

	if (mManager != nullptr)
	{
		delete mManager;  // 削除
	}
}

void UIManager::AddUI(UIBase* _ui)
{
	// UIの格納
	mManager->mUI.emplace_back(_ui);
}

void UIManager::DeleteUI()
{
	// 現在格納しているUIを全て消し、コンテナを空にする
	for (auto UI : mManager->mUI)
	{
		delete UI;
	}
	mManager->mUI.clear();
}

void UIManager::UpdateUI(float _deltaTime)
{
	for (auto UI : mManager->mUI)
	{
		UI->Update(_deltaTime);   // 各UIを更新
	}
}

void UIManager::DrawUI()
{
	for (auto UI : mManager->mUI)
	{
		UI->Draw();               // 各UIを描画
	}
}
