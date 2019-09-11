#pragma once
#include "AlgorithmStep.hpp"

class AlignMiddleSidesStep :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) override;
	void topRight(std::list<std::string>&, RubiksCube& cube);
	void topLeft(std::list<std::string>&, RubiksCube& cube);
};
