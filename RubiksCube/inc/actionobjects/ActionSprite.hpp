#pragma once
#include "ActionObject.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
class ActionSprite : virtual public ActionObject {
private:
protected:
	ActionSprite();
	sf::Sprite* spritePtr;

public:
	ActionSprite(sf::Sprite* sprite);
	ActionSprite(const ActionSprite& other);
	virtual	~ActionSprite();
	virtual ActionSprite* clone() override;
	virtual sf::IntRect getBounds() override;
	virtual sf::Drawable* getDrawable() override;
};
