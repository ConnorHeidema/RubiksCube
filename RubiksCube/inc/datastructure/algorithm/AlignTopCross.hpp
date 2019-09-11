#pragma once
#include "AlgorithmStep.hpp"

class AlignTopCross : public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<Moves> makeMoves(RubiksCube& cube) override;
	void topCrossPermutation(std::list<Moves>& stepsUsed, RubiksCube& cube);
};
