#pragma once
#include "SFML\Graphics.hpp"
#include <algorithm>

namespace ranges {
	template<typename Range, typename Function>
	Function for_each(Range& range, Function f) {
		return std::for_each(begin(range), end(range), f);
	}
}

class Util {
public:
	static bool isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle);
};
