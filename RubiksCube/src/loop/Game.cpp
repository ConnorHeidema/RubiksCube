#include "..\..\inc\loop\Game.hpp"

void Game::start() {

	sf::RenderWindow window(
		sf::VideoMode(GameParameters::SCREEN_WIDTH, GameParameters::SCREEN_HEIGHT),
		"Rubiks Game",
		sf::Style::Fullscreen
	);
	window.setActive(false);
	std::list<ActionObject*> actionObjectPtrs;
	setupInitialObjects(actionObjectPtrs);
	std::mutex deletionMutex;
	std::thread thread(RenderLoop::start, std::ref(window), std::ref(actionObjectPtrs), std::ref(deletionMutex));
	ActionLoop::start(window, actionObjectPtrs, deletionMutex);
	thread.join();
}

void Game::setupInitialObjects(std::list<ActionObject*>& actionSpritesPtrs) {
	actionSpritesPtrs.emplace_back(new InstructionsButton());
	actionSpritesPtrs.emplace_back(new InstructionsText());
	actionSpritesPtrs.emplace_back(new BeginButton());
	actionSpritesPtrs.emplace_back(new BeginText());
	actionSpritesPtrs.emplace_back(new TitleShape());
	actionSpritesPtrs.emplace_back(new Title());
}
