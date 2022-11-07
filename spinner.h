#pragma once

#include "DxLib.h"
#include "Vector2.h"

class Spinner
{
public:
	Spinner();
	~Spinner();
	void Create(Vector2 position, Vector2 speed);
	void Destroy();
	void Update();

	int GetUseFlag();
private:
	Vector2* position = nullptr;
	Vector2* speed = nullptr;
	char useflag;
	int life;
};