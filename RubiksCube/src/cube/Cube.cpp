#include "..\..\inc\cube\Cube.hpp"

Cube::Cube() {
	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			cube[face][position] = static_cast<Color>(face);
		}
	}
	colorMapping.emplace(WHITE, sf::Color::White);
	colorMapping.emplace(RED, sf::Color::Red);
	colorMapping.emplace(YELLOW, sf::Color::Yellow);
	colorMapping.emplace(ORANGE, sf::Color(255, 128, 64, 255));
	colorMapping.emplace(BLUE, sf::Color::Blue);
	colorMapping.emplace(GREEN, sf::Color::Green);
}

Cube::~Cube() {};