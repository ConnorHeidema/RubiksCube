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
		window.clear();
		sf::VertexArray curve(sf::PrimitiveType::LineStrip, 100);
		for (int x = 4000; x < 5000; x++) {
			curve.append(sf::Vertex(sf::Vector2f(x, 100 + 100*sin(0.01*x))));
		}
		window.draw(curve);
		cube.drawFlat(window);
		window.display();
	}
	return 0;
}