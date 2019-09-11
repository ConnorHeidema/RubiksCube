#include "..\..\inc\datastructure\Solve.hpp"

Solve::Solve() {
}

std::list<Moves> Solve::solveCube(RubiksCube* rubiks) {
	std::list<Moves> moveList;
	std::list<AlgorithmStep*> currentStep = {
		new AlignBottomSidesStep(),
		new AlignBottomCornerStep(),
		new AlignMiddleSidesStep(),
		new AlignTopCross(),
		new AlignTopSquares(),
		new AlignTopCorners(),
		new AlignFinalCornersFully()
	};

	std::for_each(currentStep.begin(), currentStep.end(), [&moveList, &currentStep, &rubiks](AlgorithmStep* step) {
		if (!step->stepIsComplete(*rubiks)) {
			moveList.splice((moveList).end(), step->makeMoves(*rubiks));
		}
		std::cout << (step->stepIsComplete(*rubiks) ? "Step successful\n" : "ERROR IN STEP\n");
		delete step;
		});
	return moveList;
}
