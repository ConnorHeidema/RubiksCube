#include "..\..\inc\cube\Reset.hpp"

Reset::ResetButton::ResetButton(Reset* reset, int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = reset;
}


Reset::Reset() {
	resetButtonPtr =
		new ResetButton(this, 1700, 135, 200, 75, -5, sf::Color::Green, sf::Color::Magenta, sf::Text(), sf::Font(), "Reset");
	buttons.push_back(resetButtonPtr);
}

Reset::~Reset() {
	delete resetButtonPtr;
};

void Reset::resetCube() {
	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			cube[face][position] = static_cast<Color>(face);
		}
	}
}

void Reset::ResetButton::leftButtonClicked() {
	outerReference->resetCube();
}

void Reset::ResetButton::rightButtonClicked() {
}
