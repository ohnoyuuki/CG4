#include "GameScene.h"
#include <ctime>
#include <numbers>


// 初期化
void GameScene::Initialize() {

	// 乱数の初期化
	srand((unsigned int)time(nullptr));

	Model2::StaticInitialize();

	// カメラの初期化
	camera_.Initialize();
	// ファイル名を指定してテクスチャを読み込む
	//textureHandle_ = TextureManager::Load("uvChecker.png");
	textureHandle_ = TextureManager::Load("white1x1.png");

	// 菱形モデルの生成
	modelDiamond_ = Model2::CreateDiamond();

	for (uint32_t i = 0; i < kEffectCount; i++) {

		worldTransforms_[i].Initialize();

		// X方向は細く固定
		worldTransforms_[i].scale_.x = 0.2f;

		// Y方向をランダム
		worldTransforms_[i].scale_.y = 5.0f + (float)rand() / RAND_MAX * 15.0f;

		worldTransforms_[i].scale_.z = 1.0f;

		// Z回転をランダム
		worldTransforms_[i].rotation_.z = (float)rand() / RAND_MAX * (std::numbers::pi_v<float> * 2.0f);

		worldTransforms_[i].UpdateMatrix();
	}
}

// 更新
void GameScene::Update() {
	// 3Dモデルを更新
	for (uint32_t i = 0; i < kEffectCount; i++) {
		worldTransforms_[i].UpdateMatrix();
	}
}


// 描画
void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// リングモデルを描画
	//model2->Draw(worldTransform_, camera_, textureHandle_);

	// 菱形モデルを描画
	for (uint32_t i = 0; i < kEffectCount; i++) {

		modelDiamond_->Draw(worldTransforms_[i], camera_, textureHandle_);
	}

	// 3Dモデル描画後処理
	Model2::PostDraw();
}


// デストラクタ
GameScene::~GameScene() {
	// 3Dモデルデータの解放
	//delete model2;

	delete modelDiamond_;
	modelDiamond_ = nullptr;

	Model2::StaticFinalize();
}

GameScene::GameScene() {}
