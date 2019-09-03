#include "..\..\inc\algorithm\AlignTopCross.hpp"
#include "AlgorithmStep.cpp"

bool AlignTopCross::stepIsComplete(InteractableCube& cube) {
	return false;
}

std::list<std::string> AlignTopCross::makeMoves(InteractableCube& cube, int maxMovesAllowed) {
	std::list <std::string> stepsUsed;
	return std::list<std::string>();
}

void topCrossPermutation(std::list<std::string>& stepsUsed, InteractableCube& cube, int maxMovesAllowed = 1000) {
	//stepsUsed.emplace_back(performStep(cube, &InteractableCube::topInverseMove));
}
