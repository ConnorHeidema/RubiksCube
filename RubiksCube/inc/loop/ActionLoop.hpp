#pragma once
#include "../sprite/ActionSprite.hpp"
#include <list>
#include <mutex>
class ActionLoop {
public:
	static void start(sf::RenderWindow& window, std::list<ActionObject*>& actionSpritesPtrs, std::mutex& deletionMutex);
	static void checkEvents(sf::RenderWindow& window);
	static void executeActions(std::list<ActionObject*>& actionSpritesPtrs);
	static void spriteCleanup(std::list<ActionObject*>& actionSpritesPtrs, std::mutex& deletionMutex);
};
