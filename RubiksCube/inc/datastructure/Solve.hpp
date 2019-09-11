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
class Solve {
	Solve();
	std::list<Moves> solveCube(RubiksCube* rubiks);
};

