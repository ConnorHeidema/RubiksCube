#pragma once
#include "Cube.hpp"
#include "..\Util.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>

class Drawable2DCube : public virtual Cube {
private:
	class SquareButton : public Button {
		friend class Drawable2DCube;
		Color* colour;
		SquareButton(Drawable2DCube* drawable2DCube, int face, int position, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Drawable2DCube* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
		Image getButtonImage() override;
	};

	const Color white = WHITE;
	SquareButton* squares[NUM_FACES][NUM_POSITIONS];
	const int SIZE = 50;
	const int OUTLINE_THICKNESS = -5;
	const sf::Color OUTLINE_COLOUR = sf::Color(32, 32, 32, 255);
	bool squareClicked = false;
protected:
	Drawable2DCube();
	int xFaceOffset(int face, const int& SIZE);
	int yFaceOffset(int face, const int& SIZE);
	int xPositionOffset(int position, const int& SIZE);
	int yPositionOffset(int position, const int& SIZE);

public:
	virtual ~Drawable2DCube() = 0;
};
