#include "..\..\..\inc\sprite\introscreen\BeginButton.hpp"

BeginButton::BeginButton() {
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile("res/png/green.png")) {
		std::cout << "load success" << std::endl;
	}
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setTextureRect(sf::IntRect(10, 10, 50, 30));
	sprite->setPosition(400, 400);
	spritePtr = sprite;
}

ActionSprite* BeginButton::clone() {
	return new BeginButton(*this);
}

BeginButton::BeginButton(const BeginButton& other) : ActionSprite(other) {
}
