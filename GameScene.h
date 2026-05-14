#pragma once
#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class GameScene {

public:
	// 初期化
	void Initialize();
	// 毎フレーム更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~GameScene();
	GameScene();

private:
	// カメラ
	Camera camera_;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	Model2* model2 = nullptr;

	// ワールド変換データ
	WorldTransform worldTransform_;
};