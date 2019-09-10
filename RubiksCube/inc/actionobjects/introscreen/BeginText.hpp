#pragma once
#include "../ActionText.hpp"
#include "../../util/GameParameters.hpp"
class BeginText :
	public ActionText {
public:
	BeginText();
	virtual ActionText* clone() override;
	BeginText(const BeginText& other);
};
