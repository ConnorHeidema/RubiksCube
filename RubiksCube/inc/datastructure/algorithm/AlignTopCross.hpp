#pragma once
#include "AlgorithmStep.hpp"

class AlignTopCross : public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) override;
	void topCrossPermutation(std::list<std::string>& stepsUsed, RubiksCube& cube);
};
