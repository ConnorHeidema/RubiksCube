#include "..\..\inc\algorithm\AlignBottomSidesStep.hpp"

bool AlignBottomSidesStep::stepIsComplete(InteractableCube& cube) {
	return false;
}

std::list<std::string> AlignBottomSidesStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	backTopCubeAlign(stepsUsed, cube, maxMovesAllowed);
	topTopCubeAlign(stepsUsed, cube, maxMovesAllowed);
	return stepsUsed;
}

void AlignBottomSidesStep::backTopCubeAlign(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed) {
	for (int backRotation = 0; backRotation < 4; backRotation++) {
		for (int rotation = 0; rotation < 4; rotation++) {
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
		stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
	}
}

void AlignBottomSidesStep::topTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {

}

void AlignBottomSidesStep::topRightCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}

void AlignBottomSidesStep::rightTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}

void AlignBottomSidesStep::topLeftCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}

void AlignBottomSidesStep::leftTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}

void AlignBottomSidesStep::frontTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}

void AlignBottomSidesStep::topBottomCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed) {
}
