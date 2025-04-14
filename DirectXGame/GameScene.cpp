#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {

	textureHandle_ = TextureManager::Load("mario.jpg");

	// 3Dモデルの生成
	model_ = Model::Create();

	delete model_;

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// カメラの初期化
	camera_.Initialize();
}

void GameScene::Update() {}

void GameScene::Draw() {

	// irectXCommonのインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera_, textureHandle_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
