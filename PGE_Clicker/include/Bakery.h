#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Building.h"

constexpr unsigned int NUM_BUILDING_TYPES = 2;

using json = nlohmann::json;

class Bakery
{
public:
	json j;

	double total_cookies = 0;
	double total_cps = 0;
	double cookies_per_click = 1;

	unsigned int* building_amounts;

public:
	Bakery();
	~Bakery();

	void BuyBuilding(Building building, int amount);
	double CalculatePrice(Building building, int amount);
	void BakeCookiesOnClick();
};