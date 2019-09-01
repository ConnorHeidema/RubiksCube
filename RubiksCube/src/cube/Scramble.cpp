#include "..\..\inc\cube\Scramble.hpp"

Scramble::ScrambleButton::ScrambleButton(Scramble* scramble, int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) : 
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText){
	outerReference = scramble;
}

Scramble::Scramble() {
	scrambleButtonPtr = 
		new ScrambleButton(this, 1610, 110, 200, 75, -5, sf::Color::Magenta, sf::Color::Green, sf::Text(), sf::Font(), "Scramble");
	buttons.push_back(scrambleButtonPtr);
}

Scramble::~Scramble() {
	delete scrambleButtonPtr;
};

void Scramble::scrambleCube() {
	srand(time(0));
	const int randomMoves = rand() % 1000 + 200;
	for (auto i = 0; i < randomMoves; i++) {
		int move = rand() % (NUM_FACES + NUM_ROTATIONS);
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
		case NUM_FACES + RIGHT_FRONT:
			rotateRightFront();
			break;
		case NUM_FACES + TOP_FRONT:
			rotateTopFront();
			break;
		case NUM_FACES + FRONT_FRONT:
			rotateFrontFront();
			break;
		}
	}
}

void Scramble::ScrambleButton::leftButtonClicked() {
	outerReference->scrambleCube();
}

void Scramble::ScrambleButton::rightButtonClicked() {
}
