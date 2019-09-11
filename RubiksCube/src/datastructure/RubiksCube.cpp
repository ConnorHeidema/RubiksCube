#include "../../inc/datastructure/RubiksCube.hpp"

void RubiksCube::performFunction(Moves move) {
	switch (move) {
	case FRONT_MOVE: return this->frontMove(); break;
	case RIGHT_MOVE: return this->rightMove(); break;
	case BACK_MOVE: return this->backMove(); break;
	case LEFT_MOVE: return this->leftMove(); break;
	case TOP_MOVE: return topMove(); break;
	case BOTTOM_MOVE: return bottomMove(); break;
	case FRONT_INVERSE_MOVE: return frontInverseMove(); break;
	case RIGHT_INVERSE_MOVE: return rightInverseMove(); break;
	case BACK_INVERSE_MOVE: return backInverseMove(); break;
	case LEFT_INVERSE_MOVE: return leftInverseMove(); break;
	case TOP_INVERSE_MOVE: return topInverseMove(); break;
	case BOTTOM_INVERSE_MOVE: return bottomInverseMove(); break;
	case ROTATE_RIGHT_FRONT: return rotateRightFront(); break;
	case ROTATE_TOP_FRONT: return rotateTopFront(); break;
	case ROTATE_FRONT_FRONT: return rotateFrontFront(); break;
	case ROTATE_RIGHT_FRONT_INVERSE: return rotateRightFrontInverse(); break;
	case ROTATE_TOP_FRONT_INVERSE: return rotateTopFrontInverse(); break;
	case ROTATE_FRONT_FRONT_INVERSE: return rotateFrontFrontInverse(); break;
	}
}

Moves RubiksCube::getMove(std::string moveString) {
	if (moveString == "Front") {
		return FRONT_MOVE;
	} else if (moveString == "Right") {
		return RIGHT_MOVE;
	} else if (moveString == "Back") {
		return BACK_MOVE;
	} else if (moveString == "Left") {
		return LEFT_MOVE;
	} else if (moveString == "Top") {
		return TOP_MOVE;
	} else if (moveString == "Bottom") {
		return BOTTOM_MOVE;
	} else if (moveString == "Front Inverse") {
		return FRONT_INVERSE_MOVE;
	} else if (moveString == "Right Inverse") {
		return RIGHT_INVERSE_MOVE;
	} else if (moveString == "Back Inverse") {
		return BACK_INVERSE_MOVE;
	} else if (moveString == "Left Inverse") {
		return LEFT_INVERSE_MOVE;
	} else if (moveString == "Top Inverse") {
		return TOP_INVERSE_MOVE;
	} else if (moveString == "Bottom Inverse") {
		return BOTTOM_INVERSE_MOVE;
	} else if (moveString == "Rotate Right Front") {
		return ROTATE_RIGHT_FRONT;
	} else if (moveString == "Rotate Top Front") {
		return ROTATE_TOP_FRONT;
	} else if (moveString == "Rotate Front Front") {
		return ROTATE_FRONT_FRONT;
	} else if (moveString == "Rotate Right Front Inverse") {
		return ROTATE_RIGHT_FRONT_INVERSE;
	} else if (moveString == "Rotate Top Front Inverse") {
		return ROTATE_TOP_FRONT_INVERSE;
	} else if (moveString == "Rotate Front Front Inverse") {
		return ROTATE_FRONT_FRONT_INVERSE;
	}
}

