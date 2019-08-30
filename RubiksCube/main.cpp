#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "inc/Cube.hpp"
#include "inc/ApplicationCube.hpp"
#include <iostream>

int main() {
	ApplicationCube cube;

	sf::RenderWindow window(
		sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		"Rubik's Cube!",
		sf::Style::Fullscreen
	);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(64, 64, 64,255));

		cube.moveInteractionHudClick(sf::Mouse::getPosition(window));
		cube.scrambleClick(sf::Mouse::getPosition(window));

		cube.drawScrambleButton(window);
		cube.drawHUD(window);
		cube.drawFlat(window);
		window.display();
	}
	return 0;
}