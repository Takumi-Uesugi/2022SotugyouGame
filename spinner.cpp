#include "spinner.h"

Spinner::Spinner()
{
	speed = new Vector2(0, 0);
}

Spinner::~Spinner()
{
	delete speed;
}

void Spinner::Create(Vector2 position, Vector2 speed)
{
	*this->position = position;
	*this->speed = speed;
	useflag = 1;
}

void Spinner::Destroy()
{
	useflag = 0;
}

void Spinner::Update()
{
	if (useflag == 1)
	{
		*position += *speed;
	}
}

int Spinner::GetUseFlag()
{
	return useflag;
}