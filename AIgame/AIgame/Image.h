#pragma once

/* すべての画像をロードするクラス */
class Image
{
public:
	// コンストラクタ
	Image();
	// デストラクタ
	~Image();


private:
	// 画像ファイル // @@@
	std::vector<const char*> mTitleImages;
	std::vector<const char*> mPlayImages;
};

