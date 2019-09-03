#include "..\..\inc\algorithm\AlignTopSquares.hpp"

bool AlignTopSquares::stepIsComplete(InteractableCube& cube) {
	if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
		cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
		cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
		return true;
	}
	return false;
}

std::list<std::string> AlignTopSquares::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list<std::string> stepsUsed;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				return stepsUsed;
			} else if (cube.cube[Cube::RIGHT_FACE][Cube::TOP] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
				topSquaresPermutation(stepsUsed, cube, maxMovesAllowed);
				if (!stepIsComplete(cube)) {
					stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
					topSquaresPermutation(stepsUsed, cube, maxMovesAllowed);
				}
				return stepsUsed;
			} else if (cube.cube[Cube::FRONT_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				topSquaresPermutation(stepsUsed, cube, maxMovesAllowed);
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
				topSquaresPermutation(stepsUsed, cube, maxMovesAllowed);
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
				return stepsUsed;
			}
			stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
		}
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateRightFront));
	}
	return std::list<std::string>();
}

void AlignTopSquares::topSquaresPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::topMove));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
}
