#pragma once
#include "ActionObject.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
class ActionRectangleShape : virtual public ActionObject {
private:
protected:
	ActionRectangleShape();
	sf::RectangleShape* rectShapePtr;

public:
	ActionRectangleShape(sf::RectangleShape* rectShapePtr);
	ActionRectangleShape(const ActionRectangleShape& other);
	virtual	~ActionRectangleShape();
	virtual ActionObject* clone() override;
	sf::IntRect getBounds() override;
	virtual sf::Drawable* getDrawable() override;
};
