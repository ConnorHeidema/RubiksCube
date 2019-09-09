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
	texture->loadFromFile("res/png/white_square.png");
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setTextureRect(sf::IntRect(10, 10, 50, 30));
	sprite->setPosition(100, 25);
	ActionSprite* actionSprite = new ActionSprite(sprite);
	actionSpritesPtrs.emplace_back(actionSprite);
}
