#include "..\..\inc\cube\InteractableCube.hpp"

void InteractableCube::rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
	const Cube::Face& secondFace, const Cube::Position secondPosition,
	const Cube::Face& thirdFace, const Cube::Position thirdPosition,
	const Cube::Face& fourthFace, const Cube::Position fourthPosition) {
	Color tempSquare = cube[fourthFace][fourthPosition];
	cube[fourthFace][fourthPosition] = cube[thirdFace][thirdPosition];
	cube[thirdFace][thirdPosition] = cube[secondFace][secondPosition];
	cube[secondFace][secondPosition] = cube[firstFace][firstPosition];
	cube[firstFace][firstPosition] = tempSquare;
}

void InteractableCube::inverseRotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
	const Cube::Face& secondFace, const Cube::Position secondPosition,
	const Cube::Face& thirdFace, const Cube::Position thirdPosition,
	const Cube::Face& fourthFace, const Cube::Position fourthPosition) {
	rotate4Squares(firstFace, firstPosition, 
		secondFace, secondPosition, 
		thirdFace, thirdPosition, 
		fourthFace, fourthPosition);
	rotate4Squares(firstFace, firstPosition,
		secondFace, secondPosition,
		thirdFace, thirdPosition,
		fourthFace, fourthPosition);
	rotate4Squares(firstFace, firstPosition,
		secondFace, secondPosition,
		thirdFace, thirdPosition,
		fourthFace, fourthPosition);
}

void InteractableCube::rotateFace(const Cube::Face& face) {
	Color tempSquares[2] = { cube[face][NUM_POSITIONS - 3], cube[face][NUM_POSITIONS - 2] };
	for (auto index = NUM_POSITIONS - 2; index >= 0; index--) {
		if (index < 2) {
			cube[face][index] = tempSquares[index];
		} else {
			cube[face][index] = cube[face][index - 2];
		}
	}
}

void InteractableCube::inverseRotateFace(const Cube::Face& face) {
	rotateFace(face);
	rotateFace(face);
	rotateFace(face);
}

const sf::Color InteractableCube::InteractableCubeButton::NORMAL_COLOUR = sf::Color(86, 170, 242, 255);
const sf::Color InteractableCube::InteractableCubeButton::REVERSE_COLOUR = sf::Color(185, 86, 242, 255);
const sf::Color InteractableCube::InteractableCubeButton::BUTTON_OUTLINE_COLOUR = sf::Color(32, 32, 32, 255);
const int InteractableCube::InteractableCubeButton::BUTTON_OUTLINE_THICKNESS = -3;

InteractableCube::InteractableCube() {
	movementButtons[InteractableCubeButton::NORMAL][FRONT_FACE] = new InteractableCubeButton(this, &InteractableCube::frontMove, "Move Front",75,250,250,50,-5);
	movementButtons[InteractableCubeButton::NORMAL][RIGHT_FACE] = new InteractableCubeButton(this, &InteractableCube::rightMove,"Move Right", 75, 300, 250, 50);
	movementButtons[InteractableCubeButton::NORMAL][LEFT_FACE] = new InteractableCubeButton(this, &InteractableCube::backMove, "Move Back", 75, 350, 250, 50);
	movementButtons[InteractableCubeButton::NORMAL][BACK_FACE] = new InteractableCubeButton(this, &InteractableCube::leftMove, "Move Left", 75, 400, 250, 50);
	movementButtons[InteractableCubeButton::NORMAL][TOP_FACE] = new InteractableCubeButton(this, &InteractableCube::topMove, "Move Top", 75, 450, 250, 50);
	movementButtons[InteractableCubeButton::NORMAL][BOTTOM_FACE] = new InteractableCubeButton(this, &InteractableCube::bottomMove, "Move Bottom", 75, 500, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][FRONT_FACE] = new InteractableCubeButton(this, &InteractableCube::frontInverseMove, "Move Front Inv", 325, 250, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][RIGHT_FACE] = new InteractableCubeButton(this, &InteractableCube::rightInverseMove, "Move Right Inv", 325, 300, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][LEFT_FACE] = new InteractableCubeButton(this, &InteractableCube::backInverseMove, "Move Back Inv", 325, 350, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][BACK_FACE] = new InteractableCubeButton(this, &InteractableCube::leftInverseMove, "Move Left Inv", 325, 400, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][TOP_FACE] = new InteractableCubeButton(this, &InteractableCube::topInverseMove, "Move Top Inv", 325, 450, 250, 50);
	movementButtons[InteractableCubeButton::INVERSE][BOTTOM_FACE] = new InteractableCubeButton(this, &InteractableCube::bottomInverseMove, "Move Bottom Inv", 325, 500, 250, 50);
	rotateButtons[RIGHT_FRONT] = new InteractableCubeButton(this, &InteractableCube::rotateRightFront, "Rotate Right Front", 200, 600, 250, 50);
	rotateButtons[TOP_FRONT] = new InteractableCubeButton(this, &InteractableCube::rotateTopFront, "Rotate Top Front", 200, 650, 250, 50);
	rotateButtons[FRONT_FRONT] = new InteractableCubeButton(this, &InteractableCube::rotateFrontFront, "Rotate Front Front", 200, 700, 250, 50);
	for (int face = FRONT_FACE; face < NUM_FACES; face++) {
		buttons.push_back(movementButtons[InteractableCubeButton::NORMAL][face]);
		buttons.push_back(movementButtons[InteractableCubeButton::INVERSE][face]);
	}
	for (int rotation = RIGHT_FRONT; rotation < NUM_ROTATIONS; rotation++) {
		buttons.push_back(rotateButtons[rotation]);
	}
};

