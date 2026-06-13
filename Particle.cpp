#include "Particle.h"
#include <algorithm>
#include <cassert>

using namespace MathUtility;

// 初期化
void Particle::Initialize(Model* model, Vector3 position) {
	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	worldTransform_.translation_ = position;

	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	// ワールド変換の初期化
	worldTransform_.Initialize();
}

// 更新
void Particle::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// 行列を更新
	worldTransform_.UpdateMatrix();
}

// 描画
void Particle::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}