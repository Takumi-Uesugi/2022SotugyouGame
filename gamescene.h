#pragma once
//�Q�[���̃v���O�����͂������ɏ���
//KamataEngine�ł���Ă邱�Ƃƈꏏ
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