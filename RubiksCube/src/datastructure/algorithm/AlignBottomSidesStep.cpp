#include "..\..\..\inc\datastructure\algorithm\AlignBottomSidesStep.hpp"

bool AlignBottomSidesStep::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][RIGHT] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][BOTTOM] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[TOP_FACE][CENTER] &&
		cube.thisCube[RIGHT_FACE][LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[BOTTOM_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][RIGHT] == cube.thisCube[LEFT_FACE][CENTER]) return true;
	return false;
}

std::list<Moves> AlignBottomSidesStep::makeMoves(RubiksCube& cube) {
	std::list <Moves> stepsUsed;
	for (int backRotation = 0; backRotation < 4; backRotation++) {
		for (int rotation = 0; rotation < 4; rotation++) {
			bool cubePositioned = false;
			cubePositioned |= frontFaceTop(stepsUsed, cube) ||
			backFaceTop(stepsUsed, cube) ||
			rightFaceTop(stepsUsed, cube) ||
			leftFaceTop(stepsUsed, cube) ||
			topFaceTop(stepsUsed, cube) ||
			topFaceRight(stepsUsed, cube) ||
			topFaceLeft(stepsUsed, cube) ||
			topFaceBottom(stepsUsed, cube);
			stepsUsed.emplace_back(performStep(cube, ROTATE_FRONT_FRONT));
			if (cubePositioned) {
				rotation = 0;
				backRotation = 0;
			}
		}
		stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	}
	return stepsUsed;
}

bool AlignBottomSidesStep::frontFaceTop(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::backFaceTop(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[BACK_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::rightFaceTop(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::leftFaceTop(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceTop(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][TOP] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[BACK_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[BACK_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[BACK_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		} else if (cube.thisCube[BACK_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceRight(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][RIGHT] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[RIGHT_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceLeft(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][LEFT] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			return true;
		} else if (cube.thisCube[LEFT_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceBottom(std::list<Moves>& stepsUsed, RubiksCube& cube) {
	if (cube.thisCube[TOP_FACE][BOTTOM] == cube.thisCube[FRONT_FACE][CENTER]) {
		if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[TOP_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			return true;
		} else if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[BOTTOM_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			return true;
		} else if (cube.thisCube[FRONT_FACE][TOP] == cube.thisCube[LEFT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, TOP_MOVE));
			stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
			stepsUsed.emplace_back(performStep(cube, TOP_INVERSE_MOVE));
			return true;
		}
	}
	return false;
}
