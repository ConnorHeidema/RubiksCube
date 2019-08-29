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

void Cube::drawSquare(const Face& face, const Position& position, const int& size, const int& xOffset, const int& yOffset) {

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

void Cube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, BOTTOM_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, TOP_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, BOTTOM_FACE, RIGHT, BACK_FACE, LEFT, TOP_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, BOTTOM_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, TOP_FACE, BOTTOM_RIGHT);
	rotateFace(FRONT_FACE);
}

void Cube::drawCentres(sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 3 * size;
	int yAdditionalOffset = 0;
	sf::RectangleShape visualSquare(sf::Vector2f(size, size));
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(RED)).second);
	window.draw(visualSquare);
	xAdditionalOffset += 3 * size;
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(YELLOW)).second);
	window.draw(visualSquare);
	xAdditionalOffset -= 9 * size;
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(ORANGE)).second);
	window.draw(visualSquare);
	xAdditionalOffset += 3 * size;
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(WHITE)).second);
	window.draw(visualSquare);
	yAdditionalOffset -= 3 * size;
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(BLUE)).second);
	window.draw(visualSquare);
	yAdditionalOffset += 6 * size;
	visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
	visualSquare.setFillColor((*colorMapping.find(GREEN)).second);
	window.draw(visualSquare);
}

void Cube::drawSides(sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 0;
	int yAdditionalOffset = 0;
	for (auto face = 0; face < NUM_FACES; face++) {
		for (auto position = 0; position < NUM_POSITIONS; position++) {
			xAdditionalOffset = 0;
			yAdditionalOffset = 0;
			sf::RectangleShape visualSquare(sf::Vector2f(size, size));
			switch (face) {
			case FRONT_FACE:
				break;
			case RIGHT_FACE:
				xAdditionalOffset += size * 3;
				break;
			case BACK_FACE:
				xAdditionalOffset += size * 6;
				break;
			case LEFT_FACE:
				xAdditionalOffset -= size * 3;
				break;
			case TOP_FACE:
				yAdditionalOffset -= size * 3;
				break;
			case BOTTOM_FACE:
				yAdditionalOffset += size * 3;
				break;
			}
			switch (position) {
			case TOP_LEFT:
				xAdditionalOffset -= size;
				yAdditionalOffset -= size;
				break;
			case TOP:
				yAdditionalOffset -= size;
				break;
			case TOP_RIGHT:
				xAdditionalOffset += size;
				yAdditionalOffset -= size;
				break;
			case RIGHT:
				xAdditionalOffset += size;
				break;
			case BOTTOM_RIGHT:
				xAdditionalOffset += size;
				yAdditionalOffset += size;
				break;
			case BOTTOM:
				yAdditionalOffset += size;
				break;
			case BOTTOM_LEFT:
				xAdditionalOffset -= size;
				yAdditionalOffset += size;
				break;
			case LEFT:
				xAdditionalOffset -= size;
				break;
			}
			visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
			visualSquare.setFillColor((*colorMapping.find(cube[face][position])).second);
			window.draw(visualSquare);
		}
	}

}

void Cube::drawFlat(sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	drawCentres(window, size, xOffset, yOffset);
	drawSides(window, size, xOffset, yOffset);
}
