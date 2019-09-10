#include "..\..\inc\util\GameParameters.hpp"

int GameParameters::SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;
int GameParameters::SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
sf::Color GameParameters::BACKGROUND_COLOR = sf::Color(sf::Color(64, 64, 64, 255));
int GameParameters::FRAMERATE = 60;
int GameParameters::REGULAR_BUTTON_HEIGHT = 50;
int GameParameters::REGULAR_BUTTON_WIDTH = 250;
int GameParameters::REGULAR_BUTTON_THICKNESS = -5;
