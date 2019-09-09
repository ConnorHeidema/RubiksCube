#pragma once
#include "ActionLoop.hpp"
#include "RenderLoop.hpp"
#include "../sprite/ActionSprite.hpp"
#include "../util/GameParameters.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>
#include <mutex>
#include <thread>
class Game {
public:
	static void start();
	static void setupInitialObjects(std::list<ActionSprite*>& actionSpritesPtrs);
};

