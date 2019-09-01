#pragma once
#include "AlgorithmStep.hpp"
class AlignBottomCornerStep :
	public AlgorithmStep {
	virtual bool stepIsComplete(Cube& cube) override;
	virtual int makeMoves(Cube& cube, int maxMovesAllowed) override;
};

