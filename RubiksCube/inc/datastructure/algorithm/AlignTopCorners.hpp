#pragma once
#include "AlgorithmStep.hpp"
class AlignTopCorners :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) override;
	void topCornerPermutation(std::list<std::string>& stepsUsed, RubiksCube& cube);
};

