#pragma once
#include "../ActionRectangleShape.hpp"
#include "../playscreen/RubiksMoveButton.hpp"
#include "../playscreen/MoveText.hpp"
#include "../../util/GameParameters.hpp"
#include "../../loop/Game.hpp"
class BeginButton : public ActionRectangleShape {
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	virtual void onHover(std::list<ActionObject*>& allObjects) override;
	virtual void onEndHover(std::list<ActionObject*>& allObjects) override;
public:
	BeginButton();
	virtual ActionRectangleShape* clone() override;
	BeginButton(const BeginButton& other);
};
