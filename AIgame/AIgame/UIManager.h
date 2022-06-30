#pragma once

/* すべてのUIの更新を行う */
class UIManager
{
public:
	//	コンストラクタ
	UIManager();
	// デストラクタ
	~UIManager() {};

	// インスタンスを生成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	/// <summary>
	/// UIの追加
	/// </summary>
	/// <param name="_ui">追加するUIのポインタ</param>
	static void AddUI(class UIBase* _ui);
	/// <summary>
	/// すべてのUIの削除
	/// </summary>
	static void DeleteUI();

	/// <summary>
	/// すべてのUIの更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	static void UpdateUI(float _deltaTime);

	/// <summary>
	/// UIの描画
	/// </summary>
	static void DrawUI();

private:
	static UIManager* mManager;      // UIManagerの実体（アプリ内に唯一存在）

	std::vector<UIBase*>mUI;         // すべてのUIを格納するコンテナ
	std::vector<UIBase*>mPendingUI;  // 一時的にUIを保存するコンテナ
};