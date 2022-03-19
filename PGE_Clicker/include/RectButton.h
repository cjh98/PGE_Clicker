#pragma once
#pragma once
#include "Button.h"

class RectButton : public Button
{
public:
	RectButton(Building _building, olc::PixelGameEngine* _pge, Bakery* _bakery, olc::vi2d _position, olc::vi2d _dimensions);

	bool Clicked() override;
	void OnClick(bool shift, bool ctrl) override;
	void Display(bool shift, bool ctrl) override;
private:
	olc::vi2d dimensions;
	Building building;
};