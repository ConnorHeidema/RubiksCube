#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "inc/Cube.hpp"

int main() {
	sf::RenderWindow window(
		sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		"SFML works!",
		sf::Style::Fullscreen
	);
	window.setFramerateLimit(60);
	sf::Clock clock;
	sf::Time elapsed1;
	Cube cube;
	
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
			cube.backMove();
		}
		window.clear();
		cube.drawFlat(window);
		window.display();
	}
	return 0;
}