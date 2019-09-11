#include "..\..\..\inc\datastructure\algorithm\AlignMiddleSidesStep.hpp"

bool AlignMiddleSidesStep::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[FRONT_FACE][RIGHT] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[RIGHT_FACE][RIGHT] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[RIGHT_FACE][LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][RIGHT] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][LEFT] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][RIGHT] == cube.thisCube[LEFT_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][LEFT] == cube.thisCube[LEFT_FACE][CENTER]) {
		return true;
	}
	return false;
}

std::list<Moves> AlignMiddleSidesStep::makeMoves(RubiksCube& cube) {
	std::list <Moves> stepsUsed;
	for (int i = 0; i < 4; i++) {
		if (cube.thisCube[FRONT_FACE][RIGHT] != cube.thisCube[TOP_FACE][CENTER] &&
			cube.thisCube[RIGHT_FACE][LEFT] != cube.thisCube[TOP_FACE][CENTER]) {
			for (int j = 0; j < 4; j++) {
				if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[TOP_FACE][CENTER] ||
					cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
					topRight(stepsUsed, cube);
					break;
				}		
				stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			}
		}
		stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
				if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[RIGHT_FACE][CENTER]) {
					topRight(stepsUsed, cube);
				} else if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[LEFT_FACE][CENTER]) {
					topLeft(stepsUsed, cube);
				}
			}
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
		}
		stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
	}
	return stepsUsed;
}

void AlignMiddleSidesStep::topRight(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
}

void AlignMiddleSidesStep::topLeft(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
}

