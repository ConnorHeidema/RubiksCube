#include "../../../inc/datastructure/algorithm/AlgorithmStep.hpp"

AlgorithmStep::~AlgorithmStep() {
}

Moves AlgorithmStep::performStep(RubiksCube& cube, Moves move) {
	cube.performFunction(move);
	return move;
}
