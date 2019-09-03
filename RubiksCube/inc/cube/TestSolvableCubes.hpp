#pragma once
#include "InteractableCube.hpp"
#include "..\Util.hpp"
#include "SFML\Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
/**
 * @todo Need to implement this to test several cubes quickly.
 */
class TestSolvableCubes : public virtual InteractableCube {
private:
	void testSolvableCubes();
	class TestSolvableCubesButton : public Button {
		friend class TestSolvableCubes;
		TestSolvableCubesButton(TestSolvableCubes* scramble, int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		TestSolvableCubes* outerReference;
		void leftButtonClicked() override;
		void rightButtonClicked() override;
	};
	TestSolvableCubesButton* scrambleButtonPtr;
protected:
	TestSolvableCubes();
public:
	virtual ~TestSolvableCubes() = 0;
};
