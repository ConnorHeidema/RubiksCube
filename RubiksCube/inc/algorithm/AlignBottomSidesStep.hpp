#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
	bool frontFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool backFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool rightFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool leftFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool topFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool topFaceRight(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool topFaceLeft(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	bool topFaceBottom(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
public:
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
};
