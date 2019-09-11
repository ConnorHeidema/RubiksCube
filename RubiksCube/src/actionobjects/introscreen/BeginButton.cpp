#include "..\..\..\inc\actionobjects\introscreen\BeginButton.hpp"

void BeginButton::setupMoveButtons(std::list<ActionObject*>& allObjects, RubiksCube* rubiks) {
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

	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 7 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateRightFront));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 8 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateTopFront));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 9 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateFrontFront));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 10 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateRightFrontInverse));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 11 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateTopFrontInverse));
	allObjects.emplace_back(new RubiksMoveButton(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 12 * GameParameters::REGULAR_BUTTON_HEIGHT, rubiks, &RubiksCube::rotateFrontFrontInverse));

	int xAlignment = 50;
	int xAlignment2 = 35;
	int xAlignment3 = 20;
	allObjects.emplace_back(new MoveText(xAlignment + left, top, "Front Move"));
	allObjects.emplace_back(new MoveText(xAlignment + left, top + GameParameters::REGULAR_BUTTON_HEIGHT, "Right Move"));
	allObjects.emplace_back(new MoveText(xAlignment + left, top + 2 * GameParameters::REGULAR_BUTTON_HEIGHT, "Back Move"));
	allObjects.emplace_back(new MoveText(xAlignment + left, top + 3 * GameParameters::REGULAR_BUTTON_HEIGHT, "Left Move"));
	allObjects.emplace_back(new MoveText(xAlignment + left, top + 4 * GameParameters::REGULAR_BUTTON_HEIGHT, "Top Move"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left, top + 5 * GameParameters::REGULAR_BUTTON_HEIGHT, "Bottom Move"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left + GameParameters::REGULAR_BUTTON_WIDTH, top, "Front Inverse"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left + GameParameters::REGULAR_BUTTON_WIDTH, top + GameParameters::REGULAR_BUTTON_HEIGHT, "Right Inverse"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left + GameParameters::REGULAR_BUTTON_WIDTH, top + 2 * GameParameters::REGULAR_BUTTON_HEIGHT, "Back Inverse"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left + GameParameters::REGULAR_BUTTON_WIDTH, top + 3 * GameParameters::REGULAR_BUTTON_HEIGHT, "Left Inverse"));
	allObjects.emplace_back(new MoveText(xAlignment2 + left + GameParameters::REGULAR_BUTTON_WIDTH, top + 4 * GameParameters::REGULAR_BUTTON_HEIGHT, "Top Inverse"));
	allObjects.emplace_back(new MoveText(xAlignment3 + left + GameParameters::REGULAR_BUTTON_WIDTH, top + 5 * GameParameters::REGULAR_BUTTON_HEIGHT, "Bottom Inverse"));

	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 7 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot Right Front"));
	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 8 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot Top Front"));
	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 9 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot Front Front"));
	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 10 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot R. F. Inv"));
	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 11 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot Top Front Inv"));
	allObjects.emplace_back(new MoveText(left + GameParameters::REGULAR_BUTTON_WIDTH / 2, top + 12 * GameParameters::REGULAR_BUTTON_HEIGHT, "Rot F. F. Inv"));

}

void BeginButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	std::for_each(allObjects.begin(), allObjects.end(), [](ActionObject* actionObjectPtr) {
		actionObjectPtr->toBeDeleted = true;
		});
	RubiksCube* rubiks = new RubiksCube();
	Game::setupRubiksObjects(allObjects, rubiks);
	setupMoveButtons(allObjects, rubiks);

	allObjects.emplace_back(new ScrambleButton(rubiks));
	sf::Text* text = new sf::Text();

	int textYAlign = 280;
	int textXAlign = 110;
	text->setString("Scramble Cube");
	text->setCharacterSize(32);
	text->setPosition(GameParameters::SCREEN_WIDTH/2 - textXAlign, GameParameters::SCREEN_HEIGHT/2 + textYAlign);
	allObjects.emplace_back(new ActionText(text));

	std::list<Moves>* moveList = new std::list<Moves>;
	allObjects.emplace_back(new SolveButton(rubiks, moveList));
	int textYAlign2 = 355;
	int textXAlign2 = 110;
	text->setString("Solve Cube");
	text->setCharacterSize(32);
	text->setPosition(GameParameters::SCREEN_WIDTH / 2 - textXAlign2, GameParameters::SCREEN_HEIGHT / 2 + textYAlign2);
	allObjects.emplace_back(new ActionText(text));
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
