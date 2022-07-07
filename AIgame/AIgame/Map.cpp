#include "pch.h"

Map::Map()
	: mMapSize(Vector2::Zero)
	, mObjDistance(100.0f, 0.0f, 100.0f)
{
}

Map::~Map()
{
}

bool Map::OpenFile()
{
	// @@@ test
	// データの読み込み
	if (!ReadTiledJson(mGroundMapDate, "Data/Config/test.json", "Ground"))
	{
		printf("don't have Layer/test\n");
		return true;
	}

	mMapSize.x = mGroundMapDate[0].size();
	mMapSize.y = mGroundMapDate.size();

	if (!ReadTiledJson(mPlayerMapDate, "Data/Config/test.json", "Player"))
	{
		printf("don't have Layer/test\n");
		return true;
	}

	return false;
}

void Map::GroundCreate()
{
	// 奥行
	for (float iz = 0; iz < mMapSize.y; ++iz)
	{
		// 横幅
		for (float ix = 0; ix < mMapSize.x; ++ix)
		{
			// 割り当てられている数字
			const unsigned int name = mGroundMapDate[(int)iz][(int)ix];

			// ポジション
			const VECTOR objPos = VECTOR(VGet(-mObjDistance.x * ix, 0.0f, mObjDistance.z * iz));

			// 割り当てられている数字が1だったら
			if (name == 1)
			{
				new Ground(objPos); // 床の生成
			}
		}

	}
}

void Map::PlayerCreate()
{
	// 奥行
	for (float iz = 0; iz < mMapSize.y; ++iz)
	{
		// 横幅
		for (float ix = 0; ix < mMapSize.x; ++ix)
		{
			// 割り当てられている数字
			const unsigned int name = mPlayerMapDate[(int)iz][(int)ix];

			// ポジション
			const VECTOR objPos = VECTOR(VGet(-mObjDistance.x * ix, 20.0f, mObjDistance.z * iz));

			// 割り当てられている数字が2だったら
			if (name == 2)
			{
				new Player(objPos); // プレイヤーの生成
			}
		}

	}

}

bool Map::ReadTiledJson(std::vector<std::vector<int>>& _mapData, const char* _fileName, const char* _layerName)
{
	// RapidJsonドキュメントとして開けるか？
	rapidjson::Document doc;
	if (!OpenJsonFile(doc, _fileName))
	{
		return false;
	}
	// 開いたdocumentのtypeはmapか？
	if (!IsExistMemberAndValue(doc, "type", "map"))
	{
		return false;
	}
	// 開いたdocumentにlayerはあるか？
	if (!IsExistArrayName(doc, "layers"))
	{
		return false;
	}

	// layer数を取得
	auto layer = doc["layers"].GetArray();
	int layerSize = layer.Size();

	// layer名から該当layerの添え字を調べる
	std::string layerNameString(_layerName);
	int layerIndex = FindLayerIndex(layer, layerNameString);
	if (layerIndex < 0)
	{
		return false;
	}

	// layer内にデータはあるか？
	rapidjson::Value::ConstMemberIterator itr = layer[layerIndex].FindMember("data");
	if (itr == layer[layerIndex].MemberEnd())
	{
		printf("レイヤー名:%sにマップデータがありません\n", _layerName);
		return false;
	}

	// レイヤーよりrapidjson配列作成
	const rapidjson::Value& rapidArrayData = layer[layerIndex]["data"].GetArray();
	int width, height;
	width = layer[layerIndex]["width"].GetInt();
	height = layer[layerIndex]["height"].GetInt();

	// ユーザー配列確保　行方向、列方向の順番にサイズ確保
	_mapData.resize(height);
	for (auto& mapItr : _mapData)
	{
		mapItr.resize(width);
	}

	// ユーザー配列（２次元）にデータをコピー
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			//なぜかIDが+1ずれているので補正する
			_mapData[y][x] = rapidArrayData[y * width + x].GetInt();
		}
	}

	return true;
}

int Map::FindLayerIndex(rapidjson::GenericArray<false, rapidjson::Value>& _layer, std::string& _layerName)
{
	int layerSize = _layer.Size();
	int i;

	std::string layerNameString(_layerName);

	for (i = 0; i < layerSize; ++i)
	{
		std::string currentLayerName = _layer[i]["name"].GetString();
		// 現在のレイヤー名(デバック)@
		printf("%s\n", currentLayerName.c_str());

		if (layerNameString == currentLayerName)
		{
			break;
		}
	}
	if (i == layerSize)
	{
		return -1;
	}

	return i;
}