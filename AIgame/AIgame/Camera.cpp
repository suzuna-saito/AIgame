#include "pch.h"

// 自身のインスタンスの初期化
Camera* Camera::mCamera = nullptr;

Camera::Camera()
	: ActorBase(SceneBase::Scene::eInit, Tag::eCamera)
	, MNear(1.0f)
	, MFar(1000.0f)
	, mViewpoint(VGet(0.0f, 0.0f, 0.0f))
{
	// 斜め上から見下ろす位置
	mPos = VECTOR(VGet(-1000.0f, 1000.0f, 0.0f));
	mPrevious = mPos;

	// カメラの描画範囲を設定
	SetCameraNearFar(MNear, MFar);
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

void Camera::Update(float _deltaTime)
{
}