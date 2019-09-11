#pragma once
#include "AlgorithmStep.hpp"
class AlignTopSquares :
public AlgorithmStep {
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<Moves> makeMoves(RubiksCube& cube) override;
	void topSquaresPermutation(std::list<Moves>& stepsUsed, RubiksCube& cube);
};
