#pragma once
#include "Cube.hpp"
class InteractableCube : public virtual Cube {
private:
	void rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
		const Cube::Face& secondFace, const Cube::Position secondPosition,
		const Cube::Face& thirdFace, const Cube::Position thirdPosition,
		const Cube::Face& fourthFace, const Cube::Position fourthPosition);
	void rotateFace(const Cube::Face& face);
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
public:
	virtual ~InteractableCube() = 0;
};

