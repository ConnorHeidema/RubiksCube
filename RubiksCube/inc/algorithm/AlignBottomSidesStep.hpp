#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
public:
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
	void backTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topRightCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void rightTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topLeftCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void leftTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void frontTopCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topBottomCubeAlign(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
};

