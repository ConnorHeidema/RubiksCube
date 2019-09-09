#include "..\..\inc\sprite\ActionSprite.hpp"

const int ActionSprite::CLICK_MIN_GAP_MILLIS = 2;
const int ActionSprite::DOUBLE_CLICK_MAX_GAP_MILLIS = 150;
const int ActionSprite::OBJECT_HOLD_REGISTER_TIME_MILLIS = 150;
const int ActionSprite::OBJECT_IS_DRAGGING = 120;

bool ActionSprite::containsMouse() {
	return (spritePtr->getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
}

void ActionSprite::onLeftClick(std::list<ActionSprite*>& actionSpritesPtrs) {
	const sf::Texture* texture2 = new sf::Texture();
	texture2 = spritePtr->getTexture();
	sf::Sprite* sprite2 = new sf::Sprite();
	sprite2->setTexture(*texture2);
	sprite2->setTextureRect(sf::IntRect(spritePtr->getTextureRect()));
	sprite2->setPosition(100 + spritePtr->getPosition().x, 300 + spritePtr->getPosition().y);
	ActionSprite* actionSprite2 = new ActionSprite(sprite2);
	actionSpritesPtrs.emplace_back(actionSprite2);
	
}
void ActionSprite::onMouseDown(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onDoubleClick(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onStartHold(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onHold(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onEndHold(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onStartHover(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onHover(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onEndHover(std::list<ActionSprite*>& allObjects) {}
void ActionSprite::onRightClick(std::list<ActionSprite*>& allObjects) {}

void ActionSprite::leftClickActions(std::list<ActionSprite*>& allObjects, bool isDragging) {
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

void ActionSprite::rightClickActions(std::list<ActionSprite*>& allObjects, bool isDragging) {
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

void ActionSprite::hoverActions(std::list<ActionSprite*>& allObjects, bool isDragging) {
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

bool ActionSprite::dragActions(std::list<ActionSprite*>& allObjects) {
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

sf::Texture* ActionSprite::BASE_TEXTURE_PTR = nullptr;

ActionSprite::ActionSprite(sf::Sprite* sprite) :
	toBeDeleted(false),
	clickSet(false),
	isDragging(false),
	isHovering(false),
	rightClickSet(false){
	spritePtr = sprite;
}

ActionSprite::ActionSprite(const ActionSprite& other) : 
	toBeDeleted(false),
	clickSet(false),
	isDragging(false), 
	isHovering(false),
	rightClickSet(false) {
	sf::Sprite* sprite = new sf::Sprite();
	sf::Texture* copyTexture = new sf::Texture(*other.spritePtr->getTexture());
	sprite->setTexture(*copyTexture);
	sprite->setTextureRect(other.spritePtr->getTextureRect());
	sprite->setPosition(other.spritePtr->getPosition());
	spritePtr = sprite;
}

ActionSprite::~ActionSprite() {
	delete spritePtr->getTexture();
	delete spritePtr;
}

void ActionSprite::action(std::list<ActionSprite*>& actionSpritesPtrs) {
	bool isDragging = dragActions(actionSpritesPtrs);
	if (!isDragging && sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& lastClickTime.getElapsedTime().asMilliseconds() > DOUBLE_CLICK_MAX_GAP_MILLIS)
		onMouseDown(actionSpritesPtrs);
	rightClickActions(actionSpritesPtrs, isDragging);
	leftClickActions(actionSpritesPtrs, isDragging);
	hoverActions(actionSpritesPtrs, isDragging);
}

ActionSprite* ActionSprite::clone() {
	return new ActionSprite(*this);
}
