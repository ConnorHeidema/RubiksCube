#include "..\inc\Util.hpp"

bool Util::isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle) {
	if (rectangle.getGlobalBounds().left < mouse.x && rectangle.getGlobalBounds().top < mouse.y &&
		rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width > mouse.x &&
		rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height > mouse.y) {
		return true;
	}
	return false;
}

DebugButton::DebugButton(int xPosition, int yPosition, int xSize, int ySize, int thickness, 
	sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
}

void DebugButton::leftButtonClicked() {
	std::cout << "Mouse position \nx:" << sf::Mouse::getPosition().x << "\ny:" << sf::Mouse::getPosition().y << std::endl;
}

void DebugButton::rightButtonClicked() {
}
