#pragma once
//各種入力を管理するクラス
#include "DxLib.h"

//GetKeyStateに使うinputTypeの一覧
enum KeyInputType
{
	KEYS_TOUCH,//触れている時
	KEYS_PUSH,//押した瞬間
	KEYS_HOLD,//押している間
	KEYS_RELS,//放した瞬間
};

class Input
{
public:
	Input();
	~Input();
	void Update();
	int GetKeyState(int keyCode, int inputType);

private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };
	

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	int mouseX, mouseY;

};
