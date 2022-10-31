#pragma once
//�摜�t�@�C������A�j���[�V�����𐶐����Ďg����悤�ɂ���v���O����
//LoadAnimation�֐��ŉ摜���A�j���[�V�����Ƃ��ēǂݍ��݃n���h����Ԃ�(LoadGraph�֐��ƈꏏ)
//�v���O������Ŏ��ۂɎg���Ƃ���ANIMATION�N���X�𐶐�����Set�֐��œǂݍ���
#include "DxLib.h"

typedef struct {
	int UseFlag;
	int Frames;
	int Handle[64];
} D_ANIMATION;

//�摜���A�j���[�V�����Ƃ��ēǂݍ���(�������m��)
//1�R�}������̕��ƍ����A�R�}�����w�肷��
int LoadAnimation(const char* Filename, int Width, int Height, int Frames);
//�摜�̍폜(���������)
int DeleteAnimation(int Handle);

class ANIMATION {
public:
	//�R���X�g���N�^
	ANIMATION();
	//�N���X�ւ̃A�j���[�V�����ǂݍ��݁A����ё��x�ƃ��[�v�t���O�̃Z�b�g
	void Set(int Handle, float Speed = 1.0F, int LoopFlag = 0);
	//�A�j���[�V�����̃V�[�N
	void Seek(int FrameTime);
	//�A�j���[�V�����̃R�}�𑗂�@��{�I�ɖ��t���[���Ă�
	void Play();
	//�A�j���[�V�����̕`��
	void Draw(int x, int y);
	//�A�j���[�V�����̍Đ��ʒu��Ԃ�
	int GetFrameTime();
	//�A�j���[�V�����̍Đ���Ԃ�Ԃ�
	//�A�j���[�V�������ǂݍ��܂�Ă��Ȃ�����-1�A�Đ�����0�A�Đ��I������1
	int GetState();
private:
	D_ANIMATION* AniHandle;
	int FrameTime;
	float Speed;
	char LoopFlag;
};