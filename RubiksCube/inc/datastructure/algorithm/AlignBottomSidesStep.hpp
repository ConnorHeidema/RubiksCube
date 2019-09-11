#pragma once
#include "AlgorithmStep.hpp"

class AlignBottomSidesStep :
	public AlgorithmStep {
	bool frontFaceTop(std::list<std::string>&, RubiksCube& cube);
	bool backFaceTop(std::list<std::string>&, RubiksCube& cube);
	bool rightFaceTop(std::list<std::string>&, RubiksCube& cube);
	bool leftFaceTop(std::list<std::string>&, RubiksCube& cube);
	bool topFaceTop(std::list<std::string>&, RubiksCube& cube);
	bool topFaceRight(std::list<std::string>&, RubiksCube& cube);
	bool topFaceLeft(std::list<std::string>&, RubiksCube& cube);
	bool topFaceBottom(std::list<std::string>&, RubiksCube& cube);
public:
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual std::list<std::string> makeMoves(RubiksCube& cube) override;
};
