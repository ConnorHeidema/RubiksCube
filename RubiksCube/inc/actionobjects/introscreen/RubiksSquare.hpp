#pragma once
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
class RubiksSquare :
	public ActionRectangleShape {
	RubiksSquare();
	virtual RubiksSquare* clone() override;
	RubiksSquare(const RubiksSquare& other);
	sf::Color* colorPtr;
public:
	RubiksSquare(int xPos, int yPos, sf::Color& color);
};

