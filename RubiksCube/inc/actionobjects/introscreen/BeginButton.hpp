#pragma once
#include "../ActionRectangleShape.hpp"
#include "../playscreen/RubiksMoveButton.hpp"
#include "../playscreen/MoveText.hpp"
#include "../../util/GameParameters.hpp"
#include "../../loop/Game.hpp"
#include "../playscreen/ScrambleButton.hpp"
#include "../playscreen/SolveButton.hpp"
class BeginButton : public ActionRectangleShape {
	void setupMoveButtons(std::list<ActionObject*>& allObjects, RubiksCube* rubiks);
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	virtual void onHover(std::list<ActionObject*>& allObjects) override;
	virtual void onEndHover(std::list<ActionObject*>& allObjects) override;
public:
	BeginButton();
	virtual ActionRectangleShape* clone() override;
	BeginButton(const BeginButton& other);
};
