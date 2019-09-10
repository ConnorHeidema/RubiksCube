#pragma once
#include "../ActionSprite.hpp"
class BeginButton : public ActionSprite {
public:
	BeginButton();
	virtual ActionSprite* clone() override;
	BeginButton(const BeginButton& other);
};
