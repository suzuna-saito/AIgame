#pragma once

/*
ゲームの進行を行うクラス
*/
class Game
{
public:
	// コンストラクタ
	Game();
	// デストラクタ
	~Game() {};

	// 初期化処理
	// return true : 成功、false : 失敗
	bool Initialize();
	// ゲームループ
	void GameLoop();
	// 終了処理
	void Termination();

private:
	// 入力関連の処理
	void ProcessInput();
	// ゲームの更新処理
	void UpdateGame();
	// ロードしたデータの解放
	void UnloadData();

	// ウィンドウの横幅
	const int MWidth;
	// ウィンドウの縦幅
	const int MHeight;

	// ゲームを続行するかどうか
	bool mIsRunningFlag;

	// 現在のシーン
	SceneBase* mNowScene;
	// ひとつ前のシーン
	SceneBase* mTmpScene;

	//FPS計測クラス
	FPS* mFps;

	// 入力管理クラス
	InputSystem* mInputSystem;

public: // ゲッター、セッター
	// 最初のシーンをセット
	void SetFirstScene(SceneBase* _firstScene) { mNowScene = _firstScene; }
};

