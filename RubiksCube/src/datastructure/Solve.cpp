#include "..\..\inc\datastructure\Solve.hpp"

Moves Solve::getRotationChangedMove(Moves rotation, Moves oldMove) {
	switch (rotation) {
	case ROTATE_RIGHT_FRONT:
		switch (oldMove) {
		case FRONT_MOVE: return RIGHT_MOVE;
		case RIGHT_MOVE: return BACK_MOVE;
		case BACK_MOVE: return LEFT_MOVE;
		case LEFT_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case RIGHT_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case BACK_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case LEFT_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case TOP_MOVE: return TOP_MOVE;
		case TOP_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case BOTTOM_MOVE: return BOTTOM_MOVE;
		case BOTTOM_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_RIGHT_FRONT;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_RIGHT_FRONT_INVERSE;
		case ROTATE_TOP_FRONT: ROTATE_FRONT_FRONT;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_FRONT_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT: ROTATE_TOP_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_TOP_FRONT;
		}
	case ROTATE_TOP_FRONT:
		switch (oldMove) {
		case FRONT_MOVE: return TOP_MOVE;
		case TOP_MOVE: return BACK_MOVE;
		case BACK_MOVE: return BOTTOM_MOVE;
		case BOTTOM_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case TOP_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case BACK_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case BOTTOM_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case RIGHT_MOVE: return RIGHT_MOVE;
		case RIGHT_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case LEFT_MOVE: return LEFT_MOVE;
		case LEFT_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_FRONT_FRONT_INVERSE;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_FRONT_FRONT;
		case ROTATE_TOP_FRONT: ROTATE_TOP_FRONT;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_TOP_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT: ROTATE_RIGHT_FRONT;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_RIGHT_FRONT_INVERSE;
		}
	case ROTATE_FRONT_FRONT:
		switch (oldMove) {
		case TOP_MOVE: return LEFT_MOVE;
		case LEFT_MOVE: return BOTTOM_MOVE;
		case BOTTOM_MOVE: return RIGHT_MOVE;
		case RIGHT_MOVE: return TOP_MOVE;
		case TOP_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case LEFT_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case BOTTOM_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case RIGHT_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case FRONT_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case BACK_MOVE: return BACK_MOVE;
		case BACK_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_TOP_FRONT;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_TOP_FRONT_INVERSE;
		case ROTATE_TOP_FRONT: ROTATE_RIGHT_FRONT_INVERSE;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_RIGHT_FRONT;
		case ROTATE_FRONT_FRONT: ROTATE_FRONT_FRONT;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_FRONT_FRONT_INVERSE;
		}
	case ROTATE_RIGHT_FRONT_INVERSE:
		switch (oldMove) {
		case FRONT_MOVE: return LEFT_MOVE;
		case LEFT_MOVE: return BACK_MOVE;
		case BACK_MOVE: return RIGHT_MOVE;
		case RIGHT_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case LEFT_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case BACK_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case RIGHT_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case TOP_MOVE: return TOP_MOVE;
		case TOP_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case BOTTOM_MOVE: return BOTTOM_MOVE;
		case BOTTOM_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_RIGHT_FRONT;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_RIGHT_FRONT_INVERSE;
		case ROTATE_TOP_FRONT: ROTATE_FRONT_FRONT_INVERSE;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_FRONT_FRONT;
		case ROTATE_FRONT_FRONT: ROTATE_TOP_FRONT;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_TOP_FRONT_INVERSE;
		}
	case ROTATE_TOP_FRONT_INVERSE:
		switch (oldMove) {
		case FRONT_MOVE: return BOTTOM_MOVE;
		case BOTTOM_MOVE: return BACK_MOVE;
		case BACK_MOVE: return TOP_MOVE;
		case TOP_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case BOTTOM_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case BACK_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case TOP_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case RIGHT_MOVE: return RIGHT_MOVE;
		case RIGHT_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case LEFT_MOVE: return LEFT_MOVE;
		case LEFT_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_FRONT_FRONT;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_FRONT_FRONT_INVERSE;
		case ROTATE_TOP_FRONT: ROTATE_TOP_FRONT;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_TOP_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT: ROTATE_RIGHT_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_RIGHT_FRONT;
		}
	case ROTATE_FRONT_FRONT_INVERSE:
		switch (oldMove) {
		case TOP_MOVE: return RIGHT_MOVE;
		case RIGHT_MOVE: return BOTTOM_MOVE;
		case BOTTOM_MOVE: return LEFT_MOVE;
		case LEFT_MOVE: return TOP_MOVE;
		case TOP_INVERSE_MOVE: return RIGHT_INVERSE_MOVE;
		case RIGHT_INVERSE_MOVE: return BOTTOM_INVERSE_MOVE;
		case BOTTOM_INVERSE_MOVE: return LEFT_INVERSE_MOVE;
		case LEFT_INVERSE_MOVE: return TOP_INVERSE_MOVE;
		case FRONT_MOVE: return FRONT_MOVE;
		case FRONT_INVERSE_MOVE: return FRONT_INVERSE_MOVE;
		case BACK_MOVE: return BACK_MOVE;
		case BACK_INVERSE_MOVE: return BACK_INVERSE_MOVE;
		case ROTATE_RIGHT_FRONT: ROTATE_TOP_FRONT_INVERSE;
		case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_TOP_FRONT;
		case ROTATE_TOP_FRONT: ROTATE_RIGHT_FRONT;
		case ROTATE_TOP_FRONT_INVERSE: return ROTATE_RIGHT_FRONT_INVERSE;
		case ROTATE_FRONT_FRONT: ROTATE_FRONT_FRONT;
		case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_FRONT_FRONT_INVERSE;
		}
	}
	return NUM_MOVES;
}

