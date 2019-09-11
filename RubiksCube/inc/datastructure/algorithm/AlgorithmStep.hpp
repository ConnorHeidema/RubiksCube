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
	virtual std::list<Moves> makeMoves(RubiksCube& cube) = 0;
	Moves performStep(RubiksCube& cube, Moves move);
};
