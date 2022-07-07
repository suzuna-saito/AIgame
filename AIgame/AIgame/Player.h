#pragma once

/* プレイヤー関連のクラス */
class Player :public ActorBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_pos">ポジション</param>
	Player(const VECTOR& _pos);
	// デストラクタ
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	void Update(float _deltaTime)override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;

};

