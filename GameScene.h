#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Player.h"
#include "Stage.h"
#include "GraphBar.h"
#include"DrawNumber.h"

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

	/// パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);

private:
	// 3Dモデルデータ--------------------------------------------
	KamataEngine::Model* modelParticle_ = nullptr;//パーティクル
	KamataEngine::Model* modelPlayer_ = nullptr;//プレイヤー

	// 画像読み込み----------------------------------------------
	uint32_t textureHandleStage_ = 0;//背景
	uint32_t textureHandleGraph_ = 0;//グラフ
	uint32_t textureHandleNumber_ = 0;//スコア

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	// 背景
	Stage* stage_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;

	//グラフバー
	GraphBar* graphBar_ = nullptr;
	int hp_ = 200;
	
	//スコア
	DrawNumber* drawNumber_ = nullptr;
	int gameScore_ = 0;

	
};