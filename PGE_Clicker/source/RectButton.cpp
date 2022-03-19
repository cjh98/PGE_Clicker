#include "RectButton.h"

RectButton::RectButton(Building _building, olc::PixelGameEngine* _pge, Bakery* _bakery, olc::vi2d _position, olc::vi2d _dimensions)
	: Button(_pge, _bakery, _position), building(_building), dimensions(_dimensions)
{
	text = bakery->j[(int)building]["name"];
}

bool RectButton::Clicked()
{
	int mouseX = pge->GetMouseX();
	int mouseY = pge->GetMouseY();

	return pge->GetMouse(0).bPressed && mouseX >= position.x && mouseX <= position.x + dimensions.x
		&& mouseY >= position.y && mouseY <= position.y + dimensions.y;
}

void RectButton::OnClick(bool shift, bool ctrl)
{
	if (shift)
		bakery->BuyBuilding(building, 10);
	else if (ctrl)
		bakery->BuyBuilding(building, 100);
	else
		bakery->BuyBuilding(building, 1);
}

void RectButton::Display(bool shift, bool ctrl)
{
	pge->DrawRect(position, dimensions);
	pge->FillRect(position, dimensions, olc::VERY_DARK_GREY);
	pge->DrawString(position + olc::vi2d(2, 2), text);
	pge->DrawString(position + olc::vi2d(2, 15), std::string("Amount: ") + std::to_string(bakery->building_amounts[(int)building]));

	// MAKE THIS NOT BE CALCULATED EVERY FRAME
	if (shift)
	{
		double cost = bakery->CalculatePrice(building, 10);
		pge->DrawString(position + olc::vi2d(2, 28), std::string("Cost: ") + std::to_string(cost));
	}
	else if (ctrl)
	{
		double cost = bakery->CalculatePrice(building, 100);
		pge->DrawString(position + olc::vi2d(2, 28), std::string("Cost: ") + std::to_string(cost));
	}
	else
	{
		double cost = bakery->CalculatePrice(building, 1);
		pge->DrawString(position + olc::vi2d(2, 28), std::string("Cost: ") + std::to_string(cost));
	}
}
