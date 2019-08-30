#include "..\..\inc\cube\Drawable2DCube.hpp"
Drawable2DCube::Drawable2DCube() {
	for (int face = FRONT_FACE; face < NUM_FACES; face++) {
		for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
			squares[face][position].setSize(sf::Vector2f(SIZE, SIZE));
			squares[face][position].setOutlineThickness(OUTLINE_THICKNESS);
			squares[face][position].setOutlineColor(OUTLINE_COLOUR);
		}
	}
};

int Drawable2DCube::xFaceOffset(int face, const int& SIZE) {
	if (face == LEFT_FACE) {
		return -3 * SIZE;
	} else if (face == RIGHT_FACE) {
		return 3 * SIZE;
	} else if (face == BACK_FACE) {
		return 6 * SIZE;
	} else {
		return 0;
	}
}

int Drawable2DCube::yFaceOffset(int face, const int& SIZE) {
	if (face == TOP_FACE) {
		return -3 * SIZE;
	} else if (face == BOTTOM_FACE) {
		return 3 * SIZE;
	} else {
		return 0;
	}
}

int Drawable2DCube::xPositionOffset(int position, const int& SIZE) {
	switch (position) {
	case TOP_LEFT:
	case LEFT:
	case BOTTOM_LEFT:
		return -SIZE;
	case TOP_RIGHT:
	case RIGHT:
	case BOTTOM_RIGHT:
		return SIZE;
	}
	return 0;
}

int Drawable2DCube::yPositionOffset(int position, const int& SIZE) {
	switch (position) {
	case TOP_LEFT:
	case TOP:
	case TOP_RIGHT:
		return -SIZE;
	case BOTTOM_LEFT:
	case BOTTOM:
	case BOTTOM_RIGHT:
		return SIZE;
	}
	return 0;
}

Drawable2DCube::~Drawable2DCube() {};

void Drawable2DCube::drawFlat(sf::RenderWindow& window, const int& SIZE, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 0;
	int yAdditionalOffset = 0;
	for (auto face = 0; face < NUM_FACES; face++) {
		for (auto position = 0; position < NUM_POSITIONS; position++) {
			xAdditionalOffset = 0;
			yAdditionalOffset = 0;
			xAdditionalOffset += xFaceOffset(face, SIZE);
			yAdditionalOffset += yFaceOffset(face, SIZE);
			xAdditionalOffset += xPositionOffset(position, SIZE);
			yAdditionalOffset += yPositionOffset(position, SIZE);
			squares[face][position].setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
			squares[face][position].setFillColor((*colorMapping.find(cube[face][position])).second);
			window.draw(squares[face][position]);
		}
	}
}

void Drawable2DCube::squareClick(const sf::Vector2i& mousePosition) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !squareClicked == true) {
		squareClicked = true;
		for (auto face = 0; face < NUM_FACES; face++) {
			for (auto position = 0; position < NUM_POSITIONS; position++) {
				if (Util::isWithin(mousePosition, squares[face][position])) {
					cube[face][position] = static_cast<Color>((cube[face][position] + 1) % NUM_FACES);
				}
			}
		}
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		squareClicked = false;
	}
}
