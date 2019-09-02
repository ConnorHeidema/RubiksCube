#include "..\..\inc\algorithm\AlignBottomSidesStep.hpp"

bool AlignBottomSidesStep::stepIsComplete(InteractableCube& cube) {
	return false;
}

std::list<std::string> AlignBottomSidesStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	orientation1Steps(stepsUsed, cube, maxMovesAllowed);
	orientation2Steps(stepsUsed, cube, maxMovesAllowed);
	return stepsUsed;
}

void AlignBottomSidesStep::orientation1Steps(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	for (int backRotation = 0; backRotation < 4; backRotation++) {
		for (int rotation = 0; rotation < 4; rotation++) {
			frontFaceTop(stepsUsed, cube, maxMovesAllowed);
			backFaceTop(stepsUsed, cube, maxMovesAllowed);
			rightFaceTop(stepsUsed, cube, maxMovesAllowed);
			leftFaceTop(stepsUsed, cube, maxMovesAllowed);
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateFrontFront));
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	}
}

void AlignBottomSidesStep::orientation2Steps(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	for (int backRotation = 0; backRotation < 4; backRotation++) {
		for (int rotation = 0; rotation < 4; rotation++) {
			topFaceTop(stepsUsed, cube, maxMovesAllowed);
			topFaceRight(stepsUsed, cube, maxMovesAllowed);
			topFaceLeft(stepsUsed, cube, maxMovesAllowed);
			topFaceBottom(stepsUsed, cube, maxMovesAllowed);
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateFrontFront));
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	}
}

void AlignBottomSidesStep::frontFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		}
	}
}

void AlignBottomSidesStep::backFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		}
	}
}

void AlignBottomSidesStep::rightFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		}
	}
}

void AlignBottomSidesStep::leftFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		}
	}
}

void AlignBottomSidesStep::topFaceTop(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		} else if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		}
	}
}

void AlignBottomSidesStep::topFaceRight(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		}
	}
}

void AlignBottomSidesStep::topFaceLeft(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
		}
	}
}

void AlignBottomSidesStep::topFaceBottom(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
		} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
		}
	}
}
