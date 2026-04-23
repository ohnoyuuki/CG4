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

	private:
		//カメラ
	    Camera* camera_ = nullptr;
		//テクスチャハンドル
	    uint32_t textureHandle_ = 0;
		//四角形
	    Model* model_ = nullptr;
		//ワールド座標
	    WorldTransform worldTransform_;
};
