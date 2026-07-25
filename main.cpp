#include "GameScene.h"
#include "KamataEngine.h"
#include "TitleScene.h"
#include <Windows.h>

using namespace KamataEngine;

// シーンのインスタンス
TitleScene* titleScene = nullptr;
GameScene* gameScene = nullptr;

// シーンの種類
enum class Scene {
	kUnknown = 0,
	kTitle, // タイトル
	kGame,  // ゲーム本編
};

// 現在のシーンを示す変数
Scene scene = Scene::kUnknown;

// シーン切り替え処理
void ChangeScene() {
	switch (scene) {
		// タイトルシーン
	case Scene::kTitle:
		// タイトルシーンが終了状態なら
		if (titleScene->IsFinished()) {
			// ゲームシーンへ切り替え
			scene = Scene::kGame;

			// 古いシーン削除
			delete titleScene;
			titleScene = nullptr;

			// 新しいゲームシーン作成＆初期化
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;

		// ゲームシーン
	case Scene::kGame:
		// 今回はゲームシーンから先の遷移はなし

		break;
	}
}

// シーンの更新処理
void UpdateScene() {
	switch (scene) {

	case Scene::kTitle:
		titleScene->Update();
		break;

	case Scene::kGame:
		gameScene->Update();
		break;
	}
}

// シーンの描画処理
void DrawScene() {

	switch (scene) {

	case Scene::kTitle:
		titleScene->Draw();
		break;

	case Scene::kGame:
		gameScene->Draw();
		break;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_07_オオノ_ユウキ");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 最初はタイトル
	scene = Scene::kTitle;

	titleScene = new TitleScene();
	titleScene->Initialize();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {

			break;
		}

		// シーン更新
		UpdateScene();

		// シーン切り替え
		ChangeScene();

		// 描画開始
		dxCommon->PreDraw();

		// シーン描画
		DrawScene();

		// 描画終了
		dxCommon->PostDraw();
	}

	// 解放
	delete titleScene;
	delete gameScene;

	// nullptrの代入
	gameScene = nullptr;
	titleScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}