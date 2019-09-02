#include "..\..\inc\algorithm\AlgorithmStep.hpp"

std::string AlgorithmStep::performStep(void(InteractableCube::* function)()) {
	if (function == &InteractableCube::frontMove) {
	}
	return std::string();
}
