#pragma once
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
#include "../../datastructure/RubiksCube.hpp"
class ScrambleButton : public ActionRectangleShape {
	RubiksCube* rubiksPtr;
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	virtual void onHover(std::list<ActionObject*>& allObjects) override;
	virtual void onEndHover(std::list<ActionObject*>& allObjects) override;
public:
	ScrambleButton();
	ScrambleButton(RubiksCube* rubiks);
	ActionRectangleShape* clone();
	ScrambleButton(const ScrambleButton& other);
};

