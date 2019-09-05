#pragma once
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <functional>
class CondenseCubeList {
	bool removeQuadrouples(std::list<std::string>&);
	bool reverseTriples(std::list<std::string>&);
	bool removeBackForths(std::list<std::string>& movesList);
	void removeRotations(std::list<std::string>&);

	std::map<std::string, std::string>* reverseMoveStringMapping;
	std::map<std::pair<std::string, std::string>, std::string>* rotationMoveStringMapping;
	std::list<std::string>* rotationList;

public:
	CondenseCubeList();
	~CondenseCubeList();
	void condenseList(std::list<std::string>&);
};

