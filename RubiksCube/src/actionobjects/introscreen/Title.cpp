#include "..\..\..\inc\actionobjects\introscreen\Title.hpp"


Title::Title() {
	int yOffset = -450;
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString("Rubiks Cube Simulator");
	text->setFillColor(sf::Color::White);	
	text->setCharacterSize(64);
	text->setFont(*font);
	text->setPosition((GameParameters::SCREEN_WIDTH - text->getGlobalBounds().width)/2, (GameParameters::SCREEN_HEIGHT - text->getGlobalBounds().height )/2 + yOffset);
	textPtr = text;
}

ActionText* Title::clone() {
	return new Title(*this);
}

Title::Title(const Title& other) : ActionText(other) {
}
