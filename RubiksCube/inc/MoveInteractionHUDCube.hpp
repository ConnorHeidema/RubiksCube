#pragma once
#include "SFML/Graphics.hpp"
#include "InteractableCube.hpp"
#include <iostream>
class MoveInteractionHUDCube : public virtual InteractableCube {
private:
	bool hudClicked = false;
	const int NORMAL = 0;
	const int INVERSE = 1;
	const sf::Color NORMAL_COLOUR = sf::Color(86,170,242,255);
	const sf::Color REVERSE_COLOUR = sf::Color(185,86,242,255);
	sf::RectangleShape movementButtons[2][6];
	void (MoveInteractionHUDCube::* moveFnPtr[2][NUM_FACES])(void);
protected:
	MoveInteractionHUDCube();
public:
	virtual ~MoveInteractionHUDCube() = 0;
	void drawHUD(sf::RenderWindow& window);
	void moveInteractionHudClick(const sf::Vector2i&);
};
