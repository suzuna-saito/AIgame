#include "pch.h"

FPS::FPS()
	: MSetFps(60)
	, MOneFrameTickCount(1000 / MSetFps)
	, mFpsCount(0)
	, mFrameStartTickTime(0)
	, mFps(0)
	, mBeforeTickCount(0)
	, mDeltaTime(0)
{
}

void FPS::Update()
{
}

void FPS::Wait()
{
}
