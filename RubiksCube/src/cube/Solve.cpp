#include "..\..\inc\cube\Solve.hpp"

Solve::SolveButton::SolveButton(Solve* solve, int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = solve;
}


Solve::Solve() {
	solveButtonPtr =
		new SolveButton(this, 1610, 260, 200, 75, -5, sf::Color::Green, sf::Color::Magenta, sf::Text(), sf::Font(), "Solve");
	buttons.push_back(solveButtonPtr);
}

Solve::~Solve() {
	delete solveButtonPtr;
};

void Solve::solveCube() {
	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			cube[face][position] = static_cast<Color>(face);
		}
	}
}

void Solve::SolveButton::leftButtonClicked() {
	outerReference->solveCube();
}

void Solve::SolveButton::rightButtonClicked() {
}
