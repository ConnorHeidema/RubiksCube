#pragma once
#include "InteractableCube.hpp"
#include "Util.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class Scramble : public virtual InteractableCube {
private:
	bool scrambleClicked;
	sf::RectangleShape scrambleButton;
	sf::Text text;
	sf::Font font;
	void scrambleCube();
protected:
	Scramble();
public:
	void drawScrambleButton(sf::RenderWindow& window);
	void scrambleClick(const sf::Vector2i& mousePosition);
	virtual ~Scramble() = 0;

};

