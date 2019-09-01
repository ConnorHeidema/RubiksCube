#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
	virtual bool stepIsComplete(Cube& cube) override;
	virtual int makeMoves(Cube& cube, int maxMovesAllowed = 100) override;
};

