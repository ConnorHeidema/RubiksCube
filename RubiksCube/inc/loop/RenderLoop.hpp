#pragma once
#include "../actionobjects/ActionSprite.hpp"
#include "../util/GameParameters.hpp"
#include <list>
#include <mutex>
#include <thread>
class RenderLoop {
public:
	static void start(sf::RenderWindow& window, std::list<ActionObject*>& actionSpritesPtrs, std::mutex& deletionMutex);
	static std::list<ActionObject*> getCopy(const std::list<ActionObject*>& actionSpritesPtrs);
	static void drawActionObjects(sf::RenderWindow& window, const std::list<ActionObject*>& actionSpritesPtrs);
	static void deleteCopy(std::list<ActionObject*>& actionSpritesPtrsCopy);
};
