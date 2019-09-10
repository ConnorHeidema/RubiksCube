#include "../../../inc/sprite/introscreen/InstructionsButton.hpp"

InstructionsButton::InstructionsButton() {
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile("res/png/blue.png")) {
		std::cout << "load success" << std::endl;
	}
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setTextureRect(sf::IntRect(10, 10, 50, 30));
	sprite->setPosition(100, 400);
	spritePtr = sprite;
}

ActionSprite* InstructionsButton::clone()  {
	return new InstructionsButton(*this);
}

InstructionsButton::InstructionsButton(const InstructionsButton& other) : ActionSprite(other) {
}
