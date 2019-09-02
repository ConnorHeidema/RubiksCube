#pragma once
#include "..\cube\InteractableCube.hpp"
#include "../cube/Cube.hpp"
#include "list"
#include <string>
class AlgorithmStep {
public:
	virtual bool stepIsComplete(InteractableCube& cube) = 0;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 100) = 0;
	virtual std::string performStep(void(InteractableCube::* function)());
};
