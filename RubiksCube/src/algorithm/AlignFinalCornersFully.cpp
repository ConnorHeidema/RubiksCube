#include "..\..\inc\algorithm\AlignFinalCornersFully.hpp"

bool AlignFinalCornersFully::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] &&
		cube.cube[Cube::TOP_FACE][Cube::BOTTOM_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignFinalCornersFully::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list<std::string> stepsUsed;
	for (int i = 0; i < 4; i++) {
		while (cube.cube[Cube::TOP_FACE][Cube::BOTTOM_RIGHT] != cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	}
	return stepsUsed;
}
