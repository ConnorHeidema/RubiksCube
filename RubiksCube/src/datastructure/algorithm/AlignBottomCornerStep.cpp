#include "..\..\..\inc\datastructure\algorithm\AlignBottomCornerStep.hpp"

bool AlignBottomCornerStep::stepIsComplete(RubiksCube& cube) {
	if (cube.thisCube[FRONT_FACE][BOTTOM_LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][BOTTOM] == cube.thisCube[FRONT_FACE][CENTER] &&
		cube.thisCube[FRONT_FACE][BOTTOM_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] && 
		cube.thisCube[RIGHT_FACE][BOTTOM_LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[RIGHT_FACE][BOTTOM] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[RIGHT_FACE][BOTTOM_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][BOTTOM_LEFT] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][BOTTOM_RIGHT] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[BACK_FACE][BOTTOM_LEFT] == cube.thisCube[BACK_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][BOTTOM_LEFT] == cube.thisCube[LEFT_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][BOTTOM] == cube.thisCube[LEFT_FACE][CENTER] &&
		cube.thisCube[LEFT_FACE][BOTTOM_RIGHT] == cube.thisCube[LEFT_FACE][CENTER] &&
		cube.thisCube[BOTTOM_FACE][TOP_LEFT] == cube.thisCube[BOTTOM_FACE][CENTER] &&
		cube.thisCube[BOTTOM_FACE][TOP_RIGHT] == cube.thisCube[BOTTOM_FACE][CENTER] &&
		cube.thisCube[BOTTOM_FACE][BOTTOM_LEFT] == cube.thisCube[BOTTOM_FACE][CENTER] &&
		cube.thisCube[BOTTOM_FACE][BOTTOM_RIGHT] == cube.thisCube[BOTTOM_FACE][CENTER]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignBottomCornerStep::makeMoves(RubiksCube& cube) {
	std::list <std::string> stepsUsed;
	stepsUsed.emplace_back(performStep(cube, ROTATE_TOP_FRONT_INVERSE));
	for (int rotations = 0; rotations < 5; rotations++) {
		bool cubeMoved = false;
		cubeMoved = alignCorner(stepsUsed, cube);
		if (cubeMoved) {
			rotations = 0;
		}
		stepsUsed.emplace_back(performStep(cube, ROTATE_RIGHT_FRONT));
	}
	stepsUsed.emplace_back(performStep(cube, ROTATE_TOP_FRONT));
	stepsUsed.emplace_back(performStep(cube, ROTATE_TOP_FRONT));
	return stepsUsed;
}

bool AlignBottomCornerStep::alignCorner(std::list<std::string>& stepsUsed,RubiksCube& cube) {
	bool piecesMoved = false;
	if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER] ||
		cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER] ||
		cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
		if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
			if (cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[BACK_FACE][CENTER]) {
				movements1(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER]) {
				movements2(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[LEFT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER]) {
				movements3(stepsUsed, cube);
				piecesMoved = true;
			}
		}

		if (cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[TOP_FACE][CENTER]) {
			if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[LEFT_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER]) {
				movements4(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[BACK_FACE][CENTER]) {
				movements5(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) {
				movements6(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[BACK_FACE][CENTER] &&
				cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[LEFT_FACE][CENTER]) {
				movements7(stepsUsed, cube);
				piecesMoved = true;
			}
		}

		if (cube.thisCube[BACK_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER]) {
			if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[LEFT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[BACK_FACE][CENTER]) {
				movements8(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[LEFT_FACE][CENTER]) {
				movements9(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[FRONT_FACE][CENTER]) {
				movements10(stepsUsed, cube);
				piecesMoved = true;
			} else if (cube.thisCube[TOP_FACE][TOP_LEFT] == cube.thisCube[BACK_FACE][CENTER] &&
				cube.thisCube[LEFT_FACE][TOP_LEFT] == cube.thisCube[RIGHT_FACE][CENTER]) {
				movements11(stepsUsed, cube);
				piecesMoved = true;
			}
		}
	}

	for (int bottomRotation = 0; bottomRotation < 4; bottomRotation++) {
		if (cube.thisCube[FRONT_FACE][BOTTOM_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER] &&
			cube.thisCube[RIGHT_FACE][BOTTOM_LEFT] == cube.thisCube[FRONT_FACE][CENTER] &&
			cube.thisCube[BOTTOM_FACE][TOP_RIGHT] == cube.thisCube[TOP_FACE][CENTER]) {
			// this
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
			piecesMoved = true;
		} else if (cube.thisCube[FRONT_FACE][BOTTOM_RIGHT] == cube.thisCube[TOP_FACE][CENTER] &&
			cube.thisCube[RIGHT_FACE][BOTTOM_LEFT] == cube.thisCube[RIGHT_FACE][CENTER] &&
			cube.thisCube[BOTTOM_FACE][TOP_RIGHT] == cube.thisCube[FRONT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
			piecesMoved = true;
		} else if (cube.thisCube[FRONT_FACE][BOTTOM_RIGHT] == cube.thisCube[FRONT_FACE][CENTER] &&
			cube.thisCube[RIGHT_FACE][BOTTOM_LEFT] == cube.thisCube[TOP_FACE][CENTER] &&
			cube.thisCube[BOTTOM_FACE][TOP_RIGHT] == cube.thisCube[RIGHT_FACE][CENTER]) {
			stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
			stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
			stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
			stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
			piecesMoved = true;
		}
		stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	}
	return piecesMoved;
}

void AlignBottomCornerStep::movements1(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}

void AlignBottomCornerStep::movements2(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}

void AlignBottomCornerStep::movements3(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}

void AlignBottomCornerStep::movements4(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
}

void AlignBottomCornerStep::movements5(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
}

void AlignBottomCornerStep::movements6(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}

void AlignBottomCornerStep::movements7(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
}

void AlignBottomCornerStep::movements8(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, LEFT_MOVE));
}

void AlignBottomCornerStep::movements9(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, FRONT_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
}

void AlignBottomCornerStep::movements10(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, RIGHT_MOVE));
}

void AlignBottomCornerStep::movements11(std::list<std::string>& stepsUsed, RubiksCube& cube) {
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_INVERSE_MOVE));
	stepsUsed.emplace_back(performStep(cube, BOTTOM_MOVE));
	stepsUsed.emplace_back(performStep(cube, BACK_MOVE));
}
