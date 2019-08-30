#include "..\inc\Scramble.hpp"
Scramble::Scramble() {
	scrambleButton.setFillColor(sf::Color::Magenta);
	scrambleButton.setOutlineThickness(-5);
	scrambleButton.setSize(sf::Vector2f(200, 75));
	scrambleButton.setPosition(sf::Vector2f(1600, 100));
	font.loadFromFile("font/OpenSans-Regular.ttf");
	text.setFont(font);
	text.setString("Scramble");
	text.setCharacterSize(75); 
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(sf::Vector2f(1400, 100));
};
void Scramble::drawScrambleButton(sf::RenderWindow& window) {
	window.draw(scrambleButton);
	window.draw(text);
}

void Scramble::scrambleClick(const sf::Vector2i& mousePosition) {
	if (Util::isWithin(mousePosition, scrambleButton)) {
		scrambleCube();
	}
}

Scramble::~Scramble() {};

void Scramble::scrambleCube() {
	const int randomMoves = 1000;
	srand(time(0));
	for (auto i = 0; i < randomMoves; i++) {
		int move = rand() % NUM_FACES;
		switch (move) {
		case FRONT_FACE:
			frontMove();
			break;
		case RIGHT_FACE:
			rightMove();
			break;
		case BACK_FACE:
			backMove();
			break;
		case LEFT_FACE:
			leftMove();
			break;
		case TOP_FACE:
			topMove();
			break;
		case BOTTOM_FACE:
			bottomMove();
			break;
		}
	}
}
