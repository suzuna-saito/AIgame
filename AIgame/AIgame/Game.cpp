#include "pch.h"

Game::Game()
	: MWidth(1920)
	, MHeight(1080)
	, mIsRunningFlag(true)
	, mFps(nullptr)
	, mInputSystem(nullptr)
	, mNowScene(nullptr)
	, mTmpScene(nullptr)
{
}

bool Game::Initialize()
{
	//// SDLの初期化
	//// 返り値の整数が0でなかったら
	//if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO |
	//	SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) != 0)
	//{
	//	printf("SDLを初期化できません : %s", SDL_GetError());
	//	return false;
	//}

	//入力管理クラスの初期化
	mInputSystem = new InputSystem();
	if (!mInputSystem->Initialize())
	{
		printf("インプットシステムの初期化に失敗しました");
		return false;
	}

	//// ウィンドウの作成
	//if (!mWindow)
	//{
	//	printf("ウィンドウの作成に失敗しました : %s", SDL_GetError());
	//	return false;
	}

	//// レンダラーの初期化
	//Renderer::CreateInstance();
	//if (!Renderer::Initialize())
	//{
	//	printf("レンダラーの初期化に失敗しました\n");
	//	Renderer::DeleteInstance();
	//	return false;
	//}

	// FPS管理クラスの初期化
	mFps = new FPS();

	// オブジェクト管理クラスの作成
	ActorManager::CreateInstance();
	// カメラクラスの作成
	Camera::CreateInstance();

	return true;
}

void Game::GameLoop()
{
	while (mIsRunningFlag)
	{
		// 入力関連の処理
		ProcessInput();

		// 現在のシーンの入力処理
		//mNowScene->Input(mInputSystem->GetState());

		// 現在のシーンの更新処理
		mTmpScene = mNowScene->Update();

		// シーンの切り替えが発生した？
		if (mTmpScene != mNowScene)
		{
			// 現在のシーンの解放
			delete mNowScene;

			//// いらないアクターを削除する
			//ActorManager::RemoveActor();

			// 現在実行中のシーンの切り替え
			mNowScene = mTmpScene;
			continue;
		}

		// ゲームの更新処理
		UpdateGame();
		// 現在のシーンの描画処理
		Renderer::Draw();
		// FPSの更新処理
		mFps->Update();
	}
}

void Game::Termination()
{
	// データのアンロード
	UnloadData();

	// 実体を一つしか持たないクラスの解放処理

	// クラスの解放処理
	delete mFps;
	delete mInputSystem;

}

void Game::ProcessInput()
{
	//mInputSystem->PrepareForUpdate();

	//SDL_Event event;
	//// キューにイベントがあれば繰り返す
	//while (SDL_PollEvent(&event))
	//{
	//	switch (event.type)
	//	{
	//	case SDL_QUIT:
	//		mIsRunningFlag = false;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//mInputSystem->Update();

	// 現在の状態が格納された配列
	//const InputState& state = mInputSystem->GetState();

	// ESCキーか、@@@コントローラーの終了が押されたら
	/*if (state.m_keyboard.GetKeyState(SDL_SCANCODE_ESCAPE) == ButtonState::eReleased ||
		SceneBase::mIsScene == SceneBase::Scene::eEnd)
	{
		mIsRunningFlag = false;
	}*/

	// アクターの入力状態の更新
}

void Game::UpdateGame()
{
	// アクターの更新処理
}

void Game::UnloadData()
{
	// 描画しているデータを削除
}