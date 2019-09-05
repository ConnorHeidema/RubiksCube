#include "..\..\inc\algorithm\AlignMiddleSidesStep.hpp"

bool AlignMiddleSidesStep::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::FRONT_FACE][Cube::RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::RIGHT_FACE][Cube::RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::RIGHT_FACE][Cube::LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::RIGHT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignMiddleSidesStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	for (int i = 0; i < 4; i++) {
		if (cube.cube[Cube::FRONT_FACE][Cube::RIGHT] != cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
			cube.cube[Cube::RIGHT_FACE][Cube::LEFT] != cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			for (int j = 0; j < 4; j++) {
				if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
					cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
					topRight(stepsUsed, cube, 1000);
					break;
				}		
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
			}
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
					topRight(stepsUsed, cube, 1000);
				} else if (cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
					topLeft(stepsUsed, cube, 1000);
				}
			}
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
	}
	return stepsUsed;
}

void AlignMiddleSidesStep::topRight(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
}

void AlignMiddleSidesStep::topLeft(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
}

