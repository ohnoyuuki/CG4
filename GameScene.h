#pragma once

#include "KamataEngine.h"
#include "Particle.h"

// ゲームシーン
class GameScene {
public:
	
	/// デストラクタ
	~GameScene();


	/// 初期化
	void Initialize();


	/// 更新
	void Update();


	/// 描画
	void Draw();

	//パーティクルの発生
	void ParticleBorn();

private:
	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	/// パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);
};