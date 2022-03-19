#include "Bakery.h"

Bakery::Bakery()
{
	// initialize j(son) from file
	std::ifstream file("res/building_types.json");
	if (file.is_open())
		file >> j;
	else
		std::cout << "Could not open file for json\n";

	file.close();

	unsigned int size = j.size();

	// determine building amounts from json
	building_amounts = new unsigned int[size];

	// initialize building_amounts to prevent UB
	for (int i = 0; i < size; i++)
	{
		building_amounts[i] = 0u;
	}
}

void Bakery::BakeCookiesOnClick()
{
	total_cookies += cookies_per_click;
}

Bakery::~Bakery()
{
	delete[] building_amounts;
}

void Bakery::BuyBuilding(Building building, int amount)
{
	double cps = j[(int)building]["base_cps"];

	double total_cost = CalculatePrice(building, amount);

	if (total_cookies > total_cost - 0.00001)
	{
		total_cookies -= total_cost;
		total_cps += cps * amount;
		building_amounts[(int)building] += amount;
	}
}

double Bakery::CalculatePrice(Building building, int amount)
{
	double base_cost = j[(int)building]["base_cost"];
	unsigned int current_amount = building_amounts[(int)building];

	if (current_amount == 0 && amount == 1)
		return base_cost;

	return (base_cost * (std::pow(1.15, current_amount + amount) - std::pow(1.15, current_amount))) / 0.15;
}
