#include "..\..\inc\actionobjects\ActionText.hpp"

ActionText::ActionText() : textPtr(nullptr) {
}

std::string ActionText::getFontLocation() {
	return "res/font/arial.ttf";
}

ActionText::ActionText(sf::Text* text) {
	textPtr = text;
}

ActionText::ActionText(const ActionText& other) {
	sf::Text* text = new sf::Text();
	sf::Font* copyFont = new sf::Font();
	copyFont->loadFromFile(getFontLocation());
	text->setFont(*copyFont); 
	text->setFillColor(other.textPtr->getFillColor());
	text->setString(other.textPtr->getString());
	text->setCharacterSize(other.textPtr->getCharacterSize());
	text->setPosition(other.textPtr->getPosition());
	textPtr = text;
}

ActionText::~ActionText() {
	delete textPtr->getFont();
	delete textPtr;
}

ActionObject* ActionText::clone() {
	return new ActionText(*this);
}

sf::IntRect ActionText::getBounds() {
	return sf::IntRect(textPtr->getGlobalBounds().left, 
		textPtr->getGlobalBounds().top, 
		textPtr->getGlobalBounds().width,
		textPtr->getGlobalBounds().height);
}

sf::Drawable* ActionText::getDrawable() {
	return textPtr;
}
