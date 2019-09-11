#pragma once
#include "RubiksCube.hpp"
#include "algorithm/AlgorithmStep.hpp"
#include "algorithm/AlignBottomCornerStep.hpp"
#include "algorithm/AlignBottomSidesStep.hpp"
#include "algorithm/AlignFinalCornersFully.hpp"
#include "algorithm/AlignMiddleSidesStep.hpp"
#include "algorithm/AlignTopCorners.hpp"
#include "algorithm/AlignTopCross.hpp"
#include "algorithm/AlignTopSquares.hpp"
#include <functional>
class Solve {
	Moves getRotationChangedMove(Moves rotation, Moves oldMove);
	Moves getReverseMove(Moves move);
	void removeRotations(std::list<Moves>& movesList);
	bool removeBackForths(std::list<Moves>& movesList);
	bool reverseTriples(std::list<Moves>& movesList);
	bool removeQuadrouples(std::list<Moves>& movesList);
public:
	Solve();
	std::list<Moves> solveCube(RubiksCube* rubiks);
	void condenseSolvedList(std::list<Moves>& moveList);
};

