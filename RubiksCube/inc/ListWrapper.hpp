#pragma once
#include <string>
#include <list>
#include <mutex>
class ListWrapper {
public:
	void clearList();
	void insertList(std::string component);
	void joinLists(std::list<std::string>);
	std::list<std::string> getCopy();
private:
	std::mutex mutex;
	std::list<std::string> moveList;
};

