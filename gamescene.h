#pragma once
//ゲームのプログラムはこっちに書く
//KamataEngineでやってることと一緒
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

class GameScene final
{
public:
	GameScene(const GameScene& obj) = delete;
	GameScene& operator=(const GameScene& obj) = delete;

	static GameScene* GetInstance();

	void Initalize();
	void Update();
	void Draw();

private:
	GameScene();
	~GameScene();
	void Reset();
	Input* input_ = nullptr;

	unsigned int timer_ = 0;
	unsigned int sceneNum_ = 0;
	Transform playerTransform_ = { 0 };
	Transform enemyTransform_[ENEMY_MAX] = { 0 };
	Spinner* playerShot_[3] = { 0 };

};