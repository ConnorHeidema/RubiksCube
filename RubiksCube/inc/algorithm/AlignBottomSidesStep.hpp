#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
	void orientation1Steps(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void orientation2Steps(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void frontFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void backFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void rightFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void leftFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topFaceTop(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topFaceRight(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topFaceLeft(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
	void topFaceBottom(std::list<std::string>&, InteractableCube& cube, int maxMovesAllowed = 1000);
public:
	virtual bool stepIsComplete(InteractableCube& cube) override;
	virtual std::list<std::string> makeMoves(InteractableCube& cube, int maxMovesAllowed = 1000) override;
};
