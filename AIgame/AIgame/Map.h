#pragma once

/* マップ生成クラス */
class Map
{
public:
	// コンストラクタ
	Map();
	// デストラクタ
	~Map();

	/// <summary>
	/// jsonファイルをRapidJsonで読み込んでマップデータを各配列に格納する
	/// </summary>
	/// <returns>true : ファイルを開けた , false : ファイルが開けなかった</returns>
	bool OpenFile();

	// 床を生成する
	void CreateGround();

private:
	/// <summary>
	/// データの読み込み処理
	/// </summary>
	/// <param name="_mapData">データ</param>
	/// <param name="_fileName">ファイル名</param>
	/// <param name="_layerName">レイヤー名</param>
	/// <returns>true : 読み込み完了 , false : 読み込み失敗</returns>
	bool ReadTiledJson(std::vector<std::vector<int>>& _mapData, const char* _fileName, const char* _layerName);

	/// <summary>
	/// 全てのlayerから該当layerの添え字を調べる
	/// </summary>
	/// <param name="_layer">layer全体</param>
	/// <param name="_layerName">該当レイヤー名</param>
	/// <returns>-1 : なかった</returns>
	int FindLayerIndex(rapidjson::GenericArray<false, rapidjson::Value>& _layer, std::string& _layerName);

	std::vector<std::vector<int>> mMapDate; // マップデータ

	Vector2 mMapSize;                       // マップデータサイズ(x,y)
	Vector3 mObjDistance;                   // オブジェクトごとの距離(x,y,z)
};