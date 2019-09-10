#include "..\..\..\inc\actionobjects\introscreen\BeginText.hpp"

BeginText::BeginText() {
	int yOffset = 295;
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString("Begin");
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(32);
	text->setFont(*font);
	text->setPosition((GameParameters::SCREEN_WIDTH - text->getGlobalBounds().width) / 2, (GameParameters::SCREEN_HEIGHT - text->getGlobalBounds().height) / 2 + yOffset);
	textPtr = text;
}

ActionText* BeginText::clone() {
	return new BeginText(*this);
}

BeginText::BeginText(const BeginText& other) : ActionText(other) {
}
