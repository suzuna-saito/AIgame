#include "pch.h"

Background::Background()
	: UIBase(SceneBase::mIsScene)
{
}

Background::~Background()
{
}

void Background::Draw()
{
	// ŽŽ‚µ@@@
	DrawGraph(0, 0, mNowUseImages[0], TRUE);
}
