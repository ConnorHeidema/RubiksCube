#include "..\..\inc\algorithm\AlignBottomCornerStep.hpp"

bool AlignBottomCornerStep::stepIsComplete(InteractableCube& cube) {
	return false;
}

std::list<std::string> AlignBottomCornerStep::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	stepsUsed.emplace_back(performStep(cube, &InteractableCube::rotateTopFront));
	alignCorner(stepsUsed, cube, 1000,
		cube.cube[Cube::TOP_FACE][Cube::CENTRE],
		cube.cube[Cube::FRONT_FACE][Cube::CENTRE],
		cube.cube[Cube::RIGHT_FACE][Cube::CENTRE]);
	alignCorner(stepsUsed, cube, 1000,
		cube.cube[Cube::TOP_FACE][Cube::CENTRE],
		cube.cube[Cube::RIGHT_FACE][Cube::CENTRE],
		cube.cube[Cube::BACK_FACE][Cube::CENTRE]);
	alignCorner(stepsUsed, cube, 1000,
		cube.cube[Cube::TOP_FACE][Cube::CENTRE],
		cube.cube[Cube::BACK_FACE][Cube::CENTRE],
		cube.cube[Cube::LEFT_FACE][Cube::CENTRE]);
	alignCorner(stepsUsed, cube, 1000,
		cube.cube[Cube::TOP_FACE][Cube::CENTRE],
		cube.cube[Cube::LEFT_FACE][Cube::CENTRE],
		cube.cube[Cube::FRONT_FACE][Cube::CENTRE]);
	return stepsUsed;
}

void AlignBottomCornerStep::alignCorner(std::list<std::string>& stepsUsed,InteractableCube& cube, int maxMovesAllowed,
	const Cube::Color& firstColour, const Cube::Color& secondColour, const Cube::Color& thirdColour) {
	CornerCube cornerCube = findCorner(firstColour, secondColour, thirdColour);
}

CornerCube AlignBottomCornerStep::findCorner(const Cube::Color& firstColour, const Cube::Color& secondColour, const Cube::Color& thirdColour) {
	return CornerCube(1,1,1,1,1,1);
}
