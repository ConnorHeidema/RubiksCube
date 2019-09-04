#include "..\inc\CondenseCubeList.hpp"
bool CondenseCubeList::removeQuadrouples(std::list<std::string>& movesList) {
	if (movesList.size() < 4) {
		return false;
	}
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (std::all_of(listIter, std::next(listIter, 4), 
			std::bind2nd(std::equal_to<std::string>(), *listIter))) {
			listIter = movesList.erase(listIter, std::next(listIter, 4));
			return true;
		} else {
			listIter++;
			if (std::next(listIter, 4) == movesList.end()) {
				break;
			}
		}
	}
	return false;
}

bool CondenseCubeList::reverseTriples(std::list<std::string>& movesList) {
	if (movesList.size() < 3) {
		return false;
	}
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (std::all_of(listIter, std::next(listIter, 3),
			std::bind2nd(std::equal_to<std::string>(), *listIter))) {
			*listIter = reverseMoveStringMapping->at(*listIter);
			listIter = movesList.erase(std::next(listIter, 1), std::next(listIter, 3));
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

bool CondenseCubeList::removeBackForths(std::list<std::string>& movesList) {
	if (movesList.size() < 2) {
		return false;
	}
	bool changed = false;
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (reverseMoveStringMapping->at(*listIter) == *std::next(listIter)) {
			listIter = movesList.erase(listIter, std::next(listIter, 2));
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

void CondenseCubeList::removeRotations(std::list<std::string>& movesList) {
	int check = 0;
	auto listIter = movesList.begin();
	while (listIter != movesList.end()) {
		if (*listIter == "Rotate Right Front") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = rightFrontMoveStringMapping->at(*morphingIter);
			}
		} else if (*listIter == "Rotate Top Front") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = topFrontMoveStringMapping->at(*morphingIter);
			}
		} else if (*listIter == "Rotate Front Front") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = frontFrontMoveStringMapping->at(*morphingIter);
			}
		} else if (*listIter == "Rotate Right Front Inverse") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = rightFrontInverseMoveStringMapping->at(*morphingIter);
			}
		} else if (*listIter == "Rotate Top Front Inverse") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = topFrontInverseMoveStringMapping->at(*morphingIter);
			}
		} else if (*listIter == "Rotate Front Front Inverse") {
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = frontFrontInverseMoveStringMapping->at(*morphingIter);
			}
		} else {
			listIter++;
		}
		check++;
	}
}

void CondenseCubeList::condenseList(std::list<std::string>& movesList) {
	removeRotations(movesList);
	bool changed = true;
	while (changed) {
		changed = false;
		changed = removeQuadrouples(movesList) | reverseTriples(movesList) | removeBackForths(movesList);
	}
}

CondenseCubeList::CondenseCubeList() {
	reverseMoveStringMapping = new std::map<std::string, std::string>;
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Front Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Right Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Back Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Left Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Top Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Bottom Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Front"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Right"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Back"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Left"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Top"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Bottom"));

	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Right Front Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Top Front Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Front Front Inverse"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Right Front"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Top Front"));
	reverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Front Front"));

	rightFrontMoveStringMapping = new std::map<std::string, std::string>;
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Left"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Back"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Right"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Front"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Left Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Back Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Right Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Front Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Top"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Top Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Bottom"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Bottom Inverse"));

	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Right Front"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Right Front Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Front Front Inverse"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Front Front"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Top Front"));
	rightFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Top Front Inverse"));

	topFrontMoveStringMapping = new std::map<std::string, std::string>;
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Bottom"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Back"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Top"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Front"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Bottom Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Back Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Top Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Front Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Right"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Right Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Left"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Left Inverse"));

	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Front Front"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Front Front Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Top Front"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Top Front Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Right Front Inverse"));
	topFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Right Front"));

	frontFrontMoveStringMapping = new std::map<std::string, std::string>;
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Right"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Bottom"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Left"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Top"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Right Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Bottom Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Left Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Top Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Front"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Front Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Back"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Back Inverse"));

	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Top Front Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Top Front"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Right Front"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Right Front Inverse"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Front Front"));
	frontFrontMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Front Front Inverse"));

	rightFrontInverseMoveStringMapping = new std::map<std::string, std::string>;
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Right"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Back"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Left"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Front"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Right Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Back Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Left Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Front Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Top"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Top Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Bottom"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Bottom Inverse"));

	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Right Front"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Right Front Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Front Front"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Front Front Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Top Front Inverse"));
	rightFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Top Front"));

	topFrontInverseMoveStringMapping = new std::map<std::string, std::string>;
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Top"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Back"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Bottom"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Front"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Top Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Back Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Bottom Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Front Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Right"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Right Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Left"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Left Inverse"));

	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Front Front Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Front Front"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Top Front"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Top Front Inverse"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Right Front"));
	topFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Right Front Inverse"));

	frontFrontInverseMoveStringMapping = new std::map<std::string, std::string>;
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top", "Left"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left", "Bottom"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom", "Right"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right", "Top"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Top Inverse", "Left Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Left Inverse", "Bottom Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Bottom Inverse", "Right Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Right Inverse", "Top Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front", "Front"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Front Inverse", "Front Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back", "Back"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Back Inverse", "Back Inverse"));

	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front", "Rotate Top Front"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Right Front Inverse", "Rotate Top Front Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front", "Rotate Right Front Inverse"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Top Front Inverse", "Rotate Right Front"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front", "Rotate Front Front"));
	frontFrontInverseMoveStringMapping->insert(std::pair<std::string, std::string>("Rotate Front Front Inverse", "Rotate Front Front Inverse"));
}

CondenseCubeList::~CondenseCubeList() {
	delete reverseMoveStringMapping;
	delete rightFrontMoveStringMapping;
	delete topFrontMoveStringMapping;
	delete frontFrontMoveStringMapping;
	delete rightFrontInverseMoveStringMapping;
	delete topFrontInverseMoveStringMapping;
	delete frontFrontInverseMoveStringMapping;
}