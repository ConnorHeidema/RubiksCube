#include "..\..\..\inc\datastructure\algorithm\AlignFinalCornersFully.hpp"

bool AlignFinalCornersFully::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM_LEFT] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[TOP_FACE][CENTER]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignFinalCornersFully::makeMoves(RubiksCube& cube) {
	std::list<std::string> stepsUsed;
	for (int i = 0; i < 4; i++) {
		while (cube.thisCube[TOP_FACE][BOTTOM_RIGHT] != cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
		}
		stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	}
	return stepsUsed;
}
