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
	std::map<std::string, std::string>* rightFrontMoveStringMapping;
	std::map<std::string, std::string>* topFrontMoveStringMapping;
	std::map<std::string, std::string>* frontFrontMoveStringMapping;
	std::map<std::string, std::string>* rightFrontInverseMoveStringMapping;
	std::map<std::string, std::string>* topFrontInverseMoveStringMapping;
	std::map<std::string, std::string>* frontFrontInverseMoveStringMapping;

public:
	CondenseCubeList();
	~CondenseCubeList();
	void condenseList(std::list<std::string>&);
};

