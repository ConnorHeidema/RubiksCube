#include "..\..\inc\algorithm\AlgorithmStep.hpp"

std::string AlgorithmStep::performStep(InteractableCube& cube, void(InteractableCube::* function)()) {
	std::string functionCalledString;
	if (function == &InteractableCube::frontMove) functionCalledString = "front";
	if (function == &InteractableCube::rightMove) functionCalledString = "right";
	if (function == &InteractableCube::backMove) functionCalledString = "back";
	if (function == &InteractableCube::leftMove) functionCalledString = "left";
	if (function == &InteractableCube::topMove) functionCalledString = "top";
	if (function == &InteractableCube::bottomMove) functionCalledString = "bottom";
	if (function == &InteractableCube::frontInverseMove) functionCalledString = "front inverse";
	if (function == &InteractableCube::rightInverseMove) functionCalledString = "right inverse";
	if (function == &InteractableCube::backInverseMove) functionCalledString = "back inverse";
	if (function == &InteractableCube::leftInverseMove) functionCalledString = "left inverse";
	if (function == &InteractableCube::topInverseMove) functionCalledString = "top inverse";
	if (function == &InteractableCube::bottomInverseMove) functionCalledString = "bottom inverse";
	if (function == &InteractableCube::rotateRightFront) functionCalledString = "right-front rotate";
	if (function == &InteractableCube::rotateTopFront) functionCalledString = "top-front rotate";
	if (function == &InteractableCube::rotateFrontFront) functionCalledString = "front-front rotate";
	(cube.*function)();
	return functionCalledString;
}
