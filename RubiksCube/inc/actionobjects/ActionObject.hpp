#pragma once
#include "SFML/Graphics.hpp"
#include <list>
class ActionObject {
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

	virtual void onLeftClick(std::list<ActionObject*>& allObjects);
	virtual void onMouseDown(std::list<ActionObject*>& allObjects);
	virtual void onDoubleClick(std::list<ActionObject*>& allObjects);
	virtual void onStartHold(std::list<ActionObject*>& allObjects);
	virtual void onHold(std::list<ActionObject*>& allObjects);
	virtual void onEndHold(std::list<ActionObject*>& allObjects);
	virtual void onStartHover(std::list<ActionObject*>& allObjects);
	virtual void onHover(std::list<ActionObject*>& allObjects);
	virtual void onEndHover(std::list<ActionObject*>& allObjects);
	virtual void onRightClick(std::list<ActionObject*>& allObjects);
	virtual void onTimePassing(std::list<ActionObject*>& allObjects);

	void leftClickActions(std::list<ActionObject*>& allObjects, bool isDragging);
	void rightClickActions(std::list<ActionObject*>& allObjects, bool isDragging);
	void hoverActions(std::list<ActionObject*>& allObjects, bool isDragging);
	bool dragActions(std::list<ActionObject*>& allObjects);

	virtual sf::IntRect getBounds() = 0;
protected:
	ActionObject();
	ActionObject(const ActionObject& other);
public:
	virtual sf::Drawable* getDrawable() = 0;
	void action(std::list<ActionObject*>& actionObjectPtrs);
	virtual	~ActionObject() = 0;
	virtual ActionObject* clone() = 0;
	virtual void onRemove(std::list<ActionObject*>& allObjects);
	bool toBeDeleted;
};
