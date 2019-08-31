#include "..\inc\Button.hpp"


Button::Button(int xPosition, int yPosition, 
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour, 
	void(*onLeftClick)(), void(*onRightClick)()) {
	leftClickAction = onLeftClick;
	rightClickAction = onRightClick;

}

void Button::drawButton(sf::RenderWindow) {
	
}

void Button::action() {
	leftClickAction();
	rightClickAction();
}