Moves Solve::getReverseMove(Moves move) {
	switch (move) {
	case FRONT_MOVE: return FRONT_INVERSE_MOVE;
	case RIGHT_MOVE: return RIGHT_INVERSE_MOVE;
	case BACK_MOVE: return BACK_INVERSE_MOVE;
	case LEFT_MOVE: return LEFT_INVERSE_MOVE;
	case TOP_MOVE: return TOP_INVERSE_MOVE;
	case BOTTOM_MOVE: return BOTTOM_INVERSE_MOVE;
	case FRONT_INVERSE_MOVE: return FRONT_MOVE;
	case RIGHT_INVERSE_MOVE: return RIGHT_MOVE;
	case BACK_INVERSE_MOVE: return BACK_MOVE;
	case LEFT_INVERSE_MOVE: return LEFT_MOVE;
	case TOP_INVERSE_MOVE: return TOP_MOVE;
	case BOTTOM_INVERSE_MOVE: return BOTTOM_MOVE;
	case ROTATE_RIGHT_FRONT: return ROTATE_RIGHT_FRONT_INVERSE;
	case ROTATE_TOP_FRONT: return ROTATE_TOP_FRONT_INVERSE;
	case ROTATE_FRONT_FRONT: return ROTATE_FRONT_FRONT_INVERSE;
	case ROTATE_RIGHT_FRONT_INVERSE: return ROTATE_RIGHT_FRONT;
	case ROTATE_TOP_FRONT_INVERSE: return ROTATE_TOP_FRONT;
	case ROTATE_FRONT_FRONT_INVERSE: return ROTATE_FRONT_FRONT;
	}
	return NUM_MOVES;
}

Solve::Solve() {
}

std::list<Moves> Solve::solveCube(RubiksCube* rubiks) {
	std::list<Moves> moveList;
	std::list<AlgorithmStep*> currentStep = {
		new AlignBottomSidesStep(),
		new AlignBottomCornerStep(),
		new AlignMiddleSidesStep(),
		new AlignTopCross(),
		new AlignTopSquares(),
		new AlignTopCorners(),
		new AlignFinalCornersFully()
	};

	std::for_each(currentStep.begin(), currentStep.end(), [&moveList, &currentStep, &rubiks](AlgorithmStep* step) {
		if (!step->stepIsComplete(*rubiks)) {
			moveList.splice((moveList).end(), step->makeMoves(*rubiks));
		}
		std::cout << (step->stepIsComplete(*rubiks) ? "Step successful\n" : "ERROR IN STEP\n");
		delete step;
		});
	return moveList;
}

void Solve::condenseSolvedList(std::list<Moves>& moveList) {
	removeRotations(moveList);
	bool changed = true;
	while (changed) {
		changed = false;
		changed = removeQuadrouples(moveList) | reverseTriples(moveList) | removeBackForths(moveList);
	}
}

void Solve::removeRotations(std::list<Moves>& movesList) {
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		switch (*listIter) {
		case ROTATE_RIGHT_FRONT:
		case ROTATE_RIGHT_FRONT_INVERSE:
		case ROTATE_FRONT_FRONT:
		case ROTATE_FRONT_FRONT_INVERSE:
		case ROTATE_TOP_FRONT:
		case ROTATE_TOP_FRONT_INVERSE: {
			Moves rotation = *listIter;
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = getRotationChangedMove(rotation, *morphingIter);
			}
			break;
		}
		default:
			listIter++;
		}
	}
}

bool Solve::removeBackForths(std::list<Moves>& movesList) {
	if (movesList.size() < 2) {
		return false;
	}
	bool changed = false;
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (getReverseMove(*listIter) == *std::next(listIter)) {
			listIter = movesList.erase(listIter, std::next(listIter, 2));
			return true;
		} else {
			listIter++;
			if (std::next(listIter) == movesList.end()) {
				break;
			}
		}
	}
	return false;
}

bool Solve::reverseTriples(std::list<Moves>& movesList) {
	if (movesList.size() < 3) {
		return false;
	}
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (std::all_of(listIter, std::next(listIter, 3),
			std::bind2nd(std::equal_to<Moves>(), *listIter))) {
			*listIter = getReverseMove(*listIter);
			listIter = movesList.erase(std::next(listIter, 1), std::next(listIter, 3));
			return true;
		} else {
			listIter++;
			if (std::next(listIter, 2) == movesList.end()) {
				break;
			}
		}
	}
	return false;
}

bool Solve::removeQuadrouples(std::list<Moves>& movesList) {
	if (movesList.size() < 4) {
		return false;
	}
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (std::all_of(listIter, std::next(listIter, 4),
			std::bind2nd(std::equal_to<Moves>(), *listIter))) {
			listIter = movesList.erase(listIter, std::next(listIter, 4));
			return true;
		} else {
			listIter++;
			if (std::next(listIter, 3) == movesList.end()) {
				break;
			}
		}
	}
	return false;
}
