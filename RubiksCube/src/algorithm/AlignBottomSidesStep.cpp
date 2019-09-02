#include "..\..\inc\algorithm\AlignBottomSidesStep.hpp"

bool AlignBottomSidesStep::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::BOTTOM] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::RIGHT_FACE][Cube::LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BOTTOM_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) return true;
	return false;
}

std::list<std::string> AlignBottomSidesStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	for (int backRotation = 0; backRotation < 4; backRotation++) {
		for (int rotation = 0; rotation < 4; rotation++) {
			bool cubePositioned = false;
			cubePositioned |= frontFaceTop(stepsUsed, cube, maxMovesAllowed) ||
			backFaceTop(stepsUsed, cube, maxMovesAllowed) ||
			rightFaceTop(stepsUsed, cube, maxMovesAllowed) ||
			leftFaceTop(stepsUsed, cube, maxMovesAllowed) ||
			topFaceTop(stepsUsed, cube, maxMovesAllowed) ||
			topFaceRight(stepsUsed, cube, maxMovesAllowed) ||
			topFaceLeft(stepsUsed, cube, maxMovesAllowed) ||
			topFaceBottom(stepsUsed, cube, maxMovesAllowed);
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateFrontFront));
			if (cubePositioned) {
				rotation = 0;
				backRotation = 0;
			}
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	}
	return stepsUsed;
}

bool AlignBottomSidesStep::frontFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::backFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::rightFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::leftFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			return true;
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			return true;
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceRight(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			return true;
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceLeft(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			return true;
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			return true;
		}
	}
	return false;
}

bool AlignBottomSidesStep::topFaceBottom(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			return true;
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			return true;
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			return true;
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			return true;
		}
	}
	return false;
}
