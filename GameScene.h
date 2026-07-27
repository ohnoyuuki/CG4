#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include"Stage.h"

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


	// 背景
	Stage* stage_ = nullptr;

	/// パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);

	// 画像読み込み
	uint32_t textureHandleStage_ = 0;
	

};