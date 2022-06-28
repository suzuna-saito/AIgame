#pragma once

/*
フレームにかかった時間を計測し上限を設けるクラス
*/
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
	
	int mFpsCount;            // フレームのカウンター
	int mFrameStartTickTime;  // FPSの計算を始めた時の時間
	int mFps;                 // 計算したフレームレート
	int mBeforeTickCount;     // 前のフレームのかかった時間
	float mDeltaTime;         // 現在のフレームのかかった時間
};

