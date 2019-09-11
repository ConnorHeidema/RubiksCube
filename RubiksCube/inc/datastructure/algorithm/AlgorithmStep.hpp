#pragma once
#include "../RubiksCube.hpp"
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class AlgorithmStep {
public:
	virtual ~AlgorithmStep() = 0;
	virtual bool stepIsComplete(RubiksCube& cube) = 0;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) = 0;
	std::string performStep(RubiksCube& cube, Moves move);
};
