#include "input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::Update()
{
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; i++)
	{
		oldkeys[i] = keys[i];
	}
	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

int Input::GetKeyState(int keyCode, int inputType)
{
	switch (inputType)
	{
	case KEYS_TOUCH:
		if (keys[keyCode] != 0) { return 1; }
		else { return 0; }
		break;
	case KEYS_PUSH:
		if (keys[keyCode] != 0 && oldkeys[keyCode] == 0) { return 1; }
		else { return 0; }
		break;
	case KEYS_HOLD:
		if (keys[keyCode] != 0 && oldkeys[keyCode] != 0) { return 1; }
		else { return 0; }
		break;
	case KEYS_RELS:
		if (keys[keyCode] == 0 && oldkeys[keyCode] != 0) { return 1; }
		else { return 0; }
		break;
	default:
		break;
	}
}