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
	// ゲームの描画処理
	void DrawGame();

	const int MWidth;       // 画面の横幅
	const int MHeight;      // 画面の縦幅
	const int MColorBitNum; // カラービット数

	bool mIsRunningFlag;    // ゲームを続行するかどうか

	class SceneBase* mNowScene;   // 現在のシーン
	class SceneBase* mTmpScene;   // ひとつ前のシーン

	class FPS* mFps;              // FPS計測クラス
	class Image* mImage;          // 画像データを管理しているクラス

public: // ゲッター、セッター
	// 最初のシーンをセット
	void SetFirstScene(SceneBase* _firstScene) { mNowScene = _firstScene; }

};