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

	Model2* model2_ = nullptr;

	Model2* model2_2_ = nullptr;

	Model2* model2_3_ = nullptr;


	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	Model2* model2 = nullptr;

	Model2* modelDiamond_ = nullptr;

	Model2* modelEffect_ = nullptr;


	// ワールド変換データ
	WorldTransform worldTransform_;
};