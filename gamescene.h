#pragma once
//ƒQ[ƒ€‚ÌƒvƒƒOƒ‰ƒ€‚Í‚±‚Á‚¿‚É‘‚­
//KamataEngine‚Å‚â‚Á‚Ä‚é‚±‚Æ‚Æˆê
#include "DxLib.h"
#include "Vector2.h"
#include "input.h"
#include "spinner.h"
#define ENEMY_MAX 256

typedef struct {
	Vector2* pos;
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

	unsigned int timer_ = 0;
	unsigned int sceneNum_ = 0;
	Transform playerTransform_ = { 0 };
	Transform enemyTransform_[ENEMY_MAX] = { 0 };
	Spinner* playerShot_[3] = { 0 };

};