#include "..\..\inc\cube\TestSolvableCubes.hpp"

void TestSolvableCubes::testSolvableCubes() {

}

TestSolvableCubes::TestSolvableCubes() {
}

TestSolvableCubes::~TestSolvableCubes() {
}

void TestSolvableCubes::TestSolvableCubesButton::leftButtonClicked() {
	outerReference->testSolvableCubes();
}

void TestSolvableCubes::TestSolvableCubesButton::rightButtonClicked() {
}

TestSolvableCubes::TestSolvableCubesButton::TestSolvableCubesButton(TestSolvableCubes* testSolvableCube, int xPosition, int yPosition,
	int xSize, int ySize, int thickness,
	sf::Color color, sf::Color outlineColour,
	sf::Text text, sf::Font font, std::string buttonText) :
	Button(xPosition, yPosition, xSize, ySize, thickness, color, outlineColour, text, font, buttonText) {
	outerReference = testSolvableCube;
}