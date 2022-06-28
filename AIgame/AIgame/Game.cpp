#include "pch.h"

Game::Game()
	: MWidth(650)
	, MHeight(1080)
	, MColorBitNum(16)
	, mNowScene(nullptr)
	, mTmpScene(nullptr)
	, mIsRunningFlag(true)
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

	return true;
}

void Game::GameLoop()
{
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
			continue;
		}

		// 画面を初期化する
		ClearDrawScreen();

		// 現在のシーンを描画
		mNowScene->Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		// ゲームの更新処理
		UpdateGame();
	}
}

void Game::Termination()
{
	// 現在のシーンの解放
	delete mNowScene;
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
}