#pragma once
#include "Cube.hpp"

class InteractableCube : public virtual Cube {
private:
	class InteractableCubeButton : public Button {
		friend class InteractableCube;
		const sf::Color NORMAL_COLOUR = sf::Color(86, 170, 242, 255);
		const sf::Color REVERSE_COLOUR = sf::Color(185, 86, 242, 255);
		const sf::Color BUTTON_OUTLINE_COLOUR = sf::Color(32, 32, 32, 255);
		const int BUTTON_OUTLINE_THICKNESS = -3;
		void (InteractableCube::* moveFnPtr)(void);
		InteractableCubeButton(InteractableCube* interactableCube, void (InteractableCube::* function)(), int xPosition = 0, int yPosition = 0,
			int xSize = 50, int ySize = 50, int thickness = -5,
			sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
			sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
		InteractableCube* outerReference;
		
	public:
		static const int NORMAL = 0;
		static const int INVERSE = 1;
		virtual void leftButtonClicked() override;
		virtual void rightButtonClicked() override;
	};
	InteractableCubeButton* movementButtons[2][NUM_FACES];
	InteractableCubeButton* rotateButtons[3];

	void rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
		const Cube::Face& secondFace, const Cube::Position secondPosition,
		const Cube::Face& thirdFace, const Cube::Position thirdPosition,
		const Cube::Face& fourthFace, const Cube::Position fourthPosition);
	void inverseRotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
		const Cube::Face& secondFace, const Cube::Position secondPosition,
		const Cube::Face& thirdFace, const Cube::Position thirdPosition,
		const Cube::Face& fourthFace, const Cube::Position fourthPosition);
	void rotateFace(const Cube::Face& face);
	void inverseRotateFace(const Cube::Face& face);
protected:
	InteractableCube();
	void frontMove();
	void rightMove();
	void backMove();
	void leftMove();
	void topMove();
	void bottomMove();
	void frontInverseMove();
	void rightInverseMove();
	void backInverseMove();
	void leftInverseMove();
	void topInverseMove();
	void bottomInverseMove();
	void rotateRightFront();
	void rotateTopFront();
	void rotateFrontFront();
public:
	virtual ~InteractableCube() = 0;
};

