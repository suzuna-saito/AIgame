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
	// 全てのUIをmPendingActorsに一時的に保管
	mManager->mPendingUI = mManager->mUI;

	// UIを格納するコンテナを空にする
	mManager->mUI.clear();

	// 格納するUIを判別
	for (auto UI : mManager->mPendingUI)
	{
		if (UI->GetDirthplaceScene() == SceneBase::mIsScene) // このUIが生成されたシーンと現在のシーンが一緒だったら
		{
			mManager->mUI.emplace_back(UI);                  // このUIを格納
		}
	}

	mManager->mPendingUI.clear();
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
