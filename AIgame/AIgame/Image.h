#pragma once

/* すべての画像をロードするクラス */
class Image
{
public:
	// コンストラクタ
	Image();
	// デストラクタ
	~Image();

	// インスタンスを生成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	// 必要画像を読み込む
	static void Load();

protected:
	// 画像の種類
	enum class ImageType :unsigned char
	{
		eBackGround,  // 背景
	};

	/// <summary>
	/// 使用する画像データを格納する
	/// </summary>
	/// <param name="_type">画像の種類</param>
	/// <param name="_file">画像ファイル</param>
	static void UseImages(ImageType _type, const char* _file);

	static std::vector<int> mNowUseImages;   // 現在使う画像データ

private:
	static Image* mImage;

	// いらない画像を解放
	void UnLoad();

	std::vector<ImageType> mUseTypes;                         // 使いたい画像の種類を格納
	std::map<ImageType, const char*> mFile;                   // キー：画像の種類　値：読み込みたい画像ファイル
	std::map<const char*, SceneBase::Scene> mGeneratedScene;  // キー：画像ファイル　値：生成したシーン

	std::vector<ImageType> mPendingType;                      // 一時的に使いたい画像の種類を保存するコンテナ
};