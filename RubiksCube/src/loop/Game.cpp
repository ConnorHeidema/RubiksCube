#include "..\..\inc\loop\Game.hpp"

void Game::start() {
	sf::Font* fontPtr = new sf::Font();
	fontPtr->loadFromFile("res/font/arial.ttf");

	sf::RenderWindow window(
		sf::VideoMode(GameParameters::SCREEN_WIDTH, GameParameters::SCREEN_HEIGHT),
		"Rubiks Game",
		sf::Style::Fullscreen
	);
	window.setActive(false);
	std::list<ActionSprite*> actionSpritesPtrs;
	setupInitialObjects(actionSpritesPtrs);
	std::mutex deletionMutex;
	std::thread thread(RenderLoop::start, std::ref(window), std::ref(actionSpritesPtrs), std::ref(deletionMutex));
	ActionLoop::start(window, actionSpritesPtrs, deletionMutex);
	thread.join();
}

void Game::setupInitialObjects(std::list<ActionSprite*>& actionSpritesPtrs) {
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile("res/png/white_square.png")) {
		std::cout << "load success" << std::endl;
	}
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setTextureRect(sf::IntRect(10, 10, 50, 30));
	sprite->setPosition(100, 25);
	ActionSprite* actionSprite = new ActionSprite(sprite);
	actionSpritesPtrs.emplace_back(actionSprite);

	sf::Texture* texture2 = new sf::Texture();
	if (texture2->loadFromFile("res/png/red.png")) {
		std::cout << "load success" << std::endl;
	}
	sf::Sprite* sprite2 = new sf::Sprite();
	sprite2->setTexture(*texture2);
	sprite2->setTextureRect(sf::IntRect(60, 20, 50, 30));
	sprite2->setPosition(100, 300);
	ActionSprite* actionSprite2 = new ActionSprite(sprite2);
	actionSpritesPtrs.emplace_back(actionSprite2);
}
