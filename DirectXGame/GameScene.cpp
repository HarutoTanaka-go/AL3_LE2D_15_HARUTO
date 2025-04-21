#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete model_;
	delete player_;
}

void GameScene::Initialize() {

	textureHandle_ = TextureManager::Load("pikurusuMen.png");

	// 3Dモデルの生成
	model_ = Model::Create();

	// delete model_;

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// カメラの初期化
	camera_.Initialize();

	// 自キャラ生成
	player_ = new Player();

	// 自キャラの初期化
	player_->Initialize(model_, textureHandle_,&camera_);
}

void GameScene::Update() {

	// 自キャラの更新
	player_->Update();
}

void GameScene::Draw() {

	// DirectXCommonのインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera_, textureHandle_);

	// 自キャラの更新
	player_->Draw();

	// 3Dモデル描画後処理
	Model::PostDraw();
}
