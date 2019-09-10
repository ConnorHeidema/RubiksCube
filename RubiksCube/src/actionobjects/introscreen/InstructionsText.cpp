#include "..\..\..\inc\actionobjects\introscreen\InstructionsText.hpp"

InstructionsText::InstructionsText() {
	int yOffset = 365;
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString("Instructions");
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(32);
	text->setFont(*font);
	text->setPosition((GameParameters::SCREEN_WIDTH - text->getGlobalBounds().width) / 2, (GameParameters::SCREEN_HEIGHT - text->getGlobalBounds().height) / 2 + yOffset);
	textPtr = text;
}

ActionText* InstructionsText::clone() {
	return new InstructionsText(*this);
}

InstructionsText::InstructionsText(const InstructionsText& other) : ActionText(other) {
}
