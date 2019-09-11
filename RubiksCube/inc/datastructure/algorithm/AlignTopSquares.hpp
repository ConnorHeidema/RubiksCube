#pragma once
#include "AlgorithmStep.hpp"
class AlignTopSquares :
public AlgorithmStep {
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) override;
	void topSquaresPermutation(std::list<std::string>& stepsUsed, RubiksCube& cube);
};
