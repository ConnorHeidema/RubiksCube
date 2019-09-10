#pragma once
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
class TitleShape : public ActionRectangleShape {
public:
	TitleShape();
	virtual ActionRectangleShape* clone() override;
	TitleShape(const TitleShape& other);
};
