#include "..\..\..\inc\actionobjects\introscreen\BeginButton.hpp"

void BeginButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	std::for_each(allObjects.begin(), allObjects.end(), [](ActionObject* actionObjectPtr) {
		actionObjectPtr->toBeDeleted = true;
		});
}

void BeginButton::onHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color(0, 230, 0, 255));
}

void BeginButton::onEndHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color::Green);
}

BeginButton::BeginButton() {
	int yOffset = 300;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Green);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);	
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

ActionRectangleShape* BeginButton::clone() {
	return new BeginButton(*this);
}

BeginButton::BeginButton(const BeginButton& other) : ActionRectangleShape(other) {
}
