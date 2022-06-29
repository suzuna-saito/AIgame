#pragma once

/* すべての画像をロードするクラス */
class Image
{
public:
	// コンストラクタ
	Image();
	// デストラクタ
	~Image();

	// 必要画像を読み込む
	void Load();

protected:
	std::vector<int> mNowUseImages;   // 現在使う画像データ

private:
	// いらない画像を解放
	void UnLoad();

	// タイトルで使う画像ファイルを格納する
	void TitleImageFile();
	// プレイ中に使う画像ファイルを格納する
	void PlayImageFile();
	// リザルトで使う画像ファイルを格納する
	void ResultImageFile();

	std::map<SceneBase::Scene, std::vector<const char*>> mFiles;  // 画像ファイルをシーンごとに格納
};

