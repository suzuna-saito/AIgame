#pragma once
class Ground :public ActorBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Ground();
	// デストラクタ
	~Ground() {};

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	virtual void Update(float _deltaTime)override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;
};