std::string RubiksCube::getString(Moves move) {
	switch (move) {
	case FRONT_MOVE: return "Front"; break;
	case RIGHT_MOVE: return "Right"; break;
	case BACK_MOVE: return "Back"; break;
	case LEFT_MOVE: return "Left"; break;
	case TOP_MOVE: return "Top"; break;
	case BOTTOM_MOVE: return "Bottom"; break;
	case FRONT_INVERSE_MOVE: return "Front Inverse"; break;
	case RIGHT_INVERSE_MOVE: return "Right Inverse"; break;
	case BACK_INVERSE_MOVE: return "Back Inverse"; break;
	case LEFT_INVERSE_MOVE: return "Left Inverse"; break;
	case TOP_INVERSE_MOVE: return "Top Inverse"; break;
	case BOTTOM_INVERSE_MOVE: return "Bottom Inverse"; break;
	case ROTATE_RIGHT_FRONT: return "Rotate Right Front"; break;
	case ROTATE_TOP_FRONT: return "Rotate Top Front"; break;
	case ROTATE_FRONT_FRONT: return "Rotate Front Front"; break;
	case ROTATE_RIGHT_FRONT_INVERSE: return "Rotate Right Front Inverse"; break;
	case ROTATE_TOP_FRONT_INVERSE: return "Rotate Top Front Inverse"; break;
	case ROTATE_FRONT_FRONT_INVERSE: return "Rotate Front Front Inverse"; break;
	}
}

const sf::Color RubiksCube::cubeColors[NUM_COLORS] = {
	sf::Color::Green,
	sf::Color::Red,
	sf::Color::Yellow,
	sf::Color(255,165,0,255),
	sf::Color::White,
	sf::Color::Blue
};

void RubiksCube::rotate4Squares(Faces firstFace, Positions firstPosition,
	Faces secondFace, Positions secondPosition,
	Faces thirdFace, Positions thirdPosition,
	Faces fourthFace, Positions fourthPosition) {
	sf::Color tempColor = thisCube[fourthFace][fourthPosition];
	thisCube[fourthFace][fourthPosition] = thisCube[thirdFace][thirdPosition];
	thisCube[thirdFace][thirdPosition] = thisCube[secondFace][secondPosition];
	thisCube[secondFace][secondPosition] = thisCube[firstFace][firstPosition];
	thisCube[firstFace][firstPosition] = tempColor;
}

void RubiksCube::inverseRotate4Squares(Faces firstFace, Positions firstPosition,
	Faces secondFace, Positions secondPosition,
	Faces thirdFace, Positions thirdPosition,
	Faces fourthFace, Positions fourthPosition) {
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

void RubiksCube::rotateFace(Faces face) {
	sf::Color tempColor[2] = { thisCube[face][NUM_POSITIONS - 3], thisCube[face][NUM_POSITIONS - 2] };
	for (auto index = NUM_POSITIONS - 2; index >= 0; index--) {
		if (index < 2) {
			thisCube[face][index] = tempColor[index];
		} else {
			thisCube[face][index] = thisCube[face][index - 2];
		}
	}
}

void RubiksCube::inverseRotateFace(Faces face) {
	rotateFace(face);
	rotateFace(face);
	rotateFace(face);
}

RubiksCube::RubiksCube() {
	for (auto Face = 0; Face < NUM_FACES; Face++) {
		for (auto position = 0; position < NUM_POSITIONS; position++) {
			thisCube[Face][position] = cubeColors[Face];
		}
	}
}

void RubiksCube::frontMove() {
	rotate4Squares(TOP_FACE, BOTTOM_LEFT, RIGHT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM, RIGHT_FACE, LEFT, BOTTOM_FACE, TOP, LEFT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_LEFT, LEFT_FACE, TOP_RIGHT);
	rotateFace(FRONT_FACE);
}

void RubiksCube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(RIGHT_FACE);
}

void RubiksCube::backMove() {
	rotate4Squares(TOP_FACE, TOP_LEFT, LEFT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotate4Squares(TOP_FACE, TOP, LEFT_FACE, LEFT, BOTTOM_FACE, BOTTOM, RIGHT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, TOP_RIGHT, LEFT_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_RIGHT);
	rotateFace(BACK_FACE);
}

void RubiksCube::leftMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_LEFT, BACK_FACE, BOTTOM_RIGHT, TOP_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, LEFT, BOTTOM_FACE, LEFT, BACK_FACE, RIGHT, TOP_FACE, LEFT);
	rotate4Squares(FRONT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_LEFT, BACK_FACE, TOP_RIGHT, TOP_FACE, BOTTOM_LEFT);
	rotateFace(LEFT_FACE);
}

