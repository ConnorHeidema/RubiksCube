#include "..\..\..\inc\actionobjects\playscreen\MoveText.hpp"

MoveText::MoveText() : textString("null") {
	int yOffset = 295;
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString(textString);
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(32);
	text->setFont(*font);
	text->setPosition(0,0);
	textPtr = text;
}

MoveText::MoveText(int xPos, int yPos, std::string textString) {
	sf::Font* font = new sf::Font();
	if (font->loadFromFile("res/font/arial.ttf")) {
		std::cout << "load success" << std::endl;
	}
	sf::Text* text = new sf::Text();
	text->setString(textString);
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(32);
	text->setFont(*font);
	text->setPosition(xPos, yPos);
	textPtr = text;
}

MoveText* MoveText::clone() {
	return new MoveText(*this);
}

MoveText::MoveText(const MoveText& other) : ActionText(other) {
	textPtr->setPosition(other.textPtr->getPosition());
	textPtr->setString(other.textPtr->getString());
}