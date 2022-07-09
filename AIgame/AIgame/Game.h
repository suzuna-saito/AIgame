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
	// mNextSceneTagを参考に新しいシーンを生成する
	void NewScene();
	// 入力関連の処理
	void ProcessInput();
	// ゲームの更新処理
	void UpdateGame();
	// ゲームの描画処理
	void DrawGame();

	const int MWidth;       // 画面の横幅
	const int MHeight;      // 画面の縦幅
	const int MColorBitNum; // カラービット数
	const int MZbitNum;     // Zバッファの1ピクセル辺りのビット数

	bool mIsRunningFlag;    // ゲームを続行するかどうか

	class SceneBase* mNowScene;        // 現在のシーン
	SceneBase::Scene mReturnSceneTag;  // updateで返ってきたシーンのタグ

	class FPS* mFps;                   // FPS計測クラス

public: // ゲッター、セッター
	// 最初のシーンをセット
	void SetFirstScene(SceneBase* _firstScene) { mNowScene = _firstScene; }

};