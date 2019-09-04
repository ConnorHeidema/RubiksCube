#pragma once
#include "SFML\Graphics.hpp"
#include <algorithm>
#include <iostream>

class Util {
public:
	static bool isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle);
};
