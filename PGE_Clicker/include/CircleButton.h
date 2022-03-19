#pragma once
#include "Button.h"

class CircleButton : public Button
{
public:
	CircleButton(olc::PixelGameEngine* _pge, Bakery* _bakery, olc::vi2d _position, int _radius);

	bool Clicked() override;
	void OnClick(bool shift, bool ctrl) override;
	void Display(bool shift, bool ctrl) override;
private:
	int radius;
};