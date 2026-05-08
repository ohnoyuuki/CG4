#pragma once
#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class GameScene {

public:

	//GameScene();

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
	    Camera* camera_;
		//テクスチャハンドル
	    uint32_t textureHandle_ = 0;
		//四角形
	    Model2* model2 = nullptr;
		//ワールド座標
	    WorldTransform worldTransform_;
};
