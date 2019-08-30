#pragma once
#include <ctime>
#include <cstdlib>
#include "InteractableCube.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Scramble : public virtual InteractableCube {
private:
	sf::RectangleShape scrambleButton;
	void scrambleCube();
protected:
	Scramble();
public:
	void drawScrambleButton(sf::RenderWindow& window);
	void scrambleClick(const sf::Vector2i& mousePosition);
	virtual ~Scramble() = 0;

};

