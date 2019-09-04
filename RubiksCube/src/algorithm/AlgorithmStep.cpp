#include "..\..\inc\algorithm\AlgorithmStep.hpp"

AlgorithmStep::~AlgorithmStep() {
}

std::string AlgorithmStep::performStep(InteractableCube& cube, void(InteractableCube::* function)()) {
	(cube.*function)();
	auto it = std::find_if(cube.moveMapping->begin(), cube.moveMapping->end(),
		[&function](const std::pair<std::string, void (InteractableCube::*)()>& p) {
			return p.second == function;
		});
	return it->first;
}
