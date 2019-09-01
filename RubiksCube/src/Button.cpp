#include "..\inc\Button.hpp"
#include "..\inc\Util.hpp"

Button::Button(int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) {
	image.text = text;
	image.font = font;
	image.rectangle.setPosition(sf::Vector2f(xPosition, yPosition));
	image.rectangle.setSize(sf::Vector2f(xSize, ySize));
	image.rectangle.setOutlineThickness(thickness);
	image.rectangle.setOutlineColor(outlineColour);
	image.rectangle.setFillColor(color);

	if (!image.font.loadFromFile("arial.ttf")) {
		std::cout << "ERROR" << std::endl;
	}
	image.text.setFont(image.font);
	image.text.setString(buttonText);
	image.text.setCharacterSize(ySize/2);
	image.text.setFillColor(sf::Color::Black);
	image.text.setPosition(sf::Vector2f(xPosition - thickness, yPosition - thickness));

	leftClicked = false;
	rightClicked = false;
}

Image Button::getButtonImage() {
	return image;
}

void Button::action(sf::Vector2i mousePosition) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !leftClicked && Util::isWithin(mousePosition, image.rectangle)) {
		leftClicked = true;
		leftButtonClicked();
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		leftClicked = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !rightClicked && Util::isWithin(mousePosition, image.rectangle)) {
		rightClicked = true;
		rightButtonClicked();
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		rightClicked = false;
	}
}
