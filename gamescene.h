#pragma once
//ƒQ[ƒ€‚ÌƒvƒƒOƒ‰ƒ€‚Í‚±‚Á‚¿‚É‘‚­
//KamataEngine‚Å‚â‚Á‚Ä‚é‚±‚Æ‚Æˆê
#include "DxLib.h"
#include "input.h"

typedef struct {
	int x, y;
	int width, height;
}Transform;

enum SceneName
{
	SCENE_TITLE,
	SCENE_GAMEMAIN,
	SCENE_GAMEOVER,
};

class GameScene
{
public:
	GameScene();
	~GameScene();
	void Initalize();
	void Update();
	void Draw();

private:
	void Reset();
	Input* input_ = nullptr;
	const int ENEMY_MAX = 256;

	unsigned int timer_ = 0;
	unsigned int sceneNum_ = 0;
	Transform playerTransform_ = { 0 };
	Transform enemyTransform_[256] = {0};

};