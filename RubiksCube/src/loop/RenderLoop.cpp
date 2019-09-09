#include "..\..\inc\loop\RenderLoop.hpp"

void RenderLoop::start(sf::RenderWindow& window, std::list<ActionSprite*>& actionSpritesPtrs, std::mutex& deletionMutex) {
	window.setFramerateLimit(GameParameters::FRAMERATE);
	std::list<ActionSprite*> copiedList;
	while (window.isOpen()) {
		window.clear(GameParameters::BACKGROUND_COLOR);
		deletionMutex.lock();
		copiedList = getCopy(actionSpritesPtrs);
		deletionMutex.unlock();
		drawActionSprites(window, copiedList);
		window.display();
	}
}

std::list<ActionSprite*> RenderLoop::getCopy(std::list<ActionSprite*> actionSpritesPtrs) {
	return actionSpritesPtrs;
}

void RenderLoop::drawActionSprites(sf::RenderWindow& window, std::list<ActionSprite*>& actionSpritesPtrs) {
	std::for_each(actionSpritesPtrs.begin(), actionSpritesPtrs.end(), [&window](ActionSprite* actionSpritePtr) {
		window.draw(*actionSpritePtr->spritePtr);
		});
}