InteractableCube::~InteractableCube() {
	delete[] movementButtons;
	delete[] rotateButtons;
};

InteractableCube::InteractableCubeButton::InteractableCubeButton(InteractableCube* interactableCube, 
	void (InteractableCube::* function)(), int xPosition, int yPosition,
	int xSize, int ySize, int thickness, sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = interactableCube;
	this->moveFnPtr = function;
}

InteractableCube::InteractableCubeButton::InteractableCubeButton(InteractableCube* interactableCube, 
	void(InteractableCube::* function)(), std::string buttonText, int xPosition, int yPosition, int xSize, int ySize, 
	int thickness, sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = interactableCube;
	this->moveFnPtr = function;
}

void InteractableCube::InteractableCubeButton::leftButtonClicked() {
	((*outerReference).*moveFnPtr)();
}

void InteractableCube::InteractableCubeButton::rightButtonClicked() {
}

void InteractableCube::frontMove() {
	rotate4Squares(TOP_FACE, BOTTOM_LEFT, RIGHT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM, RIGHT_FACE, LEFT, BOTTOM_FACE, TOP, LEFT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_LEFT, LEFT_FACE, TOP_RIGHT);
	rotateFace(FRONT_FACE);
}

void InteractableCube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(RIGHT_FACE);
}

void InteractableCube::backMove() {
	rotate4Squares(TOP_FACE, TOP_LEFT, LEFT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotate4Squares(TOP_FACE, TOP, LEFT_FACE, LEFT, BOTTOM_FACE, BOTTOM, RIGHT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, TOP_RIGHT, LEFT_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_RIGHT);
	rotateFace(BACK_FACE);
}

void InteractableCube::leftMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_LEFT, BACK_FACE, BOTTOM_RIGHT, TOP_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, LEFT, BOTTOM_FACE, LEFT, BACK_FACE, RIGHT, TOP_FACE, LEFT);
	rotate4Squares(FRONT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_LEFT, BACK_FACE, TOP_RIGHT, TOP_FACE, BOTTOM_LEFT);
	rotateFace(LEFT_FACE);
}

void InteractableCube::topMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, LEFT_FACE, TOP_LEFT, BACK_FACE, TOP_LEFT, RIGHT_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, TOP, LEFT_FACE, TOP, BACK_FACE, TOP, RIGHT_FACE, TOP);
	rotate4Squares(FRONT_FACE, TOP_RIGHT, LEFT_FACE, TOP_RIGHT, BACK_FACE, TOP_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotateFace(TOP_FACE);
}

void InteractableCube::bottomMove() {
	rotate4Squares(FRONT_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_LEFT, BACK_FACE, BOTTOM_LEFT, LEFT_FACE, BOTTOM_LEFT);
	rotate4Squares(FRONT_FACE, BOTTOM, RIGHT_FACE, BOTTOM, BACK_FACE, BOTTOM, LEFT_FACE, BOTTOM);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_RIGHT, BACK_FACE, BOTTOM_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotateFace(BOTTOM_FACE);
}

void InteractableCube::frontInverseMove() {
	frontMove();
	frontMove();
	frontMove();
}

void InteractableCube::rightInverseMove() {
	rightMove();
	rightMove();
	rightMove();
}

void InteractableCube::backInverseMove() {
	backMove();
	backMove();
	backMove();
}

void InteractableCube::leftInverseMove() {
	leftMove();
	leftMove();
	leftMove();
}

void InteractableCube::topInverseMove() {
	topMove();
	topMove();
	topMove();
}

void InteractableCube::bottomInverseMove() {
	bottomMove();
	bottomMove();
	bottomMove();
}

void InteractableCube::rotateRightFront() {
	rotateFace(TOP_FACE);
	inverseRotateFace(BOTTOM_FACE);
	Color tempFace[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempFace[position] = cube[FRONT_FACE][position];
	}
	for (int face = FRONT_FACE; face < LEFT_FACE; face++) {
		for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
			cube[face][position] = cube[face + 1][position];
		}
	}
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		cube[LEFT_FACE][position] = tempFace[position];
	}
}

void InteractableCube::rotateTopFront() {
	rotateFace(LEFT_FACE);
	inverseRotateFace(RIGHT_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(BACK_FACE);
	rotateFace(BACK_FACE);
	Color tempFace[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempFace[position] = cube[FRONT_FACE][position];
		cube[FRONT_FACE][position] = cube[TOP_FACE][position];
		cube[TOP_FACE][position] = cube[BACK_FACE][position];
		cube[BACK_FACE][position] = cube[BOTTOM_FACE][position];
		cube[BOTTOM_FACE][position] = tempFace[position];
	}
}

void InteractableCube::rotateFrontFront() {
	rotateFace(FRONT_FACE);
	inverseRotateFace(BACK_FACE);
	rotateFace(TOP_FACE);
	rotateFace(RIGHT_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(LEFT_FACE);
	Color tempFace[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempFace[position] = cube[RIGHT_FACE][position];
		cube[RIGHT_FACE][position] = cube[TOP_FACE][position];
		cube[TOP_FACE][position] = cube[LEFT_FACE][position];
		cube[LEFT_FACE][position] = cube[BOTTOM_FACE][position];
		cube[BOTTOM_FACE][position] = tempFace[position];
	}
}
