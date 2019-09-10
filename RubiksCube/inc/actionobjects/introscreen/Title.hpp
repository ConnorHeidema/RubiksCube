#pragma once
#include "../ActionText.hpp"
#include "../../util/GameParameters.hpp"
#include "../../datastructure/RubiksCube.hpp"
#include "SFML/Graphics.hpp"
#include <ctime>
#include <cstdlib>
class Title :
	public ActionText {
	RubiksCube* rubiks;
	sf::Clock timer;
	virtual void onTimePassing(std::list<ActionObject*>& allObjects) override;
	virtual void onRemove(std::list<ActionObject*>& allObjects) override;
	virtual ~Title();
public:
	Title(RubiksCube* rubiks);
	virtual Title* clone() override;
	Title(const Title& other);
};
