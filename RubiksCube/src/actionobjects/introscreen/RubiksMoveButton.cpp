#include "..\..\..\inc\actionobjects\introscreen\RubiksMoveButton.hpp"

void RubiksMoveButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	(*rubiksPtr.*fnPtr)();
}

RubiksMoveButton::RubiksMoveButton() {
	int yOffset = 300;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Green);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

RubiksMoveButton* RubiksMoveButton::clone() {
	return new RubiksMoveButton(*this);
}

RubiksMoveButton::RubiksMoveButton(const RubiksMoveButton& other) : ActionRectangleShape(other) {
	rectShapePtr->setPosition(other.rectShapePtr->getPosition());
	rubiksPtr = other.rubiksPtr;
	fnPtr = other.fnPtr;
}

RubiksMoveButton::RubiksMoveButton(int xPos, int yPos, RubiksCube* rubiks, void(RubiksCube::* fnPtr)()) {
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Green);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition(xPos, yPos);
	rubiksPtr = rubiks;
	rectShapePtr = rect;
	this->fnPtr = fnPtr;
}
