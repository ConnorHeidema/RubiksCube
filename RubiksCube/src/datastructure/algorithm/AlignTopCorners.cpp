#include "..\..\..\inc\datastructure\algorithm\AlignTopCorners.hpp"

bool AlignTopCorners::stepIsComplete(RubiksCube& cube) {
	int cornersCompleted = 0;
	for (int i = 0; i < 4; i++) {
		if ((cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
			cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] ||
			cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) &&
			(cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
			cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] ||
			cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) &&
			(cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER] ||
			cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER] ||
			cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER])) {
			cornersCompleted++;
		}
		cube.rotateRightFront();
	}
	return cornersCompleted == 4;
}

std::list<std::string> AlignTopCorners::makeMoves(RubiksCube& cube) {

	std::list<std::string> stepsUsed;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			if ((cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
				cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] ||
				cube.thisCube[FRONT_FACE][TOP_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) &&
				(cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
					cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] ||
					cube.thisCube[TOP_FACE][BOTTOM_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) &&
					(cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER] ||
						cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER] ||
						cube.thisCube[RIGHT_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER])) {
				for (int j = 0; j < 4; j++) {
					if ((cube.thisCube[FRONT_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER] ||
						cube.thisCube[FRONT_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER] ||
						cube.thisCube[FRONT_FACE][TOP_LEFT] == cube.thisCube[LEFT_FACE][CENTER]) &&
						(cube.thisCube[TOP_FACE][BOTTOM_LEFT] == cube.thisCube[TOP_FACE][CENTER] ||
							cube.thisCube[TOP_FACE][BOTTOM_LEFT] == cube.thisCube[FRONT_FACE][CENTER] ||
							cube.thisCube[TOP_FACE][BOTTOM_LEFT] == cube.thisCube[LEFT_FACE][CENTER]) &&
							(cube.thisCube[LEFT_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
								cube.thisCube[LEFT_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] ||
								cube.thisCube[LEFT_FACE][TOP_RIGHT] == cube.thisCube[LEFT_FACE][CENTER])) {
						return stepsUsed;
					}
					topCornerPermutation(stepsUsed, cube);
				}
			}
			stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
		}
		topCornerPermutation(stepsUsed, cube);
	}
	return stepsUsed;
}

void AlignTopCorners::topCornerPermutation(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}
