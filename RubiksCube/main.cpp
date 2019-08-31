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
				ranges::for_each(cube, [](Button* thisButton) {delete thisButton;});
				window.close();
			}
		}

		window.clear(WINDOW_CLEAR_COLOUR);
		ranges::for_each(cube, [&window](Button* button) {
			Image image = button->getButtonImage();
			button->action(sf::Mouse::getPosition());
			window.draw(image.rectangle);
			window.draw(image.text);
			});

		cube.moveInteractionHudClick(sf::Mouse::getPosition(window));
		cube.squareClick(sf::Mouse::getPosition(window));
		cube.drawHUD(window);
		cube.drawFlat(window);

		window.display();
	}
	ranges::for_each(cube, [](Button* thisButton) {delete thisButton;});
	return PROGRAM_OUT_OF_GAME_LOOP;
}