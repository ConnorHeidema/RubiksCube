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
		new SolutionButton(this, 10, 650, 0, 35, 0, sf::Color::Transparent, sf::Color::Transparent, sf::Text(), sf::Font(), "No solution yet");
	solveButtonPtr =
		new SolveButton(this, solutionButtonPtr, 1700, 210, 200, 75, -5, sf::Color::Green, sf::Color::Magenta, sf::Text(), sf::Font(), "Solve");
	buttons.push_back(solveButtonPtr);
	buttons.push_back(solutionButtonPtr);
	stringToFunction = new std::map<std::string, void (InteractableCube::*)()>;
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Front", &InteractableCube::frontMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Right", &InteractableCube::rightMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Back", &InteractableCube::backMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Left", &InteractableCube::leftMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Top", &InteractableCube::topMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Bottom", &InteractableCube::bottomMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Front Inverse", &InteractableCube::frontInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Right Inverse", &InteractableCube::rightInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Back Inverse", &InteractableCube::backInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Left Inverse", &InteractableCube::leftInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Top Inverse", &InteractableCube::topInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Bottom Inverse", &InteractableCube::bottomInverseMove));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Right Front", &InteractableCube::rotateRightFront));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Top Front", &InteractableCube::rotateTopFront));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Front Front", &InteractableCube::rotateFrontFront));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Right Front Inverse", &InteractableCube::rotateRightFrontInverse));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Top Front Inverse", &InteractableCube::rotateTopFrontInverse));
	stringToFunction->insert(std::pair<std::string, void (InteractableCube::*)()>("Rotate Front Front Inverse", &InteractableCube::rotateFrontFrontInverse));
}

Solve::~Solve() {
	delete solveButtonPtr;
	delete solutionButtonPtr;
	delete stringToFunction;
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

	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			outerReference->tempCube[face][position] = outerReference->cube[face][position];
		}
	}
	outerReference->solved = false;
	outerReference->solveCube();
	std::string moveString;
	size_t currentMoveOffset = 0;
	int moveNumber = 1;
	for (const auto& move : outerReference->moveList) {
		currentMoveOffset += move.length() + std::to_string(moveNumber).size() + 3;
		if (currentMoveOffset > 200) {
			moveString += "\r\n";
			currentMoveOffset = 0;
		}
		moveString += std::to_string(moveNumber) + ":" + move + ", ";
		solutionReference->image.text.setString(moveString);
		moveNumber++;
	}
}

void Solve::SolveButton::rightButtonClicked() {
}

void Solve::SolveButton::update() {
	if (timeExpansion % timeExpansionCap == 0) {
		if (outerReference->solved == true) {
			return;
		} else if (outerReference->stepsGoneThrough > outerReference->moveList.size() - 1 || outerReference->moveList.size() == 0) {
			outerReference->solved = true;
			outerReference->stepsGoneThrough = 0;
		} else {
			if (outerReference->stepsGoneThrough == 0) {
				for (auto face = 0; face < Face::NUM_FACES; face++) {
					for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
						outerReference->cube[face][position] = outerReference->tempCube[face][position];
					}
				}
			}
			auto iter = outerReference->moveList.begin();
			for (int i = 0; i < outerReference->stepsGoneThrough; i++) {
				iter++;
			}
			((*outerReference).*(outerReference->stringToFunction->at(*iter)))();
			std::cout << "Moved " << *iter << " " << outerReference->stepsGoneThrough << std::endl;
			outerReference->stepsGoneThrough++;
		}
	}
	timeExpansion++;
}

Solve::SolutionButton::SolutionButton(Solve* solution, int xPosition, int yPosition, int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour, sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
}

void Solve::SolutionButton::leftButtonClicked() {
}

void Solve::SolutionButton::rightButtonClicked() {
}
