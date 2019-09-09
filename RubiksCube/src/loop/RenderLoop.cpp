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
		deleteCopy(copiedList);
	}
}

std::list<ActionSprite*> RenderLoop::getCopy(const std::list<ActionSprite*>& actionSpritesPtrs) {
	std::list<ActionSprite*> copiedList;
	std::for_each(actionSpritesPtrs.begin(), actionSpritesPtrs.end(), 
		[&copiedList](ActionSprite* actionSpritePtr) {
		copiedList.emplace_back(actionSpritePtr->clone());
		});
	return copiedList;
}

void RenderLoop::drawActionSprites(sf::RenderWindow& window, const std::list<ActionSprite*>& actionSpritesPtrs) {
	std::for_each(actionSpritesPtrs.begin(), actionSpritesPtrs.end(), [&window](ActionSprite* actionSpritePtr) {
		window.draw(*actionSpritePtr->spritePtr);
		});
}

void RenderLoop::deleteCopy(std::list<ActionSprite*>& actionSpritesPtrsCopy) {
	std::for_each(actionSpritesPtrsCopy.begin(), actionSpritesPtrsCopy.end(), [](ActionSprite* actionSpritesPtrCopy) {
		delete actionSpritesPtrCopy;
		});
}