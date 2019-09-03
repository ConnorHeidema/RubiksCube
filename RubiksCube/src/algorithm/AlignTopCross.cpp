#include "..\..\inc\algorithm\AlignTopCross.hpp"

bool AlignTopCross::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignTopCross::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		return stepsUsed;
	} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] != cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::LEFT] != cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::TOP] != cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM] != cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
		topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
		topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
	} else if (cube.cube[Cube::TOP_FACE][Cube::RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
	} else if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
	} else {
		for (int i = 0; i < 4; i++) {
			if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
				cube.cube[Cube::TOP_FACE][Cube::LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
				topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
				topCrossPermutation(stepsUsed, cube, maxMovesAllowed);
				return stepsUsed;
			}
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
		}
	}
	return stepsUsed;
}

void AlignTopCross::topCrossPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed = 1000) {
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
}
