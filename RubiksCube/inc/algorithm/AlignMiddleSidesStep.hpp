#pragma once
#include "AlgorithmStep.hpp"

class AlignMiddleSidesStep :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
	void topRight(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topLeft(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
};
