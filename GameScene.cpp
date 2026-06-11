#include "GameScene.h"
#include <ctime>
#include <numbers>


// 初期化
void GameScene::Initialize() {

	// 乱数の初期化
	// 毎回異なるランダム値が生成されるようにする
	srand((unsigned int)time(nullptr));

	Model2::StaticInitialize();

	// カメラの初期化
	camera_.Initialize();

	// ファイル名を指定してテクスチャを読み込む
	//textureHandle_ = TextureManager::Load("uvChecker.png");
	textureHandle_ = TextureManager::Load("white1x1.png");

	// 菱形モデルの生成
	modelDiamond_ = Model2::CreateDiamond();

	// エフェクトを複数生成
	for (uint32_t i = 0; i < kEffectCount; i++) {

		// ワールド変換情報を初期化
		effects_[i].worldTransform.Initialize();

		// 色情報を初期化
		effects_[i].objectColor.Initialize();

		// 最初は完全表示（不透明）
		effects_[i].alpha = 1.0f;

		// 横幅を設定
		effects_[i].worldTransform.scale_.x = 0.2f;

		// 高さをランダムに設定( 5.0 ～ 20.0 の範囲)
		effects_[i].worldTransform.scale_.y = 5.0f + (float)rand() / RAND_MAX * 15.0f;

		// 奥行きを設定
		effects_[i].worldTransform.scale_.z = 1.0f;

		// Z軸回転をランダムに設定(0 ～ 360度)
		effects_[i].worldTransform.rotation_.z = (float)rand() / RAND_MAX * (std::numbers::pi_v<float> * 2.0f);

		// 色を白に設定
		effects_[i].objectColor.SetColor({1.0f, 1.0f, 1.0f, 1.0f});

		// ワールド行列を更新
		effects_[i].worldTransform.UpdateMatrix();
	}
}

// 更新
void GameScene::Update() {
	// 全エフェクトを更新
	for (uint32_t i = 0; i < kEffectCount; i++) {

		// α値を少しずつ減少させる( 徐々に透明になる)
		effects_[i].alpha -= 0.01f;

		// α値が0以下になったらエフェクトをリセット
		if (effects_[i].alpha < 0.0f) {
			effects_[i].alpha = 1.0f;
		}

		// 現在のα値を色に反映
		effects_[i].objectColor.SetColor({1.0f, 1.0f, 1.0f, effects_[i].alpha});

		// ワールド行列を更新
		effects_[i].worldTransform.UpdateMatrix();
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

		modelDiamond_->Draw(effects_[i].worldTransform, // 位置・回転・拡大縮小
			camera_,                    // カメラ
			textureHandle_,             // テクスチャ
			&effects_[i].objectColor    // 色・透明度
		);
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
