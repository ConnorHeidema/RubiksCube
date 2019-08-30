#pragma once
#include "SFML/Graphics.hpp"
#include "InteractableCube.hpp"
#include <iostream>
class MoveInteractionHUDCube : public virtual InteractableCube {
private:
	const int NORMAL = 0;
	const int INVERSE = 1;
	const sf::Color NORMAL_COLOUR = sf::Color::Red;
	const sf::Color REVERSE_COLOUR = sf::Color::Blue;
	sf::RectangleShape rectangles[2][6];
	const bool isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle);
	void (MoveInteractionHUDCube::* moveFnPtr[2][6])(void);
protected:
	MoveInteractionHUDCube();
public:
	virtual ~MoveInteractionHUDCube() = 0;
	void drawHUD(sf::RenderWindow& window);
	void moveInteractionHudClick(const sf::Vector2i&);
};
