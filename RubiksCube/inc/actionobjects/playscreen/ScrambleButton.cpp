#include "ScrambleButton.hpp"

void ScrambleButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	const int MOVES_TO_MAKE = 1000;
	srand(time(0));
	for (int movesMade = 0; movesMade < MOVES_TO_MAKE; movesMade++) {
		rubiksPtr->performFunction(static_cast<Moves>(rand() % NUM_MOVES));
	}
}

void ScrambleButton::onHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color::Magenta);
}

void ScrambleButton::onEndHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color::Blue);
}

ScrambleButton::ScrambleButton() : rubiksPtr(nullptr) {
	int yOffset = 300;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Blue);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

ScrambleButton::ScrambleButton(RubiksCube* rubiks) : rubiksPtr(rubiks) {
	int yOffset = 300;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Blue);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}


ActionRectangleShape* ScrambleButton::clone() {
	return new ScrambleButton(*this);
}

ScrambleButton::ScrambleButton(const ScrambleButton& other) : ActionRectangleShape(other) {
	rubiksPtr = other.rubiksPtr;
}
