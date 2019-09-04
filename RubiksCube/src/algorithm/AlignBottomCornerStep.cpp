#include "..\..\inc\algorithm\AlignBottomCornerStep.hpp"

bool AlignBottomCornerStep::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::FRONT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::BOTTOM] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] && 
		cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::BOTTOM] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BOTTOM_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BOTTOM_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BOTTOM_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BOTTOM_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignBottomCornerStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFrontInverse));
	for (int rotations = 0; rotations < 5; rotations++) {
		bool cubeMoved = false;
		cubeMoved = alignCorner(stepsUsed, cube, 1000);
		if (cubeMoved) {
			rotations = 0;
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
	}
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	return stepsUsed;
}

bool AlignBottomCornerStep::alignCorner(std::list<std::string>& stepsUsed,InteractableCube& cube, int maxMovesAllowed) {
	bool piecesMoved = false;
	if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
		cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
		cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				movements1(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
				movements2(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				movements3(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			}
		}

		if (cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				movements4(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				movements5(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
				movements6(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
				movements7(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			}
		}

		if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				movements8(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
				movements9(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				movements10(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
				movements11(stepsUsed, cube, maxMovesAllowed);
				piecesMoved = true;
			}
		}
	}

	for (int bottomRotation = 0; bottomRotation < 4; bottomRotation++) {
		if (cube.cube[Cube::FRONT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
			cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
			cube.cube[Cube::BOTTOM_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			// this
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
			piecesMoved = true;
		} else if (cube.cube[Cube::FRONT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
			cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
			cube.cube[Cube::BOTTOM_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			piecesMoved = true;
		} else if (cube.cube[Cube::FRONT_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
			cube.cube[Cube::RIGHT_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
			cube.cube[Cube::BOTTOM_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
			piecesMoved = true;
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	}
	return piecesMoved;
}

void AlignBottomCornerStep::movements1(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}

void AlignBottomCornerStep::movements2(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}

void AlignBottomCornerStep::movements3(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}

void AlignBottomCornerStep::movements4(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
}

void AlignBottomCornerStep::movements5(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
}

void AlignBottomCornerStep::movements6(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}

void AlignBottomCornerStep::movements7(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
}

void AlignBottomCornerStep::movements8(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}

void AlignBottomCornerStep::movements9(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
}

void AlignBottomCornerStep::movements10(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
}

void AlignBottomCornerStep::movements11(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
}
