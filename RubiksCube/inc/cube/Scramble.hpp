#pragma once
#include "InteractableCube.hpp"
#include "..\Util.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class Scramble : public virtual InteractableCube {
private:
	void scrambleCube();
	class ScrambleButton : public Button {
		friend class Scramble;
		ScrambleButton(Scramble* scramble, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Scramble* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
	};
protected:
	Scramble();
public:
	virtual ~Scramble() = 0;
};
