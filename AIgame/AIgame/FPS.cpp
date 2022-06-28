#include "pch.h"

FPS::FPS()
	: MSetFps(60)
	, MOneFrameTickCount(1000 / MSetFps)
	, mBeforeTickCount(0)
	, mDeltaTime(0)
{
}

void FPS::Update()
{
	Wait();

	mDeltaTime = (GetNowCount() - mBeforeTickCount) / 1000.0f;
	// デルタタイムを制御
	if (mDeltaTime >= 0.10f)
	{
		mDeltaTime = 0.10f;
	}

	mBeforeTickCount = GetNowCount();
}

void FPS::Wait()
{
	int aiu = GetNowCount();
	// 現在値が1フレームにかける時間を超えるまで繰り返す
	while (GetNowCount() < mBeforeTickCount + MOneFrameTickCount);
}
