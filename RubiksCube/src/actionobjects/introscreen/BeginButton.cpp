#include "..\..\..\inc\actionobjects\introscreen\BeginButton.hpp"

void BeginButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	std::for_each(allObjects.begin(), allObjects.end(), [](ActionObject* actionObjectPtr) {
		actionObjectPtr->toBeDeleted = true;
		});
	RubiksCube* rubiks = new RubiksCube();
	Game::setupRubiksObjects(allObjects, rubiks);
	int left = 100;
	int top = 100;
	allObjects.emplace_back(new RubiksMoveButton(left, top, rubiks, &RubiksCube::frontMove));
	allObjects.emplace_back(new RubiksMoveButton(left, top + GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rightMove));
	allObjects.emplace_back(new RubiksMoveButton(left, top + 2 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::backMove));
	allObjects.emplace_back(new RubiksMoveButton(left, top + 3 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::leftMove));
	allObjects.emplace_back(new RubiksMoveButton(left, top + 4 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::topMove));
	allObjects.emplace_back(new RubiksMoveButton(left, top + 5 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::bottomMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top, rubiks, &RubiksCube::frontInverseMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top + GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rightInverseMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top + 2 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::backInverseMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top + 3 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::leftInverseMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top + 4 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::topInverseMove));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH, top + 5 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::bottomInverseMove));
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
