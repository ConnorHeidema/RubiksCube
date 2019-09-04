#include "inc\ListWrapper.hpp"

void ListWrapper::clearList() {
	mutex.lock();
	moveList.clear();
	mutex.unlock();
}

void ListWrapper::insertList(std::string component) {
	mutex.lock();
	moveList.emplace_back(component);
	mutex.unlock();
}

void ListWrapper::joinLists(std::list<std::string> appendedList) {
	mutex.lock();
	moveList.splice(moveList.end(), appendedList);
	mutex.unlock();
}

std::list<std::string> ListWrapper::getCopy() {
	return moveList;
}
