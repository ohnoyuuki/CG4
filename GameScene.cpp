#include "GameScene.h"
// 初期化
void GameScene::Initialize() { 
	Model2::StaticFinalize();

}
// 更新
void GameScene::Update() {}
// 描画
void GameScene::Draw() {}
// デストラクタ
GameScene::~GameScene() { 
	Model2::StaticFinalize();
}
