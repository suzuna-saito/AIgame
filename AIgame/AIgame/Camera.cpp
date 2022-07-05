#include "pch.h"

// 自身のインスタンスの初期化
Camera* Camera::mCamera = nullptr;

Camera::Camera()
	: ActorBase(SceneBase::Scene::eInit, Tag::eCamera)
	, MNear(0.1f)
	, MFar(10000.0f)
	, mViewpoint(VGet(0.0f, 0.0f, 0.0f))
{
	// 斜め上から見下ろす位置
	mPos = VECTOR(VGet(100.0f, 100.0f, 100.0f));
	mPrevious = mPos;

	// カメラの描画範囲を設定
	SetCameraNearFar(MNear, MFar);
	SetCameraPositionAndTargetAndUpVec(mPos, mViewpoint,VGet(0.0f,1.0f,0.0f));
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

void Camera::Update(float _deltaTime)
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPos.x += 10.0f;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPos.x -= 10.0f;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		mPos.y += 10.0f;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPos.y -= 10.0f;
	}

	if (CheckHitKey(KEY_INPUT_W))
	{
		mPos.z -= 10.0f;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{
		mPos.z += 10.0f;
	}

	SetCameraPositionAndTarget_UpVecY(mPos, mViewpoint);

	unsigned int Color;

	Color = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Color, "x : %f\ny : %f\nz : %f\n", mCamera->mPos.x, mCamera->mPos.y, mCamera->mPos.z);

}