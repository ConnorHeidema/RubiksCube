#include "..\..\inc\loop\RenderLoop.hpp"

void RenderLoop::start(sf::RenderWindow& window, std::list<ActionObject*>& ActionObjectsPtrs, std::mutex& deletionMutex) {
	window.setFramerateLimit(GameParameters::FRAMERATE);
	using namespace std::chrono_literals;
	std::list<ActionObject*> copiedList;
	while (window.isOpen()) {
		window.clear(GameParameters::BACKGROUND_COLOR);
		deletionMutex.lock();
		copiedList = getCopy(ActionObjectsPtrs);
		deletionMutex.unlock();
		drawActionObjects(window, copiedList);
		window.display();
		deleteCopy(copiedList);
	}
}

std::list<ActionObject*> RenderLoop::getCopy(const std::list<ActionObject*>& actionObjectsPtrs) {
	std::list<ActionObject*> copiedList;
	std::for_each(actionObjectsPtrs.begin(), actionObjectsPtrs.end(), 
		[&copiedList](ActionObject* ActionObjectPtr) {
		copiedList.emplace_back(ActionObjectPtr->clone());
		});
	return copiedList;
}

void RenderLoop::drawActionObjects(sf::RenderWindow& window, const std::list<ActionObject*>& actionObjectsPtrs) {
	std::for_each(actionObjectsPtrs.begin(), actionObjectsPtrs.end(), [&window](ActionObject* actionObjectPtr) {
		window.draw(*actionObjectPtr->getDrawable());
		});
}

void RenderLoop::deleteCopy(std::list<ActionObject*>& ActionObjectsPtrsCopy) {
	std::for_each(ActionObjectsPtrsCopy.begin(), ActionObjectsPtrsCopy.end(), [](ActionObject* actionObjectsPtrCopy) {
		delete actionObjectsPtrCopy;
		});
}