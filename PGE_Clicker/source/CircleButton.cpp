#include "CircleButton.h"

CircleButton::CircleButton(olc::PixelGameEngine* _pge, Bakery* _bakery, olc::vi2d _position, int _radius)
	:	Button(_pge, _bakery, _position), radius(_radius)
{}

bool CircleButton::Clicked()
{
	return pge->GetMouse(0).bPressed && (std::abs((pge->GetMousePos() - position).mag())) <= radius;
}

void CircleButton::OnClick(bool shift, bool ctrl)
{
	bakery->BakeCookiesOnClick();
}

void CircleButton::Display(bool shift, bool ctrl) 
{
	pge->FillCircle(position, radius, olc::DARK_RED);
}