#include "..\..\..\inc\actionobjects\introscreen\Title.hpp"

void Title::onTimePassing(std::list<ActionObject*>& allObjects) {
	if (timer.getElapsedTime() > sf::milliseconds(1600)) {
		std::cout << "here" << std::endl;
		timer.restart();
		srand(time(0));
		for (int i = 0; i < 1; i++) {
			int r = (rand() % 12);
			switch (r) {
			case 0: rubiks->frontMove(); break;
			case 1: rubiks->leftMove(); break;
			case 2: rubiks->backMove(); break;
			case 3: rubiks->rightMove(); break;
			case 4: rubiks->topMove(); break;
			case 5: rubiks->bottomMove(); break;
			case 6: rubiks->frontInverseMove(); break;
			case 7: rubiks->leftInverseMove(); break;
			case 8: rubiks->backInverseMove(); break;
			case 9: rubiks->rightInverseMove(); break;
			case 10: rubiks->topInverseMove(); break;
			case 11: rubiks->bottomInverseMove(); break;
			}
		}
		Solve solve;
		std::list<Moves> moves = solve.solveCube(rubiks);
		solve.condenseSolvedList(moves);
	}
}

void Title::onRemove(std::list<ActionObject*>& allObjects) {
	delete rubiks;
}

Title::~Title() {
}

Title::Title(RubiksCube* rubiks) {
	timer.restart();
	this->rubiks = rubiks;
	int yOffset = -450;
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString("Rubiks Cube Simulator");
	text->setFillColor(sf::Color::White);
	text->setCharacterSize(64);
	text->setFont(*font);
	text->setPosition((GameParameters::SCREEN_WIDTH - text->getGlobalBounds().width) / 2, (GameParameters::SCREEN_HEIGHT - text->getGlobalBounds().height) / 2 + yOffset);
	textPtr = text;
}

Title* Title::clone() {
	return new Title(*this);
}

Title::Title(const Title& other) : ActionText(other) {
	rubiks = other.rubiks;
	timer = other.timer;
}
