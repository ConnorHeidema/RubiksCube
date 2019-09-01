#pragma once
#include "Cube.hpp"
#include "..\Util.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class Solve : public virtual Cube {
private:
	void solveCube();
	class SolveButton : public Button {
		friend class Solve;
		SolveButton(Solve* solve, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Solve* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
	};
	SolveButton* solveButtonPtr;
protected:
	Solve();
public:
	virtual ~Solve() = 0;
};
