#include "SolveButton.hpp"

void SolveButton::onLeftClick(std::list<ActionObject*>& allObjects) {
	Solve solve;
	moveList = solve.solveCube(rubiksPtr);
	//@TODO fix bug!
	solve.condenseSolvedList(moveList);
	std::for_each(moveList.begin(), moveList.end(), [this](Moves move) {
		rubiksPtr->performFunction(move);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(.01s);
		});
	moveList.clear();
}

void SolveButton::onHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color::Magenta);
}

void SolveButton::onEndHover(std::list<ActionObject*>& allObjects) {
	rectShapePtr->setFillColor(sf::Color::Blue);
}

SolveButton::SolveButton() {
}

SolveButton::SolveButton(RubiksCube* rubiks, std::list<Moves>* moveList) : rubiksPtr(rubiks), moveList(*moveList) {
	clock.restart();
	int yOffset = 375;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(GameParameters::REGULAR_BUTTON_WIDTH, GameParameters::REGULAR_BUTTON_HEIGHT));
	rect->setFillColor(sf::Color::Blue);
	rect->setOutlineThickness(GameParameters::REGULAR_BUTTON_THICKNESS);
	rect->setOutlineColor(sf::Color::Black);
	rect->setPosition((GameParameters::SCREEN_WIDTH - rect->getSize().x) / 2, (GameParameters::SCREEN_HEIGHT - rect->getSize().y) / 2 + yOffset);
	rectShapePtr = rect;
}

SolveButton* SolveButton::clone() {
	return new SolveButton(*this);
}

SolveButton::SolveButton(const SolveButton& other) : ActionRectangleShape(other) {
	clock = other.clock;
	moveList = other.moveList;
	rubiksPtr = other.rubiksPtr;
}
