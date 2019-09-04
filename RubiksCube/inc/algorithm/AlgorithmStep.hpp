#pragma once
#include "..\cube\InteractableCube.hpp"
#include "../cube/Cube.hpp"
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class AlgorithmStep {
public:
	virtual ~AlgorithmStep() = 0;
	virtual bool stepIsComplete(InteractableCube& cube) = 0;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 100) = 0;
	std::string performStep(InteractableCube& cube, void(InteractableCube::* function)());
};
