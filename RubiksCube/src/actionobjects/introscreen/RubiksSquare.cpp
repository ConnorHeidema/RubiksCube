#include "..\..\..\inc\actionobjects\introscreen\RubiksSquare.hpp"

RubiksSquare::RubiksSquare(int xPos, int yPos, sf::Color& color) {
	colorPtr = &color;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(50,50));
	rect->setFillColor(*colorPtr);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition(xPos, yPos);
	rectShapePtr = rect;
}

RubiksSquare::RubiksSquare() : colorPtr(nullptr) {
}

RubiksSquare* RubiksSquare::clone() {
	return new RubiksSquare(*this);
}

RubiksSquare::RubiksSquare(const RubiksSquare& other) : ActionRectangleShape(other) {
	colorPtr = other.colorPtr;
	rectShapePtr->setFillColor(*colorPtr);
}
