#include "..\inc\Scramble.hpp"
Scramble::Scramble() {
	scrambleButton.setFillColor(sf::Color::Magenta);
	scrambleButton.setOutlineThickness(-5);
	scrambleButton.setSize(sf::Vector2f(200, 75));
	scrambleButton.setPosition(sf::Vector2f(1600, 100));
};
void Scramble::drawScrambleButton(sf::RenderWindow& window) {
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString("Scramble");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(sf::Vector2f(1610, 110));
	window.draw(scrambleButton);
	window.draw(text);
}

void Scramble::scrambleClick(const sf::Vector2i& mousePosition) {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !scrambleClicked && Util::isWithin(mousePosition, scrambleButton)) {
		scrambleClicked = true;
		scrambleCube();
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		scrambleClicked = false;
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
