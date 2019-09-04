#include "..\..\inc\cube\Solve.hpp"

Solve::SolveButton::SolveButton(Solve* solve, SolutionButton* solutionButton, int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	solutionReference = solutionButton;
	outerReference = solve;
}

Solve::Solve() {
	solutionButtonPtr =
		new SolutionButton(this, 350, 650, 0, 44, 0, sf::Color::Transparent, sf::Color::Transparent, sf::Text(), sf::Font(), "No solution yet");
	solveButtonPtr =
		new SolveButton(this, solutionButtonPtr, 1700, 210, 200, 75, -5, sf::Color::Green, sf::Color::Magenta, sf::Text(), sf::Font(), "Solve");
	buttons.push_back(solveButtonPtr);
	buttons.push_back(solutionButtonPtr);
}

Solve::~Solve() {
	delete solveButtonPtr;
	delete solutionButtonPtr;
};

void Solve::solveCube() {
	this->moveList.clear();
	std::list<AlgorithmStep*> currentStep = {
		new AlignBottomSidesStep(),
		new AlignBottomCornerStep(),
		new AlignMiddleSidesStep(),
		new AlignTopCross(),
		new AlignTopSquares(),
		new AlignTopCorners(),
		new AlignFinalCornersFully()
	};
	Solve* cubePtr = this;
	std::for_each(currentStep.begin(), currentStep.end(), [&currentStep, &cubePtr](AlgorithmStep* step) {
		if (!step->stepIsComplete(*cubePtr)) {
			(cubePtr->moveList).splice((cubePtr->moveList).end(), step->makeMoves(*cubePtr));
		}
		std::cout << (step->stepIsComplete(*cubePtr) ? "Step successful\n" : "ERROR IN STEP\n");
		delete step;
		});
	CondenseCubeList condenseCubeList;
	condenseCubeList.condenseList(cubePtr->moveList);
}

void Solve::SolveButton::leftButtonClicked() {
	outerReference->solveCube();
	std::string moveString;
	size_t currentMoveOffset = 0;
	for (const auto& move : outerReference->moveList) {
		currentMoveOffset += move.length();
		if (currentMoveOffset > 100) {
			moveString += "\r\n";
			currentMoveOffset = 0;
		}
		moveString += move + ", ";
		solutionReference->image.text.setString(moveString);
	}
}

void Solve::SolveButton::rightButtonClicked() {
}

Solve::SolutionButton::SolutionButton(Solve* solution, int xPosition, int yPosition, int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
}

void Solve::SolutionButton::leftButtonClicked() {
}

void Solve::SolutionButton::rightButtonClicked() {
}
