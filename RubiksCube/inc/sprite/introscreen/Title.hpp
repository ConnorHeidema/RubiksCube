#pragma once
#include "../ActionSprite.hpp"
class Title :
	public ActionSprite {
public:
	Title();
	virtual ActionSprite* clone() override;
	Title(const Title& other);
};

