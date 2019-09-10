#include "../../../inc/actionobjects/introscreen/InstructionsButton.hpp"

void InstructionsButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	std::cout << "Begin button clicked" << std::endl;
}

InstructionsButton::InstructionsButton() {
	int yOffset = 375;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Yellow);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

ActionRectangleShape* InstructionsButton::clone() {
	return new InstructionsButton(*this);
}

InstructionsButton::InstructionsButton(const InstructionsButton& other) : ActionRectangleShape(other) {
}
