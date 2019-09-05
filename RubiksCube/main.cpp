#include "inc\cube\ApplicationCube.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "inc/Button.hpp"
#include "inc\Util.hpp"
#include <vector>
#include <algorithm>

const int FRAMERATE = 60;
const sf::Color WINDOW_CLEAR_COLOUR = sf::Color(64, 64, 64, 255);
const int PROGRAM_OUT_OF_GAME_LOOP = 0;

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
		std::for_each(cube.buttons.begin(), cube.buttons.end(), [&window](Button* button) {
			Image image = button->getButtonImage();
			button->action(sf::Mouse::getPosition());
			button->update();
			window.draw(image.rectangle);
			window.draw(image.text);
			});
		window.display();
	}
	return PROGRAM_OUT_OF_GAME_LOOP;
}