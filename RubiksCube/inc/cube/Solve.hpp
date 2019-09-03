#pragma once
#include "InteractableCube.hpp"
#include "..\Util.hpp"
#include "..\algorithm\AlignBottomSidesStep.hpp"
#include "..\algorithm\AlignBottomCornerStep.hpp"
#include "..\algorithm\AlignMiddleSidesStep.hpp"
#include "..\algorithm\AlignTopCross.hpp"
#include "..\algorithm\AlignTopSquares.hpp"
#include "..\algorithm\AlignTopCorners.hpp"
#include "..\algorithm\AlignFinalCornersFully.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
class Solve : public virtual InteractableCube {
private:
	void solveCube();

	class SolutionButton : public Button {
		friend class Solve;
		SolutionButton(Solve* solution, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Solve* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
	};

	class SolveButton : public Button {
		friend class Solve;
		SolveButton(Solve* solve, SolutionButton* solutionButton, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		Solve* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
		SolutionButton* solutionReference;
	};

	SolveButton* solveButtonPtr;
	SolutionButton* solutionButtonPtr;
protected:
	Solve();
public:
	std::list<std::string> moveList;
	virtual ~Solve() = 0;
};
