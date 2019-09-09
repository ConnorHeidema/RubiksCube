#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
class ActionSprite {
private:
	static const int DOUBLE_CLICK_MAX_GAP_MILLIS;
	static const int CLICK_MIN_GAP_MILLIS;
	static const int OBJECT_HOLD_REGISTER_TIME_MILLIS;
	static const int OBJECT_IS_DRAGGING;

	sf::Clock dragClock;
	sf::Clock lastDragClock;
	sf::Clock rightClock;
	sf::Clock lastRightClock;
	sf::Clock initRightClickClock;
	sf::Clock clock;
	sf::Clock lastClock;
	sf::Clock initClickClock;
	sf::Clock doubleClickClock;
	sf::Clock lastClickTime;

	bool clickSet;
	bool rightClickSet;
	bool isHovering;
	bool isDragging;

	bool containsMouse();

	virtual void onLeftClick(std::list<ActionSprite*>& allObjects);
	virtual void onMouseDown(std::list<ActionSprite*>& allObjects);
	virtual void onDoubleClick(std::list<ActionSprite*>& allObjects);
	virtual void onStartHold(std::list<ActionSprite*>& allObjects);
	virtual void onHold(std::list<ActionSprite*>& allObjects);
	virtual void onEndHold(std::list<ActionSprite*>& allObjects);
	virtual void onStartHover(std::list<ActionSprite*>& allObjects);
	virtual void onHover(std::list<ActionSprite*>& allObjects);
	virtual void onEndHover(std::list<ActionSprite*>& allObjects);
	virtual void onRightClick(std::list<ActionSprite*>& allObjects);	
	
	void leftClickActions(std::list<ActionSprite*>& allObjects, bool isDragging);
	void rightClickActions(std::list<ActionSprite*>& allObjects, bool isDragging);
	void hoverActions(std::list<ActionSprite*>& allObjects, bool isDragging);
	bool dragActions(std::list<ActionSprite*>& allObjects);
public:
	static sf::Texture* BASE_TEXTURE_PTR;
	ActionSprite(sf::Sprite* sprite);
	ActionSprite(const ActionSprite& other);
	~ActionSprite();
	sf::Sprite* spritePtr;
	bool toBeDeleted;
	virtual void action(std::list<ActionSprite*>& actionSpritesPtrs);
	virtual ActionSprite* clone();
};
