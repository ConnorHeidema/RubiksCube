#pragma once
#include "ActionLoop.hpp"
#include "RenderLoop.hpp"
#include "../datastructure/RubiksCube.hpp"
#include "../actionobjects/ActionObject.hpp"
#include "../actionobjects/introscreen/BeginButton.hpp"
#include "../actionobjects/introscreen/BeginText.hpp"
#include "../actionobjects/introscreen/InstructionsButton.hpp"
#include "../actionobjects/introscreen/InstructionsText.hpp"
#include "../actionobjects/introscreen/Title.hpp"
#include "../actionobjects/introscreen/TitleShape.hpp"
#include "../actionobjects/introscreen/RubiksSquare.hpp"
#include "../actionobjects/introscreen/RubiksMoveButton.hpp"
#include "../util/GameParameters.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>
#include <mutex>
#include <thread>
class Game {
public:
	static void start();
	static void setupInitialObjects(std::list<ActionObject*>& actionSpritesPtrs);
	static void setupRubiksObjects(std::list<ActionObject*>& setupRubiksObject);
	static void placeFace(std::list<ActionObject*>& actionSpritesPtrs, RubiksCube* rubiks, Faces face);
	static void placeSquares(std::list<ActionObject*>& actionSpritesPtrs, RubiksCube* rubiks, int xFaceOffset, int yFaceOffset, Faces face);
};
