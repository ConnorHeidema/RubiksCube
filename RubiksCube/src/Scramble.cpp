#include "..\inc\Scramble.hpp"

Scramble::Scramble() {
	scrambleButton.setFillColor(sf::Color::Magenta);
	scrambleButton.setOutlineThickness(-5);
	scrambleButton.setSize(sf::Vector2f(200, 75));
	scrambleButton.setPosition(sf::Vector2f(1600, 100));
};
void Scramble::drawScrambleButton(sf::RenderWindow& window) {
	window.draw(scrambleButton);
}

void Scramble::scrambleClick(const sf::Vector2i& mousePosition) {
	
}

Scramble::~Scramble() {};

void Scramble::scrambleCube() {
	srand(time(0));
	for (auto i = 0; i < 1000; i++) {
		int move = rand() % 6;
		switch (move) {
		case 0:
			frontMove();
			break;
		case 1:
			rightMove();
			break;
		case 2:
			backMove();
			break;
		case 3:
			leftMove();
			break;
		case 4:
			topMove();
			break;
		case 5:
			bottomMove();
			break;
		}
	}
}
