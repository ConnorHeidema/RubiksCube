#pragma once
#include "SFML/Graphics.hpp"
#include <list>
class ActionSprite {
public:
	ActionSprite();
	sf::Sprite* spritePtr;
	bool toBeDeleted;
	virtual void action(std::list<ActionSprite*>& actionSpritesPtrs);
};
