#pragma once
#include "../ActionRectangleShape.hpp"
#include "../ActionText.hpp"
#include "../../util/GameParameters.hpp"
#include "../../datastructure/RubiksCube.hpp"
class RubiksMoveButton :
	virtual public ActionRectangleShape {
	virtual void onHover(std::list<ActionObject*>& allObjects);
	virtual void onEndHover(std::list<ActionObject*>& allObjects);
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	RubiksMoveButton();
	virtual RubiksMoveButton* clone() override;
	RubiksMoveButton(const RubiksMoveButton& other);

	void (RubiksCube::* fnPtr)();
	RubiksCube* rubiksPtr;
public:
	RubiksMoveButton(int xPos, int yPos, RubiksCube* rubiks, void (RubiksCube::* fnPtr)());
};