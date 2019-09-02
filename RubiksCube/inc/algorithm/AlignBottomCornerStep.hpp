#pragma once
#include "AlgorithmStep.hpp"
class AlignBottomCornerStep :
	public AlgorithmStep {
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual  std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed) override;
	void alignCorner(std::list<std::string>& , InteractableCube& cube, int maxMovesAllowed, const Cube::Color& firstColour, const Cube::Color& secondColour, const Cube::Color& thirdColour);
};
