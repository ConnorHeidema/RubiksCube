#include "..\..\..\inc\actionobjects\introscreen\TitleShape.hpp"

TitleShape::TitleShape() {
	int yOffset = -435;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH*3, GameParameters::REGULAR_BUTTON_HEIGHT*2));
	rect->setFillColor(sf::Color::Black);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

ActionRectangleShape* TitleShape::clone() {
	return new TitleShape(*this);
}

TitleShape::TitleShape(const TitleShape& other) : ActionRectangleShape(other) {
}
