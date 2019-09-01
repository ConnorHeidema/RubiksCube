#pragma once
#include "..\cube\Cube.hpp"
class AlgorithmStep {
	virtual bool stepIsComplete(Cube& cube) = 0;
	virtual int makeMoves(Cube& cube, int maxMovesAllowed = 100) = 0;
};
