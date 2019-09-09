#pragma once
#include "../sprite/ActionSprite.hpp"
#include "../util/GameParameters.hpp"
#include <list>
#include <mutex>
class RenderLoop {
public:
	static void start(sf::RenderWindow& window, std::list<ActionSprite*>& actionSpritesPtrs, std::mutex& deletionMutex);
	static std::list<ActionSprite*> getCopy(std::list<ActionSprite*> actionSpritesPtrs);
	static void drawActionSprites(sf::RenderWindow& window, std::list<ActionSprite*>& actionSpritesPtrs);
};

