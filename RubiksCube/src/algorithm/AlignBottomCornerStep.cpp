#include "..\..\inc\algorithm\AlignBottomCornerStep.hpp"

bool AlignBottomCornerStep::stepIsComplete(InteractableCube& cube) {
	return false;
}

std::list<std::string> AlignBottomCornerStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	bool cubeMoved = true;
	while (cubeMoved) {
		cubeMoved = alignCorner(stepsUsed, cube, 1000);
	}
	return stepsUsed;
}

bool AlignBottomCornerStep::alignCorner(std::list<std::string>& stepsUsed,InteractableCube& cube, int maxMovesAllowed) {
	if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
		cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE] ||
		cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
		if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				return true;
			} else if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				return true;
			} else if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				return true;
			}
		}

		if (cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				return true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::rightInverseMove));
				return true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::FRONT_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::frontInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				return true;
			} else if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE] &&
				cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE]) {
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::leftMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::backMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::bottomInverseMove));
				stepsUsed.emplace_back(performStep(cube, &InteractableCube::backInverseMove));
				return true;
			}
		}

		if (cube.cube[Cube::BACK_FACE][Cube::TOP_RIGHT] == cube.cube[Cube::TOP_FACE][Cube::CENTRE]) {
			//if (cube.cube[Cube::TOP_FACE][Cube::TOP_LEFT] == cube.cube[Cube::LEFT_FACE][Cube::CENTRE] &&
			//	cube.cube[Cube::LEFT_FACE][Cube::TOP_LEFT] == cube.cube[Cube::BACK_FACE][Cube::CENTRE]) {

			//}
		}
	}
	return false;
}
