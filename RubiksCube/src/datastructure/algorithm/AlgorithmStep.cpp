#include "../../../inc/datastructure/algorithm/AlgorithmStep.hpp"

AlgorithmStep::~AlgorithmStep() {
}

std::string AlgorithmStep::performStep(RubiksCube& cube, Moves move) {
	cube.performFunction(move);
	return cube.getString(move);
}
