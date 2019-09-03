#include "..\..\inc\algorithm\AlignTopCorners.hpp"

bool AlignTopCorners::stepIsComplete(InteractableCube& cube) {
	int cornersCompleted = 0;
	for (int i = 0; i < 4; i++) {
		if ((cube.cube[Cube::FRONT_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
			cube.cube[Cube::FRONT_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] ||
			cube.cube[Cube::FRONT_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) &&
			(cube.cube[Cube::TOP_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
			cube.cube[Cube::TOP_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] ||
			cube.cube[Cube::TOP_FACE][Cube::BOTTOM_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) &&
			(cube.cube[Cube::RIGHT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
			cube.cube[Cube::RIGHT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] ||
			cube.cube[Cube::RIGHT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE])) {
			cornersCompleted++;
		}
		cube.rotateRightFront();
	}
	return cornersCompleted == 4;
}

std::list<std::string> AlignTopCorners::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	return std::list<std::string>();
}

void AlignTopCorners::topCornerPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
}
