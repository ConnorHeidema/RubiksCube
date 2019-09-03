#pragma once
#include "AlgorithmStep.hpp"
class AlignTopCorners :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
	void topCornerPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed);
};

