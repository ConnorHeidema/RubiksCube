#include "..\..\..\inc\sprite\introscreen\Title.hpp"


Title::Title() {
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

ActionSprite* Title::clone() {
	return new Title(*this);
}

Title::Title(const Title& other) : ActionSprite(other) {
}
