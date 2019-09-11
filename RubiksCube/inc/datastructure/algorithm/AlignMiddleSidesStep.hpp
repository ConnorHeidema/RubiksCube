#pragma once
#include "AlgorithmStep.hpp"

class AlignMiddleSidesStep :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<Moves> makeMoves(RubiksCube& cube) override;
	void topRight(std::list<Moves>&, RubiksCube& cube);
	void topLeft(std::list<Moves>&, RubiksCube& cube);
};
