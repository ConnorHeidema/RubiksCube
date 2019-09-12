#pragma once
#include "../../datastructure/Solve.hpp"
#include "../ActionRectangleShape.hpp"
#include "../../util/GameParameters.hpp"
#include "../../datastructure/RubiksCube.hpp"
#include "../ActionRectangleShape.hpp"
#include "../ActionText.hpp"
#include <thread>
class SolveButton : public ActionRectangleShape {
	sf::Text* lastSolution;
	sf::Clock clock;
	RubiksCube* rubiksPtr;
	std::list<Moves> moveList;
	virtual void onLeftClick(std::list<ActionObject*>& allObjects) override;
	virtual void onHover(std::list<ActionObject*>& allObjects) override;
	virtual void onEndHover(std::list<ActionObject*>& allObjects) override;
public:
	SolveButton();
	~SolveButton();
	SolveButton(RubiksCube* rubiks, std::list<Moves>* moveList);
	SolveButton* clone() override;
	SolveButton(const SolveButton& other);
};
