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
			if (std::next(listIter, 3) == movesList.end()) {
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
			if (std::next(listIter, 2) == movesList.end()) {
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
			if (std::next(listIter) == movesList.end()) {
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
		if (std::find(rotationList->begin(), rotationList->end(), *listIter) != rotationList->end()) {
			std::string rotation = *listIter;
			listIter = movesList.erase(listIter);
			for (auto morphingIter = listIter; morphingIter != movesList.end(); morphingIter++) {
				*morphingIter = rotationMoveStringMapping->at(std::pair<std::string, std::string>(rotation, *morphingIter));
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

	using stringToString = std::pair<std::string, std::string>;
	using pairToString = std::pair<std::pair<std::string, std::string>, std::string>;
	rotationMoveStringMapping = new std::map<stringToString, std::string>;
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Front"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Left"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Back"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Right"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Front Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Left Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Back Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Right Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Top"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Top Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Bottom"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Bottom Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Right Front"), "Rotate Right Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Right Front Inverse"), "Rotate Right Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Top Front"), "Rotate Front Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Top Front Inverse"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Front Front"), "Rotate Top Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front Inverse", "Rotate Front Front Inverse"), "Rotate Top Front Inverse"));

	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Front"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Right"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Back"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Left"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Front Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Right Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Back Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Left Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Top"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Top Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Bottom"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Bottom Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Right Front"), "Rotate Right Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Right Front Inverse"), "Rotate Right Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Top Front"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Top Front Inverse"), "Rotate Front Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Front Front"), "Rotate Top Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Right Front", "Rotate Front Front Inverse"), "Rotate Top Front"));

	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Front"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Bottom"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Back"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Top"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Front Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Bottom Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Back Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Top Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Right"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Right Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Left"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Left Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Right Front"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Right Front Inverse"), "Rotate Front Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Top Front"), "Rotate Top Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Top Front Inverse"), "Rotate Top Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Front Front"), "Rotate Right Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front Inverse", "Rotate Front Front Inverse"), "Rotate Right Front"));

	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Front"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Top"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Back"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Bottom"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Front Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Top Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Back Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Bottom Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Right"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Right Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Left"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Left Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Right Front"), "Rotate Front Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Right Front Inverse"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Top Front"), "Rotate Top Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Top Front Inverse"), "Rotate Top Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Front Front"), "Rotate Right Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Top Front", "Rotate Front Front Inverse"), "Rotate Right Front Inverse"));
	
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Top"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Right"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Bottom"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Left"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Top Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Right Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Bottom Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Left Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Front"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Front Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Back"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Back Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Right Front"), "Rotate Top Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Right Front Inverse"), "Rotate Top Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Top Front"), "Rotate Right Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Top Front Inverse"), "Rotate Right Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Front Front"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front Inverse", "Rotate Front Front Inverse"), "Rotate Front Front Inverse"));

	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Top"), "Left"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Left"), "Bottom"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Bottom"), "Right"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Right"), "Top"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Top Inverse"), "Left Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Left Inverse"), "Bottom Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Bottom Inverse"), "Right Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Right Inverse"), "Top Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Front"), "Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Front Inverse"), "Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Back"), "Back"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Back Inverse"), "Back Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Right Front"), "Rotate Top Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Right Front Inverse"), "Rotate Top Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Top Front"), "Rotate Right Front Inverse"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Top Front Inverse"), "Rotate Right Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Front Front"), "Rotate Front Front"));
	rotationMoveStringMapping->insert(pairToString(stringToString("Rotate Front Front", "Rotate Front Front Inverse"), "Rotate Front Front Inverse"));

	rotationList = new std::list<std::string>();
	rotationList->emplace_back("Rotate Right Front");
	rotationList->emplace_back("Rotate Right Front Inverse");
	rotationList->emplace_back("Rotate Top Front");
	rotationList->emplace_back("Rotate Top Front Inverse");
	rotationList->emplace_back("Rotate Front Front");
	rotationList->emplace_back("Rotate Front Front Inverse");
}

CondenseCubeList::~CondenseCubeList() {
	delete reverseMoveStringMapping;
	delete rotationMoveStringMapping;
}