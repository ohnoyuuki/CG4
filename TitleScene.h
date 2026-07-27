#pragma once
#pragma once
#include "Fade.h"
#include "GameScene.h"
#include "KamataEngine.h"
#include "MyMath.h"

using namespace KamataEngine;
class TitleScene {
public:
	// シーンのフェーズ
	enum class Phase {
		kFadeIn,  // フェードイン
		kMain,    // メイン部
		kFadeOut, // フェードアウト
	};

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~TitleScene();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

private:
	static inline const float kTimeTitleMove = 2.0f;

	// ビュープロジェクション
	Camera camera_;

	// WorldTransform worldTransformTitle_;
	// WorldTransform worldTransformPlayer_;

	// Model* modelPlayer_ = nullptr;
	// Model* modelTitle_ = nullptr;

	float counter_ = 0.0f;

	// 終了フラグ
	bool finished_ = false;

	// フェード
	Fade* fade_ = nullptr;

	// 現在のフェーズ
	Phase phase_ = Phase::kFadeIn;

	// 画像読み込み
	uint32_t textureHandle_ = 0;
	uint32_t titleBarHandle_ = 0;
	uint32_t pushBarHandle_ = 0;

	// スプライト
	Sprite* sprite_ = nullptr;
	Sprite* titleBarSprite_ = nullptr;
	Sprite* pushBarSprite_ = nullptr;

	// タイトルバー
	float titleMove_ = 0.0f;
	// pushバー
	float pushAlpha_ = 1.0f;
	bool pushFade_ = false;

	// 音声ファイル
	// uint32_t soundTitleHandle_ = 0;

	// 音声再生ハンドル
	// int voiceTitleHandle_ = 0;

	// 効果音ハンドル
	// uint32_t soundBotanHandle_ = 0;
};
