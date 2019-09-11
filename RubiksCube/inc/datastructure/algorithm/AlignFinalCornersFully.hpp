#pragma once
#include "AlgorithmStep.hpp"
class AlignFinalCornersFully :
	public AlgorithmStep {
	virtual bool stepIsComplete(RubiksCube & cube) override;
	virtual  std::list<Moves> makeMoves(RubiksCube& cube) override;
};
