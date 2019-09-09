#include "..\..\inc\util\GameParameters.hpp"

int GameParameters::SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;
int GameParameters::SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
sf::Font* GameParameters::FONT_PTR = nullptr;
sf::Color GameParameters::BACKGROUND_COLOR = sf::Color(sf::Color(64, 64, 64, 255));
int GameParameters::FRAMERATE = 60;
