#pragma once
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
class InstructionsButton : public ActionRectangleShape {
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	virtual void onHover(std::list<ActionObject*>& allObjects);
	virtual void onEndHover(std::list<ActionObject*>& allObjects);
public:
	InstructionsButton();
	virtual ActionRectangleShape* clone() override;
	InstructionsButton(const InstructionsButton & other);
};
