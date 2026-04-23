#include "GameScene.h"

using namespace KamataEngine;

// 初期化
void GameScene::Initialize() { 
	Model2::StaticFinalize();
	// カメラ生成
	camera_->Initialize();
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("Resources/white1x1.png");
	//ワールド座標
	worldTransform_.Initialize();


}
// 更新
void GameScene::Update() {}
// 描画
void GameScene::Draw() {
	Model::PreDraw()
}
// デストラクタ
GameScene::~GameScene() { 
	Model2::StaticFinalize();
}
