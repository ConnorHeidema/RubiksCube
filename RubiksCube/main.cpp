#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "inc/Cube.hpp"
#include "inc/ApplicationCube.hpp"
#include <iostream>


int main() {
	sf::RenderWindow window(
		sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		"Rubik's Cube!",
		sf::Style::Fullscreen
	);
	window.setFramerateLimit(60);
	sf::Clock clock;
	sf::Time elapsed1;

	ApplicationCube cube;
	bool isMouseClicked = false;
	while (window.isOpen()) {
		elapsed1 = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (elapsed1.asSeconds() > 1) {
			clock.restart();
			elapsed1 = clock.getElapsedTime();
		}
		window.clear(sf::Color(64, 64, 64,255));
			// display number of ticks mouse wheel has moved
		
		if (event.type == sf::Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				std::cout << "wheel type: vertical" << std::endl;
			else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
				std::cout << "wheel type: horizontal" << std::endl;
			else
				std::cout << "wheel type: unknown" << std::endl;
			std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
			std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
			std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isMouseClicked) {
			cube.moveInteractionHudClick(sf::Mouse::getPosition(window));
			cube.scrambleClick(sf::Mouse::getPosition(window));
			isMouseClicked = true;
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isMouseClicked = false;
		}
		cube.drawScrambleButton(window);
		cube.drawHUD(window);
		cube.drawFlat(window);
		window.display();
	}
	return 0;
}