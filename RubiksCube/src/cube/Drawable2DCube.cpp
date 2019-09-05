#include "..\..\inc\cube\Drawable2DCube.hpp"
Drawable2DCube::Drawable2DCube() {
	const int initialXLocation = 800;
	const int initialYLocation = 225;
	for (int face = FRONT_FACE; face < NUM_FACES; face++) {
		for (int position = TOP_LEFT; position < NUM_POSITIONS; position++) {
			int xAdditionalOffset = 0;
			int yAdditionalOffset = 0;
			xAdditionalOffset += xFaceOffset(face, SIZE);
			yAdditionalOffset += yFaceOffset(face, SIZE);
			xAdditionalOffset += xPositionOffset(position, SIZE);
			yAdditionalOffset += yPositionOffset(position, SIZE);
			squares[face][position] = new SquareButton(this, face, position, 
				initialXLocation + xAdditionalOffset, initialYLocation + yAdditionalOffset, SIZE, SIZE, OUTLINE_THICKNESS,
				(*colorMapping.find(cube[face][position])).second, OUTLINE_COLOUR,sf::Text(), sf::Font(), "");
			buttons.push_back(squares[face][position]);
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

Drawable2DCube::~Drawable2DCube() {
	delete[] squares;
};

Drawable2DCube::SquareButton::SquareButton(Drawable2DCube* drawable2DCube, int face, int position, int xPosition, int yPosition, 
	int xSize, int ySize, int thickness, sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = drawable2DCube;
	colour = &(outerReference->cube[face][position]);
}

void Drawable2DCube::SquareButton::leftButtonClicked() {
	*colour = static_cast<Color>((*colour + 1) % NUM_FACES);
}

void Drawable2DCube::SquareButton::rightButtonClicked() {
	if (*colour == 0) {
		*colour = Cube::GREEN;
	} else {
		*colour = static_cast<Color>((*colour - 1) % NUM_FACES);
	}
}

Image Drawable2DCube::SquareButton::getButtonImage() {
	image.rectangle.setFillColor((*outerReference->colorMapping.find(*colour)).second);
	return image;
}
