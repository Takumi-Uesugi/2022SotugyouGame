#include "DXLibvector2override.h"

int DrawGraph(Vector2* pos, int GrHandle, int TransFlag)
{
	return DrawGraph((int)pos->x, (int)pos->y, GrHandle, TransFlag);
}

int DrawRotaGraph(Vector2* pos, double ExtRate, double Angle, int GrHandle, int TransFlag, int TurnFlag)
{
	return DrawRotaGraph((int)pos->x, (int)pos->y, ExtRate, Angle, GrHandle, TransFlag, TurnFlag);
}