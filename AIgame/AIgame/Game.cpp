#include "pch.h"

Game::Game()
	: MWidth(650)
	, MHeight(1080)
	, MColorBitNum(16)
	, mIsRunningFlag(true)
	, mNowScene(nullptr)
	, mTmpScene(nullptr)
	, mFps(nullptr)
{
}

bool Game::Initialize()
{
	// 画面モードのセット
	SetGraphMode(MWidth, MHeight, MColorBitNum);
	ChangeWindowMode(TRUE);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return false;
	}

	// FPS管理クラスの初期化
	mFps = new FPS();

	// 実態を一つしか持たないクラスの作成
	UIManager::CreateInstance();  // UI管理クラス
	Image::CreateInstance();      // 画像を管理するクラス

	return true;
}

void Game::GameLoop()
{
	Image::Load();   // 必要画像を読み込み
	
	while (mIsRunningFlag)
	{
		// 入力関連の処理
		ProcessInput();

		// 現在のシーンの入力処理
		mNowScene->Input();

		// 現在のシーンの更新処理
		mTmpScene = mNowScene->Update();

		// シーンの切り替えが発生したら
		if (mTmpScene != mNowScene)
		{
			delete mNowScene;           // 現在のシーンの解放
			mNowScene = mTmpScene;      // 現在実行中のシーンの切り替え

			UIManager::DeleteUI();      // いらないUIを削除する
			Image::Load();              // 必要画像を読み込み

			continue;
		}

		// ゲームの更新処理
		UpdateGame();
		// FPSの更新処理
		mFps->Update();

		// 画面を初期化する
		ClearDrawScreen();

		// 現在のシーンを描画
		DrawGame();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}
}

void Game::Termination()
{
	// 実体を一つしか持たないクラスの解放処理
	UIManager::DeleteInstance();
	Image::DeleteInstance();
\
	// クラスの解放処理
	delete mNowScene;
	delete mFps;

	// DXライブラリの後始末
	DxLib_End();
}

void Game::ProcessInput()
{
	// Escキーが押されるか、ウィンドウが閉じられたら
	if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		mIsRunningFlag = false;   // ゲームループフラグをfalseにする
	}
}

void Game::UpdateGame()
{
	float deltaTime = mFps->GetDeltaTime();
}

void Game::DrawGame()
{
	UIManager::DrawUI();  // UI
}
