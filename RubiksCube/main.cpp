#include "inc\cube\ApplicationCube.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "inc/Button.hpp"
#include <vector>

const int FRAMERATE = 60;
const sf::Color WINDOW_CLEAR_COLOUR = sf::Color(64, 64, 64, 255);
const int PROGRAM_SUCCESS = 0;

int main() {
	std::vector<Button> buttons;

	ApplicationCube cube;

	sf::RenderWindow window(
		sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		"Rubik's Cube!",
		sf::Style::Fullscreen
	);

	Button button(100, 200, 75, 30, 50, sf::Color::Green, sf::Color::Red,sf::Text(), sf::Font(), []() {std::cout << "hellowowlrd"; }, []() {std::cout << "goodbye\n\n\n"; }, "Scramble");

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
		cube.squareClick(sf::Mouse::getPosition(window));

		cube.drawScrambleButton(window);
		cube.drawHUD(window);
		cube.drawFlat(window);
		Image image = button.getButtonImage();
		window.draw(image.rectangle);
		//window.draw(image.text);

		button.action(sf::Mouse::getPosition(window));
		window.display();
	}
	return PROGRAM_SUCCESS;
}