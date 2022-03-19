#define OLC_PGE_APPLICATION
#include <string>
#include "olcPixelGameEngine.h"
#include "Bakery.h"
#include "Building.h"
#include "Button.h"
#include "CircleButton.h"
#include "RectButton.h"

class Clicker : public olc::PixelGameEngine
{
public:
	Bakery bakery;

	olc::vi2d screen_center = olc::vf2d(320, 180);

	//-----------------------------------------
	//	Building
	//	Buttons
	//-----------------------------------------
	olc::vi2d rect_dimensions = olc::vi2d(192, 36);
	std::vector<RectButton> rect_buttons;
	RectButton cursor_button =		RectButton(Building::Cursor,		this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 1)),		rect_dimensions);
	RectButton grandma_button =		RectButton(Building::Grandma,		this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 2)),		rect_dimensions);
	RectButton farm_button =		RectButton(Building::Farm,			this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 3)),		rect_dimensions);
	RectButton mine_button =		RectButton(Building::Mine,			this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 4)),		rect_dimensions);
	RectButton factory_button =		RectButton(Building::Factory,		this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 5)),		rect_dimensions);
	RectButton bank_button =		RectButton(Building::Bank,			this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 6)),		rect_dimensions);
	RectButton temple_button =		RectButton(Building::Temple,		this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 7)),		rect_dimensions);
	RectButton wizard_button =		RectButton(Building::WizardTower,	this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 8)),		rect_dimensions);
	RectButton shipment_button =	RectButton(Building::Shipment,		this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 9)),		rect_dimensions);
	RectButton alchemy_button =		RectButton(Building::AlchemyLab,	this, &bakery, olc::vi2d(0, 360 - (rect_dimensions.y * 10)),	rect_dimensions);

	//-----------------------------------------
	//	Center
	//	Button
	//-----------------------------------------
	int cookie_size = 32;
	olc::vi2d big_cookie_pos = olc::vi2d(screen_center.x + rect_dimensions.x / 2, screen_center.y);
	CircleButton big_cookie = CircleButton(this, &bakery, big_cookie_pos, cookie_size);


	Clicker()
	{
		sAppName = "Clicker";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		SetPixelMode(olc::Pixel::MASK);

		// Push buttons to buttons vector
		rect_buttons.push_back(cursor_button);
		rect_buttons.push_back(grandma_button);
		rect_buttons.push_back(farm_button);
		rect_buttons.push_back(mine_button);
		rect_buttons.push_back(factory_button);
		rect_buttons.push_back(bank_button);
		rect_buttons.push_back(temple_button);
		rect_buttons.push_back(wizard_button);
		rect_buttons.push_back(shipment_button);
		rect_buttons.push_back(alchemy_button);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::VERY_DARK_BLUE);

		if (bakery.total_cps > 0.0)
			bakery.total_cookies += bakery.total_cps * fElapsedTime;

		DrawString(big_cookie_pos + olc::vi2d(-36, -64), "PLACEHOLDER: " + std::to_string(static_cast<uint64_t>(bakery.total_cookies)));
		DrawString(big_cookie_pos + olc::vi2d(-72, 64), "Per second: " + std::to_string(bakery.total_cps));

		ManageButtons();

		return true;
	}

	void ManageButtons()
	{
		bool shift = GetKey(olc::SHIFT).bHeld;
		bool ctrl = GetKey(olc::CTRL).bHeld;

		big_cookie.Display(shift, ctrl);
		if (big_cookie.Clicked())
			big_cookie.OnClick(shift, ctrl);

		for (auto &button : rect_buttons)
		{
			button.Display(shift, ctrl);
			if (button.Clicked())
				button.OnClick(shift, ctrl);
		}
	}
};

int main()
{
	Clicker demo;
	if (demo.Construct(640, 360, 2, 2, false, true, false))
		demo.Start();

	return 0;
}