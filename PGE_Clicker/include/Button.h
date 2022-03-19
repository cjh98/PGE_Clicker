#pragma once
#include "olcPixelGameEngine.h"
#include "Bakery.h"
#include <string>

class Button
{
public:
	virtual bool Clicked() = 0;
	virtual void OnClick(bool shift, bool ctrl) = 0;
	virtual void Display(bool shift, bool ctrl) = 0;

protected:
	olc::PixelGameEngine* pge;
	Bakery* bakery;
	olc::vi2d position;
	std::string text;

	Button(olc::PixelGameEngine* _pge, Bakery* _bakery, olc::vi2d _position);
};