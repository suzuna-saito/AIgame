#pragma once

/* カメラ(1つ)関連のクラス */
class Camera :public ActorBase
{
public:
	// コンストラクタ
	Camera();
	// デストラクタ
	~Camera() {};

	// インスタンスを作成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

//	// カメラのアップデート
//	void Update(float _deltaTime)override;
//
//	/// <summary>
///// 描画
///// </summary>
//	void Draw()override;

private:
	static Camera* mCamera;  // Cameraの実体（アプリ内に唯一存在）

	const float MNear;       // カメラの手前クリップ距離
	const float MFar;        // カメラの奥クリップ距離

	VECTOR mPrevious;        // カメラ位置を保存する
	VECTOR mViewpoint;       // 注視点
};

