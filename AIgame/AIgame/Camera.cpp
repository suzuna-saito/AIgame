#include "pch.h"

// 自身のインスタンスの初期化
Camera* Camera::mCamera = nullptr;

Camera::Camera()
	: MNear(20.0f)
	, MFar(10000.0f)
	, mViewpoint(VGet(-450.0f, 0.0f, 450.0f))
{
	// 斜め上から見下ろす位置
	mPos = VECTOR(VGet(-450.0f, 1000.0f, 1700.0f));
	mPrevious = mPos;

	// カメラの描画範囲を設定
	SetCameraNearFar(MNear, MFar);
	// カメラの視点、注視点を設定
	SetCameraPositionAndTarget_UpVecY(mPos, mViewpoint);
}

void Camera::CreateInstance()
{
	if (mCamera == nullptr)
	{
		mCamera = new Camera();  // インスタンスを生成
	}
}

void Camera::DeleteInstance()
{
	if (mCamera != nullptr)
	{
		delete mCamera;          // 削除
		mCamera = nullptr;
	}
}

//void Camera::Update(float _deltaTime)
//{
//	if (CheckHitKey(KEY_INPUT_LEFT))
//	{
//		mPos.x += 10.0f;
//	}
//	else if (CheckHitKey(KEY_INPUT_RIGHT))
//	{
//		mPos.x -= 10.0f;
//	}
//
//	if (CheckHitKey(KEY_INPUT_UP))
//	{
//		mPos.y += 10.0f;
//	}
//	else if (CheckHitKey(KEY_INPUT_DOWN))
//	{
//		mPos.y -= 10.0f;
//	}
//
//	if (CheckHitKey(KEY_INPUT_W))
//	{
//		mPos.z -= 10.0f;
//	}
//	else if (CheckHitKey(KEY_INPUT_S))
//	{
//		mPos.z += 10.0f;
//	}
//
//	SetCameraPositionAndTarget_UpVecY(mPos, mViewpoint);
//}
//
//void Camera::Draw()
//{
//	unsigned int Color;
//
//	Color = GetColor(255, 255, 255);
//	DrawFormatString(0, 0, Color, "x : %f\ny : %f\nz : %f\n", mCamera->mPos.x, mCamera->mPos.y, mCamera->mPos.z);
//
//}
