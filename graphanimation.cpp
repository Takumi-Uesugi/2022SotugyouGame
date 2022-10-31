#include <stdio.h>
#include "graphanimation.h"
#define DATA_MAX 256

D_ANIMATION animationData[DATA_MAX] = { 0 };

int LoadAnimation(const char* Filename, int Width, int Height, int Frames) {
	int GrSizeX = 0, GrSizeY = 0;
	int GrHandle = LoadGraph(Filename);
	if (GrHandle == -1) { return -1; }
	GetGraphSize(GrHandle, &GrSizeX, &GrSizeY);
	int i = 0;
	while (i < DATA_MAX)
	{
		if (animationData[i].UseFlag == 0)
		{
			animationData[i].UseFlag = 1;
			animationData[i].Frames = Frames;
			for (int j = 0; j < Frames; j++)
			{
				animationData[i].Handle[j] = DerivationGraph(Width * (j % (GrSizeX / Width)), Height * (j / (GrSizeX / Width)), Width, Height, GrHandle);
			}
			break;
		}
		i++;
	}
	if (i >= DATA_MAX) { return -1; }
	return i;
}

int DeleteAnimation(int Handle) {
	for (int i = 0; i < animationData[Handle].Frames; i++)
	{
		DeleteGraph(animationData[Handle].Handle[i]);
	}
	animationData[Handle].UseFlag = 0;
	return 0;
}

ANIMATION::ANIMATION() {
	AniHandle = nullptr;
	FrameTime = 0;
	Speed = 0.0f;
	LoopFlag = 0;
}

void ANIMATION::Set(int Handle, float Speed, int LoopFlag) {
	if (animationData[Handle].UseFlag == 1 && Speed > 0)
	{
		AniHandle = &animationData[Handle];
		this->Speed = Speed;
		this->LoopFlag = LoopFlag;
		FrameTime = 0;
	}
}

void ANIMATION::Seek(int FrameTime) {
	if (AniHandle != nullptr && AniHandle->UseFlag == 1 
		&& FrameTime <= (int)((float)AniHandle->Frames * Speed))
	{
		this->FrameTime = FrameTime;
	}
}

void ANIMATION::Play() {
	if (AniHandle != nullptr && AniHandle->UseFlag == 1)
	{
		if (LoopFlag == 1)
		{
			FrameTime = ++FrameTime % (int)((float)AniHandle->Frames * Speed);
		}
		else if (FrameTime < (int)((float)AniHandle->Frames * Speed))
		{
			FrameTime++;
		}
	}
}

void ANIMATION::Draw(int x, int y) {
	if (AniHandle != nullptr && AniHandle->UseFlag == 1)
	{
		DrawGraph(x, y, AniHandle->Handle[(int)((float)FrameTime / Speed)], 1);
	}
}

int ANIMATION::GetFrameTime() {
	return FrameTime;
}

int ANIMATION::GetState() {
	if (AniHandle == nullptr || AniHandle->UseFlag == 0)
	{
		return -1;
	}
	else if (FrameTime >= (int)((float)AniHandle->Frames * Speed) || LoopFlag == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}