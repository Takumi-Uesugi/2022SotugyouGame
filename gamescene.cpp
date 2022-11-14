#include "gamescene.h"

GameScene* GameScene::GetInstance()
{
	static GameScene instance;
}

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete input_;
	delete playerTransform_.pos;
}

void GameScene::Initalize()
{
	input_ = new Input;
	playerTransform_.pos = new Vector2(100.0f, 100.0f);
	playerTransform_.height = 15;
	playerTransform_.width = 15;
}

void GameScene::Update()
{
	input_->Update();

	switch (sceneNum_)
	{
	case SCENE_TITLE:
		if (input_->GetKeyState(KEY_INPUT_RETURN, KEYS_PUSH))
		{
			Reset();
			sceneNum_ = SCENE_GAMEMAIN;
		}
		break;
	case SCENE_GAMEMAIN:

		if (input_->GetKeyState(KEY_INPUT_W, KEYS_TOUCH))
		{
			playerTransform_.pos->x += 1.0f;
		}
		if (input_->GetKeyState(KEY_INPUT_SPACE, KEYS_PUSH))
		{
			for (int i = 0; i < 3; i++)
			{
				if (playerShot_[i]->GetUseFlag() == 0)
				{
					playerShot_[i]->Create(*playerTransform_.pos, Vector2(0.0f, -5.0f));
					break;
				}
			}
		}
		for (int i = 0; i < ENEMY_MAX; i++)
		{

		}
		break;
	default:
		break;
	}

}

void GameScene::Draw()
{
	switch (sceneNum_)
	{
	case SCENE_TITLE:
		DrawFormatString(200, 200, GetColor(255, 255, 255), "Press Enter");
		break;
	case SCENE_GAMEMAIN:
		timer_--;
		if (timer_ <= 0)
		{

		}
		DrawFormatString(10, 10, GetColor(255, 255, 255), "TEST");
		DrawBox(playerTransform_.x, playerTransform_.y, playerTransform_.x + playerTransform_.width, playerTransform_.y + playerTransform_.height, GetColor(255, 255, 255), 1);
		break;
	default:
		break;
	}
}

void GameScene::Reset()
{
	timer_ = 60;
}