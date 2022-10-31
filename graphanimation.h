#pragma once
//画像ファイルからアニメーションを生成して使えるようにするプログラム
//LoadAnimation関数で画像をアニメーションとして読み込みハンドルを返す(LoadGraph関数と一緒)
//プログラム上で実際に使うときはANIMATIONクラスを生成してSet関数で読み込み
#include "DxLib.h"

typedef struct {
	int UseFlag;
	int Frames;
	int Handle[64];
} D_ANIMATION;

//画像をアニメーションとして読み込む(メモリ確保)
//1コマあたりの幅と高さ、コマ数を指定する
int LoadAnimation(const char* Filename, int Width, int Height, int Frames);
//画像の削除(メモリ解放)
int DeleteAnimation(int Handle);

class ANIMATION {
public:
	//コンストラクタ
	ANIMATION();
	//クラスへのアニメーション読み込み、および速度とループフラグのセット
	void Set(int Handle, float Speed = 1.0F, int LoopFlag = 0);
	//アニメーションのシーク
	void Seek(int FrameTime);
	//アニメーションのコマを送る　基本的に毎フレーム呼ぶ
	void Play();
	//アニメーションの描画
	void Draw(int x, int y);
	//アニメーションの再生位置を返す
	int GetFrameTime();
	//アニメーションの再生状態を返す
	//アニメーションが読み込まれていない時は-1、再生中は0、再生終了時は1
	int GetState();
private:
	D_ANIMATION* AniHandle;
	int FrameTime;
	float Speed;
	char LoopFlag;
};