void RubiksCube::topMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, LEFT_FACE, TOP_LEFT, BACK_FACE, TOP_LEFT, RIGHT_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, TOP, LEFT_FACE, TOP, BACK_FACE, TOP, RIGHT_FACE, TOP);
	rotate4Squares(FRONT_FACE, TOP_RIGHT, LEFT_FACE, TOP_RIGHT, BACK_FACE, TOP_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotateFace(TOP_FACE);
}

void RubiksCube::bottomMove() {
	rotate4Squares(FRONT_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_LEFT, BACK_FACE, BOTTOM_LEFT, LEFT_FACE, BOTTOM_LEFT);
	rotate4Squares(FRONT_FACE, BOTTOM, RIGHT_FACE, BOTTOM, BACK_FACE, BOTTOM, LEFT_FACE, BOTTOM);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_RIGHT, BACK_FACE, BOTTOM_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotateFace(BOTTOM_FACE);
}

void RubiksCube::frontInverseMove() {
	frontMove();
	frontMove();
	frontMove();
}

void RubiksCube::rightInverseMove() {
	rightMove();
	rightMove();
	rightMove();
}

void RubiksCube::backInverseMove() {
	backMove();
	backMove();
	backMove();
}

void RubiksCube::leftInverseMove() {
	leftMove();
	leftMove();
	leftMove();
}

void RubiksCube::topInverseMove() {
	topMove();
	topMove();
	topMove();
}

void RubiksCube::bottomInverseMove() {
	bottomMove();
	bottomMove();
	bottomMove();
}

void RubiksCube::rotateRightFront() {
	rotateFace(TOP_FACE);
	inverseRotateFace(BOTTOM_FACE);
	sf::Color tempColor[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempColor[position] = thisCube[FRONT_FACE][position];
	}
	for (int face = FRONT_FACE; face < LEFT_FACE; face++) {
		for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
			thisCube[face][position] = thisCube[face + 1][position];
		}
	}
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		thisCube[LEFT_FACE][position] = tempColor[position];
	}
}

void RubiksCube::rotateTopFront() {
	rotateFace(LEFT_FACE);
	inverseRotateFace(RIGHT_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(BACK_FACE);
	rotateFace(BACK_FACE);
	sf::Color tempColor[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempColor[position] = thisCube[FRONT_FACE][position];
		thisCube[FRONT_FACE][position] = thisCube[TOP_FACE][position];
		thisCube[TOP_FACE][position] = thisCube[BACK_FACE][position];
		thisCube[BACK_FACE][position] = thisCube[BOTTOM_FACE][position];
		thisCube[BOTTOM_FACE][position] = tempColor[position];
	}
}

void RubiksCube::rotateFrontFront() {
	rotateFace(FRONT_FACE);
	inverseRotateFace(BACK_FACE);
	rotateFace(TOP_FACE);
	rotateFace(RIGHT_FACE);
	rotateFace(BOTTOM_FACE);
	rotateFace(LEFT_FACE);
	sf::Color tempColor[NUM_POSITIONS];
	for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
		tempColor[position] = thisCube[RIGHT_FACE][position];
		thisCube[RIGHT_FACE][position] = thisCube[TOP_FACE][position];
		thisCube[TOP_FACE][position] = thisCube[LEFT_FACE][position];
		thisCube[LEFT_FACE][position] = thisCube[BOTTOM_FACE][position];
		thisCube[BOTTOM_FACE][position] = tempColor[position];
	}
}

void RubiksCube::rotateRightFrontInverse() {
	rotateRightFront();
	rotateRightFront();
	rotateRightFront();
}

void RubiksCube::rotateTopFrontInverse() {
	rotateTopFront();
	rotateTopFront();
	rotateTopFront();
}

void RubiksCube::rotateFrontFrontInverse() {
	rotateFrontFront();
	rotateFrontFront();
	rotateFrontFront();
}
