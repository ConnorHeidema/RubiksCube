#pragma once
#include "AlgorithmStep.hpp"
class AlignTopSquares :
public AlgorithmStep {
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
	void topSquaresPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed);
};
