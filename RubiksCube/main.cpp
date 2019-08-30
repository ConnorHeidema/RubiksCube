#include "inc\ApplicationCube.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>

const int FRAMERATE = 60;
const sf::Color WINDOW_CLEAR_COLOUR = sf::Color(64, 64, 64, 255);
const int PROGRAM_SUCCESS = 0;

int main() {
	ApplicationCube cube;

	sf::RenderWindow window(
		sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		"Rubik's Cube!",
		sf::Style::Fullscreen
	);
	window.setFramerateLimit(FRAMERATE);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(WINDOW_CLEAR_COLOUR);

		cube.moveInteractionHudClick(sf::Mouse::getPosition(window));
		cube.scrambleClick(sf::Mouse::getPosition(window));

		cube.drawScrambleButton(window);
		cube.drawHUD(window);
		cube.drawFlat(window);
		window.display();
	}
	return PROGRAM_SUCCESS;
}