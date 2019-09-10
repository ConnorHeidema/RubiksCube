#include "..\..\inc\actionobjects\ActionSprite.hpp"

ActionSprite::ActionSprite() : spritePtr(nullptr) {
}

ActionSprite::ActionSprite(sf::Sprite* sprite) {
	spritePtr = sprite;
}

ActionSprite::ActionSprite(const ActionSprite& other) {
	sf::Sprite* sprite = new sf::Sprite();
	sf::Texture* copyTexture = new sf::Texture(*other.spritePtr->getTexture());
	sprite->setTexture(*copyTexture);
	sprite->setTextureRect(other.spritePtr->getTextureRect());
	sprite->setPosition(other.spritePtr->getPosition());
	spritePtr = sprite;
}

ActionSprite::~ActionSprite() {
	delete spritePtr->getTexture();
	delete spritePtr;
}

ActionSprite* ActionSprite::clone() {
	return new ActionSprite(*this);
}

sf::IntRect ActionSprite::getBounds() {
	return sf::IntRect(spritePtr->getGlobalBounds().left, 
		spritePtr->getGlobalBounds().top, 
		spritePtr->getGlobalBounds().width, 
		spritePtr->getGlobalBounds().height);
}

sf::Drawable* ActionSprite::getDrawable() {
	return spritePtr;
}
