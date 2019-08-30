#include "inc\MoveInteractionHUDCube.hpp"

const bool MoveInteractionHUDCube::isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle) {
	if (rectangle.getGlobalBounds().left < mouse.x && rectangle.getGlobalBounds().top < mouse.y &&
		rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width > mouse.x &&
		rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height > mouse.y) {
		return true;
	}
	return false;
}

MoveInteractionHUDCube::MoveInteractionHUDCube() {
	const int& xStartingLocation = 1500;
	const int& yStartingLocation = 500;
	const int& width = 45;
	const int& height = 150;
	for (int rectIdx = FRONT_FACE; rectIdx < NUM_FACES; rectIdx++) {
		rectangles[NORMAL][rectIdx].setFillColor(NORMAL_COLOUR);
		rectangles[INVERSE][rectIdx].setFillColor(REVERSE_COLOUR);
	}

	rectangles[NORMAL][FRONT_FACE];
	rectangles[NORMAL][RIGHT_FACE].setSize(sf::Vector2f(width, height));
	rectangles[NORMAL][RIGHT_FACE].setPosition(sf::Vector2f(xStartingLocation + height + width, yStartingLocation));
	rectangles[NORMAL][BACK_FACE];
	rectangles[NORMAL][LEFT_FACE].setSize(sf::Vector2f(width, height));
	rectangles[NORMAL][LEFT_FACE].setPosition(sf::Vector2f(xStartingLocation - 2 * width, yStartingLocation));
	rectangles[NORMAL][TOP_FACE].setSize(sf::Vector2f(height, width));
	rectangles[NORMAL][TOP_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation - 2 * width));
	rectangles[NORMAL][BOTTOM_FACE].setSize(sf::Vector2f(height, width));
	rectangles[NORMAL][BOTTOM_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation + height + width));
	rectangles[INVERSE][FRONT_FACE];
	rectangles[INVERSE][RIGHT_FACE].setSize(sf::Vector2f(width, height));
	rectangles[INVERSE][RIGHT_FACE].setPosition(sf::Vector2f(xStartingLocation + height, yStartingLocation));
	rectangles[INVERSE][BACK_FACE];
	rectangles[INVERSE][LEFT_FACE].setSize(sf::Vector2f(width, height));
	rectangles[INVERSE][LEFT_FACE].setPosition(sf::Vector2f(xStartingLocation - width, yStartingLocation));
	rectangles[INVERSE][TOP_FACE].setSize(sf::Vector2f(height, width));
	rectangles[INVERSE][TOP_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation - width));
	rectangles[INVERSE][BOTTOM_FACE].setSize(sf::Vector2f(height, width));
	rectangles[INVERSE][BOTTOM_FACE].setPosition(sf::Vector2f(xStartingLocation, yStartingLocation + height));

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
		window.draw(rectangles[NORMAL][rectIdx]);
		window.draw(rectangles[INVERSE][rectIdx]);
	}
}

void MoveInteractionHUDCube::moveInteractionHudClick(const sf::Vector2i& mousePosition) {
	for (int rectIdx = FRONT_FACE; rectIdx < NUM_FACES; rectIdx++) {
		if (isWithin(mousePosition, rectangles[NORMAL][rectIdx])) {
			(this->*moveFnPtr[NORMAL][rectIdx])();
		} else if (isWithin(mousePosition, rectangles[INVERSE][rectIdx])) {
			(this->*moveFnPtr[INVERSE][rectIdx])();
		}
	}
}