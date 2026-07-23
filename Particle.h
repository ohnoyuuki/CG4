#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

// パーティクル
class Particle {

public:
	/// 初期化
	void Initialize(Model* model, Vector3 position);

	/// 更新
	void Update();

	/// 描画
	void Draw(KamataEngine::Camera& camera);

	// デスフラグのgetter
	bool IsFinished() { return isFinished_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;

	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間（消滅までの時間）<秒>
	const float kDuration = 1.0f;

	//色変更オブジェクト
	ObjectColor objectColor_;

	//色の数値
	Vector4 color_;

};