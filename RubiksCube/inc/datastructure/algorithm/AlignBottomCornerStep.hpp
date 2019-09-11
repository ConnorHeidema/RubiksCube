#pragma once
#include "AlgorithmStep.hpp"
class AlignBottomCornerStep :
	public AlgorithmStep {
	virtual bool stepIsComplete(RubiksCube& cube) override;
	virtual  std::list<Moves> makeMoves(RubiksCube& cube) override;
	bool alignCorner(std::list<Moves>& , RubiksCube& cube);

	void movements1(std::list<Moves>&, RubiksCube& cube);
	void movements2(std::list<Moves>&, RubiksCube& cube);
	void movements3(std::list<Moves>&, RubiksCube& cube);
	void movements4(std::list<Moves>&, RubiksCube& cube);
	void movements5(std::list<Moves>&, RubiksCube& cube);
	void movements6(std::list<Moves>&, RubiksCube& cube);
	void movements7(std::list<Moves>&, RubiksCube& cube);
	void movements8(std::list<Moves>&, RubiksCube& cube);
	void movements9(std::list<Moves>&, RubiksCube& cube);
	void movements10(std::list<Moves>&, RubiksCube& cube);
	void movements11(std::list<Moves>&, RubiksCube& cube);
};
