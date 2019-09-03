#pragma once
#include "AlgorithmStep.hpp"
class AlignFinalCornersFully :
	public AlgorithmStep {
	virtual bool stepIsComplete(InteractableCube & cube) override;
	virtual  std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed) override;
};
