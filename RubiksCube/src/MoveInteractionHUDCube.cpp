#include "..\inc\MoveInteractionHUDCube.hpp"

MoveInteractionHUDCube::MoveInteractionHUDCube() {
	const int& xStartingLocation = 1500;
	const int& yStartingLocation = 500;
	const int& width = 45;
	const int& height = 150;

	for (int rectIdx = FRONT_FACE; rectIdx < NUM_FACES; rectIdx++) {
		movementButtons[NORMAL][rectIdx].setFillColor(NORMAL_COLOUR);
		movementButtons[INVERSE][rectIdx].setFillColor(REVERSE_COLOUR);
		movementButtons[NORMAL][rectIdx].setOutlineThickness(BUTTON_OUTLINE_THICKNESS);
		movementButtons[INVERSE][rectIdx].setOutlineThickness(BUTTON_OUTLINE_THICKNESS);
		movementButtons[NORMAL][rectIdx].setOutlineColor(BUTTON_OUTLINE_COLOUR);
		movementButtons[INVERSE][rectIdx].setOutlineColor(BUTTON_OUTLINE_COLOUR);
	}

	movementButtons[NORMAL][FRONT_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[NORMAL][FRONT_FACE].setPosition(sf::Vector2f(xStartingLocation - height - width, yStartingLocation - 4 * width));
	movementButtons[NORMAL][RIGHT_FACE].setSize(sf::Vector2f(width, height));
	movementButtons[NORMAL][RIGHT_FACE].setPosition(sf::Vector2f(xStartingLocation + height + width, yStartingLocation));
	movementButtons[NORMAL][BACK_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[NORMAL][BACK_FACE].setPosition(sf::Vector2f(xStartingLocation + height + width, yStartingLocation - 4 * width));
	movementButtons[NORMAL][LEFT_FACE].setSize(sf::Vector2f(width, height));
	movementButtons[NORMAL][LEFT_FACE].setPosition(sf::Vector2f(xStartingLocation - 2 * width, yStartingLocation));
	movementButtons[NORMAL][TOP_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[NORMAL][TOP_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation - 2 * width));
	movementButtons[NORMAL][BOTTOM_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[NORMAL][BOTTOM_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation + height + width));
	movementButtons[INVERSE][FRONT_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[INVERSE][FRONT_FACE].setPosition(sf::Vector2f(xStartingLocation - height - width, yStartingLocation - 3 * width));
	movementButtons[INVERSE][RIGHT_FACE].setSize(sf::Vector2f(width, height));
	movementButtons[INVERSE][RIGHT_FACE].setPosition(sf::Vector2f(xStartingLocation + height, yStartingLocation));
	movementButtons[INVERSE][BACK_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[INVERSE][BACK_FACE].setPosition(sf::Vector2f(xStartingLocation + height + width, yStartingLocation - 3 * width));
	movementButtons[INVERSE][LEFT_FACE].setSize(sf::Vector2f(width, height));
	movementButtons[INVERSE][LEFT_FACE].setPosition(sf::Vector2f(xStartingLocation - width, yStartingLocation));
	movementButtons[INVERSE][TOP_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[INVERSE][TOP_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation - width));
	movementButtons[INVERSE][BOTTOM_FACE].setSize(sf::Vector2f(height, width));
	movementButtons[INVERSE][BOTTOM_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation + height));

	moveFnPtr[NORMAL][FRONT_FACE] = &MoveInteractionHUDCube::frontMove;
	moveFnPtr[NORMAL][RIGHT_FACE] = &MoveInteractionHUDCube::rightMove;
	moveFnPtr[NORMAL][BACK_FACE] = &MoveInteractionHUDCube::backMove;
	moveFnPtr[NORMAL][LEFT_FACE] = &MoveInteractionHUDCube::leftMove;
	moveFnPtr[NORMAL][TOP_FACE] = &MoveInteractionHUDCube::topMove;
	moveFnPtr[NORMAL][BOTTOM_FACE] = &MoveInteractionHUDCube::bottomMove;
	moveFnPtr[INVERSE][FRONT_FACE] = &MoveInteractionHUDCube::frontInverseMove;
	moveFnPtr[INVERSE][RIGHT_FACE] = &MoveInteractionHUDCube::rightInverseMove;
	moveFnPtr[INVERSE][BACK_FACE] = &MoveInteractionHUDCube::backInverseMove;
	moveFnPtr[INVERSE][LEFT_FACE] = &MoveInteractionHUDCube::leftInverseMove;
	moveFnPtr[INVERSE][TOP_FACE] = &MoveInteractionHUDCube::topInverseMove;
	moveFnPtr[INVERSE][BOTTOM_FACE] = &MoveInteractionHUDCube::bottomInverseMove;
}

MoveInteractionHUDCube::~MoveInteractionHUDCube() {};

void MoveInteractionHUDCube::drawHUD(sf::RenderWindow& window) {
	for (int rectIdx = FRONT_FACE; rectIdx < NUM_FACES; rectIdx++) {
		window.draw(movementButtons[NORMAL][rectIdx]);
		window.draw(movementButtons[INVERSE][rectIdx]);
	}
}

void MoveInteractionHUDCube::moveInteractionHudClick(const sf::Vector2i& mousePosition) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !hudClicked) {
		hudClicked = true;
		for (int rectIdx = FRONT_FACE; rectIdx < NUM_FACES; rectIdx++) {
			if (Util::isWithin(mousePosition, movementButtons[NORMAL][rectIdx])) {
				(this->*moveFnPtr[NORMAL][rectIdx])();
			} else if (Util::isWithin(mousePosition, movementButtons[INVERSE][rectIdx])) {
				(this->*moveFnPtr[INVERSE][rectIdx])();
			}
		}
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		hudClicked = false;
	}
}