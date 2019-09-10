#pragma once
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
class InstructionsButton : public ActionRectangleShape {
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
public:
	InstructionsButton();
	virtual ActionRectangleShape* clone() override;
	InstructionsButton(const InstructionsButton & other);
};
