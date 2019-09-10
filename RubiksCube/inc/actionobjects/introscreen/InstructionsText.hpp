#pragma once
#include "../ActionText.hpp"
#include "../../util/GameParameters.hpp"
class InstructionsText : public ActionText {
public:
	InstructionsText();
	virtual ActionText* clone() override;
	InstructionsText(const InstructionsText& other);
};
