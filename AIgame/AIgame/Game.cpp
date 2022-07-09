#include "pch.h"

Game::Game()
	: MWidth(1920)
	, MHeight(1080)
	, MColorBitNum(16)
	, MZbitNum(24)
	, mIsRunningFlag(true)
	, mNowScene(nullptr)
	, mReturnSceneTag(SceneBase::mIsSceneTag)
	, mFps(nullptr)
{
}

bool Game::Initialize()
{
	// 画面モードのセット
	SetGraphMode(MWidth, MHeight, MColorBitNum);
	ChangeWindowMode(TRUE);

	// Ｚバッファの1ピクセル辺りのビット数をデフォルトの16から24に変更
	SetZBufferBitDepth(MZbitNum);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return false;    // エラーが起きたら直ちに終了
	}

	// FPS管理クラスの初期化
	mFps = new FPS();

	// 実態を一つしか持たないクラスの作成
	UIManager::CreateInstance();    // UI管理クラス
	ActorManager::CreateInstance(); // Actor管理クラス
	Camera::CreateInstance();       // カメラ

	return true;
}

void Game::GameLoop()
{	
	// ゲーム続行フラグがたってたら
	while (mIsRunningFlag)
	{
		ProcessInput();                        // 入力関連の処理

		mReturnSceneTag = mNowScene->Update(); // 現在のシーンの更新処理

		// シーンタグのの切り替えが発生したら
		if (mReturnSceneTag != SceneBase::mIsSceneTag)
		{
			delete mNowScene;                       // 現在のシーンの解放

			UIManager::DeleteUI();                  // UIを削除する
			ActorManager::DeleteActor();            // アクターを削除する

			NewScene();                             // 新しいシーンを生成
			continue;
		}

		UpdateGame();     // ゲームの更新処理
		DrawGame();       // 現在のシーンを描画
	}
}

void Game::Termination()
{
	// 実体を一つしか持たないクラスの解放処理
	UIManager::DeleteInstance();  // UIマネージャー
	ActorManager::DeleteActor();  // Actorマネージャー
	Camera::DeleteInstance();     // カメラ

	// クラスの解放処理
	delete mNowScene;
	delete mFps;

	// DXライブラリの後始末
	DxLib_End();
}

void Game::NewScene()
{
	// 返り値で返ってきたタグがタイトルだったら
	if (mReturnSceneTag == SceneBase::Scene::eTitle)
	{
		mNowScene = new Title();   // タイトルを生成
	}
	// 返り値で返ってきたタグがプレイだったら
	else if (mReturnSceneTag == SceneBase::Scene::ePlay)
	{
		mNowScene = new Play();    // プレイを生成
	}
	// 返り値で返ってきたタグがリザルトだったら
	else if (mReturnSceneTag == SceneBase::Scene::eResult)
	{
		mNowScene = new Result();  // リザルトを生成
	}
}

void Game::ProcessInput()
{
	// Escキーが押されるか、ウィンドウが閉じられたら
	if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		mIsRunningFlag = false;   // ゲームループフラグをfalseにする
	}

	// 現在のシーンの入力処理
	mNowScene->Input();
}

void Game::UpdateGame()
{
	// デルタタイムを更新
	float deltaTime = mFps->GetDeltaTime();

	ActorManager::UpdateActor(deltaTime); // アクター

	// FPSの更新処理
	mFps->Update();
}

void Game::DrawGame()
{
	// 画面を初期化する
	ClearDrawScreen();

	UIManager::DrawUI();       // UI
	ActorManager::DrawActor(); // アクター

	// 裏画面の内容を表画面に反映させる
	ScreenFlip();
}
