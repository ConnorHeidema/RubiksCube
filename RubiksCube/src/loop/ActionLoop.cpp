#include "..\..\inc\loop\ActionLoop.hpp"

void ActionLoop::start(sf::RenderWindow& window, std::list<ActionObject*>& actionSpritesPtrs, std::mutex& deletionMutex) {
	while (window.isOpen()) {
		checkEvents(window);
		executeActions(actionSpritesPtrs);
		spriteCleanup(actionSpritesPtrs, deletionMutex);
		auto iter = actionSpritesPtrs.begin();
	}
}

void ActionLoop::checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void ActionLoop::executeActions(std::list<ActionObject*>& actionSpritesPtrs) {
	std::for_each(actionSpritesPtrs.begin(), actionSpritesPtrs.end(), [ &actionSpritesPtrs](ActionObject* actionSpritePtr) {
		actionSpritePtr->action(actionSpritesPtrs);
		});
}

void ActionLoop::spriteCleanup(std::list<ActionObject*>& actionSpritesPtrs, std::mutex& deletionMutex) {
	auto actionSpriteIterator = actionSpritesPtrs.begin();
	while (actionSpriteIterator != actionSpritesPtrs.end()) {
		if ((*actionSpriteIterator)->toBeDeleted) {
			deletionMutex.lock();
			(*actionSpriteIterator)->onRemove(actionSpritesPtrs);
			delete* actionSpriteIterator;
			actionSpriteIterator = actionSpritesPtrs.erase(actionSpriteIterator);
			deletionMutex.unlock();
		} else {
			actionSpriteIterator++;
		}
	}
}
