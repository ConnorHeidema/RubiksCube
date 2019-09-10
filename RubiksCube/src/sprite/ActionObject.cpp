#include "../../inc/sprite/ActionObject.hpp"

const int ActionObject::CLICK_MIN_GAP_MILLIS = 2;
const int ActionObject::DOUBLE_CLICK_MAX_GAP_MILLIS = 150;
const int ActionObject::OBJECT_HOLD_REGISTER_TIME_MILLIS = 150;
const int ActionObject::OBJECT_IS_DRAGGING = 120;

bool ActionObject::containsMouse() {
	return (getBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
}

void ActionObject::onLeftClick(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onMouseDown(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onDoubleClick(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onStartHold(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onHold(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onEndHold(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onStartHover(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onHover(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onEndHover(std::list<ActionObject*>& allObjects) {
}

void ActionObject::onRightClick(std::list<ActionObject*>& allObjects) {
}

void ActionObject::leftClickActions(std::list<ActionObject*>& allObjects, bool isDragging) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clock = lastClock;
		lastClock.restart();
	}
	if (clock.getElapsedTime().asMilliseconds() - lastClock.getElapsedTime().asMilliseconds() >
		DOUBLE_CLICK_MAX_GAP_MILLIS &&
		containsMouse()) {
		initClickClock.restart();
		clickSet = true;
	} else if (clock.getElapsedTime().asMilliseconds() - lastClock.getElapsedTime().asMilliseconds() >
		CLICK_MIN_GAP_MILLIS &&
		clock.getElapsedTime().asMilliseconds() - lastClock.getElapsedTime().asMilliseconds() <
		DOUBLE_CLICK_MAX_GAP_MILLIS &&
		containsMouse()) {
		doubleClickClock.restart();
	} else if (clickSet && initClickClock.getElapsedTime().asMilliseconds() >
		DOUBLE_CLICK_MAX_GAP_MILLIS) {
		if (initClickClock.getElapsedTime().asMilliseconds() > doubleClickClock.getElapsedTime().asMilliseconds() &&
			!isDragging &&
			containsMouse()) {
			onDoubleClick(allObjects);
			lastClickTime.restart();
		} else if (!isDragging) {
			onLeftClick(allObjects);
			lastClickTime.restart();
		}
		clickSet = false;
	}
}

void ActionObject::rightClickActions(std::list<ActionObject*>& allObjects, bool isDragging) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		rightClock = lastRightClock;
		lastRightClock.restart();
		rightClickSet = true;
	}
	if (rightClickSet && rightClock.getElapsedTime().asMilliseconds() -
		lastRightClock.getElapsedTime().asMilliseconds() >
		CLICK_MIN_GAP_MILLIS &&
		containsMouse()) {
		if (!isDragging) {
			onRightClick(allObjects);
			lastClickTime.restart();
		}
		rightClickSet = false;
	}
}

void ActionObject::hoverActions(std::list<ActionObject*>& allObjects, bool isDragging) {
	if (!isDragging) {
		if (!containsMouse() && !isHovering) {
			return;
		} else if (containsMouse() && !isHovering) {
			if (!isDragging) {
				onStartHover(allObjects);
			}
			isHovering = true;
		} else if (containsMouse() && isHovering && !isDragging) {
			onHover(allObjects);
		} else {
			isHovering = false;
			if (!isDragging) {
				onEndHover(allObjects);
			}
		}
	}
}

bool ActionObject::dragActions(std::list<ActionObject*>& allObjects) {
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		dragClock.restart();
	}
	if (dragClock.getElapsedTime().asMilliseconds() >
		OBJECT_IS_DRAGGING) {
		clickSet = false;
	}
	if (dragClock.getElapsedTime().asMilliseconds() >
		OBJECT_IS_DRAGGING && containsMouse() &&
		!isDragging) {
		isDragging = true;
		clickSet = false;
		onStartHold(allObjects);
		return true;
	} else if (dragClock.getElapsedTime().asMilliseconds() >
		OBJECT_IS_DRAGGING && containsMouse() &&
		isDragging) {
		onHold(allObjects);
	} else if (isDragging) {
		isDragging = false;
		onEndHold(allObjects);
	}
	return false;
}

ActionObject::ActionObject() :
	toBeDeleted(false),
	clickSet(false),
	isDragging(false),
	isHovering(false),
	rightClickSet(false) {
}

ActionObject::ActionObject(const ActionObject& other) :
	toBeDeleted(false),
	clickSet(false),
	isDragging(false),
	isHovering(false),
	rightClickSet(false) {
}

void ActionObject::action(std::list<ActionObject*>& actionObjectPtrs) {
	bool isDragging = dragActions(actionObjectPtrs);
	if (!isDragging && sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& lastClickTime.getElapsedTime().asMilliseconds() > DOUBLE_CLICK_MAX_GAP_MILLIS)
		onMouseDown(actionObjectPtrs);
	rightClickActions(actionObjectPtrs, isDragging);
	leftClickActions(actionObjectPtrs, isDragging);
	hoverActions(actionObjectPtrs, isDragging);
}

ActionObject::~ActionObject() {
}
