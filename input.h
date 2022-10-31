#pragma once
//�e����͂��Ǘ�����N���X
#include "DxLib.h"

//GetKeyState�Ɏg��inputType�̈ꗗ
enum KeyInputType
{
	KEYS_TOUCH,//�G��Ă��鎞
	KEYS_PUSH,//�������u��
	KEYS_HOLD,//�����Ă����
	KEYS_RELS,//�������u��
};

class Input
{
public:
	Input();
	~Input();
	void Update();
	int GetKeyState(int keyCode, int inputType);

private:
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };
	

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	int mouseX, mouseY;

};
