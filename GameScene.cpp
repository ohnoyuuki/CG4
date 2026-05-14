#include "GameScene.h"

using namespace KamataEngine;

// GameScene::GameScene() {}

// 初期化
void GameScene::Initialize() {

	
	// カメラ生成
	camera_->Initialize();
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");
	// ワールド座標
	worldTransform_.Initialize();
	worldTransform_.scale_ = {2, 2, 2};
	// 四角形３Dモデル生成
	model2 = Model2::CreateSquare(1);

	Model2::StaticFinalize();
}

// 更新
void GameScene::Update() {
	// 3Dモデル更新
	worldTransform_.UpdateMatrix();
}

// 描画
void GameScene::Draw() { Model::PreDraw(); }

// デストラクタ
GameScene::~GameScene() {
	// 3Dモデル解放
	delete model2;

	Model2::StaticFinalize();
}
