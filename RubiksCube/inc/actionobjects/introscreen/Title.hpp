#pragma once
#include "../ActionText.hpp"
#include "../../util/GameParameters.hpp"
class Title :
	public ActionText {
public:
	Title();
	virtual ActionText* clone() override;
	Title(const Title& other);
};
