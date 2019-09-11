#include "..\..\..\inc\datastructure\algorithm\AlignTopSquares.hpp"

bool AlignTopSquares::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][TOP] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		return true;
	}
	return false;
}

std::list<Moves> AlignTopSquares::makeMoves(RubiksCube& cube) {
	std::list<Moves> stepsUsed;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP] == cube.thisCube[BACK_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER] &&
				cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
				return stepsUsed;
			} else if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[BACK_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
				topSquaresPermutation(stepsUsed, cube);
				if (!stepIsComplete(cube)) {
					stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
					topSquaresPermutation(stepsUsed, cube);
				}
				return stepsUsed;
			} else if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP] == cube.thisCube[BACK_FACE][CENTER]) {
				topSquaresPermutation(stepsUsed, cube);
				stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
				topSquaresPermutation(stepsUsed, cube);
				stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
				stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
				return stepsUsed;
			}
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
		}
		stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
	}
	return std::list<Moves>();
}

void AlignTopSquares::topSquaresPermutation(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
}
