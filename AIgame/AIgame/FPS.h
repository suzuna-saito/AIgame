#pragma once

/* フレームにかかった時間を計測し上限を設けるクラス */
class FPS
{
public:
	// コンストラクタ
	FPS();
	// デストラクタ
	~FPS() {};

	// フレーム毎の処理
	void Update();

private:
	// FPSが設定値より大きくならないように制御
	void Wait();

	const int MSetFps;             // フレームレートの最高値
	const int MOneFrameTickCount;  // 1フレームにかける時間
	
	int mBeforeTickCount;     // 前のフレームのかかった時間
	float mDeltaTime;         // 現在のフレームのかかった時間

public:   // ゲッター、セッター
	// 現在のフレームにかかった時間(float型)
	float GetDeltaTime() { return mDeltaTime; }
};

