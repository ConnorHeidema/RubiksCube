#include "../inc/Cube.hpp"

void Cube::rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
	const Cube::Face& secondFace, const Cube::Position secondPosition, 
	const Cube::Face& thirdFace, const Cube::Position thirdPosition,
	const Cube::Face& fourthFace, const Cube::Position fourthPosition) {
	Color tempSquare = cube[fourthFace][fourthPosition];
	cube[fourthFace][fourthPosition] = cube[thirdFace][thirdPosition];
	cube[thirdFace][thirdPosition] = cube[secondFace][secondPosition];
	cube[secondFace][secondPosition] = cube[firstFace][firstPosition];
	cube[firstFace][firstPosition] = tempSquare;
}

void Cube::rotateFace(const Cube::Face& face) {
	Color tempSquare = cube[face][NUM_POSITIONS - 1];
	for (auto index = NUM_POSITIONS - 1; index >= 0; index--) {
		if (index == 0) {
			cube[face][index] = cube[face][6];
		} else if (index == 1) {
			cube[face][index] = tempSquare;
		} else {
			cube[face][index] = cube[face][index - 2];
		}
	}
}

Cube::Cube() {
	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			cube[face][position] = static_cast<Color>(face);
		}
	}
	colorMapping.emplace(WHITE, sf::Color::White);
	colorMapping.emplace(RED, sf::Color::Red);
	colorMapping.emplace(YELLOW, sf::Color::Yellow);
	colorMapping.emplace(ORANGE, sf::Color(255, 128, 64, 255));
	colorMapping.emplace(BLUE, sf::Color::Blue);
	colorMapping.emplace(GREEN, sf::Color::Green);
}

void Cube::frontMove() {
	rotate4Squares(TOP_FACE, BOTTOM_LEFT, RIGHT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM, RIGHT_FACE, LEFT, BOTTOM_FACE, TOP, LEFT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_LEFT, LEFT_FACE, TOP_RIGHT);
	rotateFace(FRONT_FACE);
}

void Cube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(RIGHT_FACE);
}

void Cube::backMove() {
	rotate4Squares(TOP_FACE, TOP_LEFT, LEFT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotate4Squares(TOP_FACE, TOP, LEFT_FACE, LEFT, BOTTOM_FACE, BOTTOM, RIGHT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, TOP_RIGHT, LEFT_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_RIGHT);
	rotateFace(BACK_FACE);
}

// UNFINISHED LEFT TOP AND BOTTOM MOVE @TODO AUGUST 30
void Cube::leftMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(LEFT_FACE);
}

void Cube::topMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(TOP_FACE);
}

void Cube::bottomMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(BOTTOM_FACE);
}

void Cube::colourSquare(sf::RenderWindow& window, sf::RectangleShape visualSquare, const int& xOffset, const int& yOffset, Color colour) {
	visualSquare.setPosition(sf::Vector2f(xOffset, yOffset));
	visualSquare.setFillColor((*colorMapping.find(colour)).second);
	window.draw(visualSquare);
}

void Cube::drawCentres(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 3 * size;
	int yAdditionalOffset = 0;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, RED);
	xAdditionalOffset += 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, YELLOW);
	xAdditionalOffset -= 9 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, ORANGE);
	xAdditionalOffset += 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, WHITE);
	yAdditionalOffset -= 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, BLUE);
	yAdditionalOffset += 6 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, GREEN);
}

int Cube::xFaceOffset(int face, const int& size) {
	if (face == LEFT_FACE) {
		return -3 * size;
	} else if (face == RIGHT_FACE) {
		return 3 * size;
	} else if (face == BACK_FACE) {
		return 6 * size;
	} else {
		return 0;
	}
}

int Cube::yFaceOffset(int face, const int& size) {
	if (face == TOP_FACE) {
		return -3 * size;
	} else if (face == BOTTOM_FACE) {
		return 3 * size;
	} else {
		return 0;
	}
}

int Cube::xPositionOffset(int position, const int& size) {
	switch (position) {
	case TOP_LEFT:
	case LEFT:
	case BOTTOM_LEFT:
		return -size;
	case TOP_RIGHT:
	case RIGHT:
	case BOTTOM_RIGHT:
		return size;
	}
	return 0;
}

int Cube::yPositionOffset(int position, const int& size) {
	switch (position) {
	case TOP_LEFT:
	case TOP:
	case TOP_RIGHT:
		return -size;
	case BOTTOM_LEFT:
	case BOTTOM:
	case BOTTOM_RIGHT:
		return size;
	}
	return 0;
}

void Cube::drawSides(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 0;
	int yAdditionalOffset = 0;
	for (auto face = 0; face < NUM_FACES; face++) {
		for (auto position = 0; position < NUM_POSITIONS; position++) {
			xAdditionalOffset = 0;
			yAdditionalOffset = 0;
			xAdditionalOffset += xFaceOffset(face, size);
			yAdditionalOffset += yFaceOffset(face, size);
			xAdditionalOffset += xPositionOffset(position, size);
			yAdditionalOffset += yPositionOffset(position, size);
			visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
			visualSquare.setFillColor((*colorMapping.find(cube[face][position])).second);
			window.draw(visualSquare);
		}
	}

}

void Cube::drawFlat(sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	sf::RectangleShape visualSquare(sf::Vector2f(size, size));
	visualSquare.setOutlineThickness(-5);
	visualSquare.setOutlineColor(sf::Color(64, 64, 64, 255));
	drawCentres(visualSquare, window, size, xOffset, yOffset);
	drawSides(visualSquare, window, size, xOffset, yOffset);
}
