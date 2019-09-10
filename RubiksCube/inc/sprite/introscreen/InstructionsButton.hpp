#pragma once
#include "../ActionSprite.hpp"
class InstructionsButton : public ActionSprite {
public:
	InstructionsButton();
	virtual ActionSprite* clone() override;
	InstructionsButton(const InstructionsButton& other);
};
