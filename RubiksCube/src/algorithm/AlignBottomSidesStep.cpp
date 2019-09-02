#include "..\..\inc\algorithm\AlignBottomSidesStep.hpp"

bool AlignBottomSidesStep::stepIsComplete(InteractableCube& cube) {
	return false;
}

/**
 * This part of the algorithm will specifically get the side cubes adjacent to the center front cube in
 * correct position
 */
std::list<std::string> AlignBottomSidesStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	for (int rotation = 0; rotation < 4; rotation++) {
		if (cube.cube[Cube::BACK_FACE][Cube::TOP] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::TOP_FACE][Cube::TOP] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
				cube.topMove();
				cube.topMove();
				stepsUsed.emplace_back("top");
				stepsUsed.emplace_back("top");
			} else if (cube.cube[Cube::RIGHT_FACE][Cube::RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {

			} else if (cube.cube[Cube::BOTTOM_FACE][Cube::BOTTOM] == cube.cube[Cube::BOTTOM_FACE][Cube::CENTRE]) {

			} else if (cube.cube[Cube::LEFT_FACE][Cube::TOP] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {

			}
			rotation = 0;
		}
	}
	return stepsUsed;
}
