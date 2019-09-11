#include "..\..\..\inc\datastructure\algorithm\AlignTopCross.hpp"

bool AlignTopCross::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[TOP_FACE][CENTER]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignTopCross::makeMoves(RubiksCube& cube) {
	std::list <std::string> stepsUsed;
	if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[TOP_FACE][CENTER]) {
		return stepsUsed;
	} else if (cube.thisCube[TOP_FACE][RIGHT] != cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][LEFT] != cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][TOP] != cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM] != cube.thisCube[TOP_FACE][CENTER]) {
		topCrossPermutation(stepsUsed, cube);
		topCrossPermutation(stepsUsed, cube);
		stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
		topCrossPermutation(stepsUsed, cube);
	} else if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
		topCrossPermutation(stepsUsed, cube);
	} else if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[TOP_FACE][CENTER]) {
		stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
		topCrossPermutation(stepsUsed, cube);
	} else {
		for (int i = 0; i < 4; i++) {
			if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER] &&
				cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
				topCrossPermutation(stepsUsed, cube);
				topCrossPermutation(stepsUsed, cube);
				return stepsUsed;
			}
			stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
		}
	}
	return stepsUsed;
}

void AlignTopCross::topCrossPermutation(std::list<std::string>& stepsUsed, RubiksCube& cube) {
		stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
		stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
		stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
		stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
		stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
		stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
}
