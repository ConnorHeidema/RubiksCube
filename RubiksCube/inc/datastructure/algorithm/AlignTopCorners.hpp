#pragma once
#include "AlgorithmStep.hpp"
class AlignTopCorners :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<Moves> makeMoves(RubiksCube& cube) override;
	void topCornerPermutation(std::list<Moves>& stepsUsed, RubiksCube& cube);
};

