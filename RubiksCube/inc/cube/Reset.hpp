#pragma once
#include "InteractableCube.hpp"
#include "..\Util.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class Reset : public virtual InteractableCube {
private:
	void resetCube();
	class ResetButton : public Button {
		friend class Reset;
		ResetButton(Reset* reset, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Reset* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
	};
	ResetButton* resetButtonPtr;
protected:
	Reset();
public:
	virtual ~Reset() = 0;
};
