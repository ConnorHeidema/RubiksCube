#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
	bool frontFaceTop(std::list<Moves>&, RubiksCube& cube);
	bool backFaceTop(std::list<Moves>&, RubiksCube& cube);
	bool rightFaceTop(std::list<Moves>&, RubiksCube& cube);
	bool leftFaceTop(std::list<Moves>&, RubiksCube& cube);
	bool topFaceTop(std::list<Moves>&, RubiksCube& cube);
	bool topFaceRight(std::list<Moves>&, RubiksCube& cube);
	bool topFaceLeft(std::list<Moves>&, RubiksCube& cube);
	bool topFaceBottom(std::list<Moves>&, RubiksCube& cube);
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<Moves> makeMoves(RubiksCube& cube) override;
};
