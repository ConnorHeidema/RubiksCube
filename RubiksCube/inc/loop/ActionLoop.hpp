#pragma once
#include "../sprite/ActionSprite.hpp"
#include <list>
#include <mutex>
class ActionLoop {
public:
	static void start(sf::RenderWindow& window, std::list<ActionSprite*>& actionSpritesPtrs, std::mutex& deletionMutex);
	static void checkEvents(sf::RenderWindow& window);
	static void executeActions(std::list<ActionSprite*>& actionSpritesPtrs);
	static void spriteCleanup(std::list<ActionSprite*>& actionSpritesPtrs, std::mutex& deletionMutex);
};
