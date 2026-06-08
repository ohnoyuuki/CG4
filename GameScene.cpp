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

	//  ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.scale_ = {2, 2, 2};
	// 3Dモデルデータの生成
	//model2 = Model2::CreateSquare(5);
	// リングモデルの生成
	//model2 = Model2::CreateRing(16);
	
	// 菱形モデルの生成
	modelDiamond_ = Model2::CreateDiamond();
	// 3Dモデルデータ生成
	//modelEffect_ = Model2::CreateFromOBJ("plane");

	// Y方向の大きさを乱数で決定
	worldTransform_.scale_.x = 0.2f;
	worldTransform_.scale_.y = 5.0f + (float)rand() / RAND_MAX * 15.0f;
	worldTransform_.scale_.z = 1.0f;

	// Z軸回転を乱数で決定（0～2π）
	worldTransform_.rotation_.z = (float)rand() / RAND_MAX * (std::numbers::pi_v<float> * 2.0f);

	worldTransform_.UpdateMatrix();
}

// 更新
void GameScene::Update() {
	// 3Dモデルを更新
	worldTransform_.UpdateMatrix();
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
	modelDiamond_->Draw(worldTransform_, camera_, textureHandle_);

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
