#pragma once
#include "../../util/GameParameters.hpp"
#include "../ActionText.hpp"
#include <string>
class MoveText : public ActionText {
public:
	MoveText();
	MoveText(int xPos, int yPos, std::string text);
	std::string textString;
	virtual MoveText* clone() override;
	MoveText(const MoveText& other);
};

