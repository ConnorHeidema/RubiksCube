#include "..\..\inc\actionobjects\ActionRectangleShape.hpp"

ActionRectangleShape::ActionRectangleShape() : rectShapePtr(nullptr) {
}

ActionRectangleShape::ActionRectangleShape(sf::RectangleShape* rectShapePtr) {
	this->rectShapePtr = rectShapePtr;
}

ActionRectangleShape::ActionRectangleShape(const ActionRectangleShape& other) {
	sf::RectangleShape* rectShape = new sf::RectangleShape();
	rectShape->setFillColor(other.rectShapePtr->getFillColor());
	rectShape->setPosition(other.rectShapePtr->getPosition());
	rectShape->setOutlineColor(other.rectShapePtr->getOutlineColor());
	rectShape->setOutlineThickness(other.rectShapePtr->getOutlineThickness());
	rectShape->setSize(other.rectShapePtr->getSize());
	rectShape->setFillColor(other.rectShapePtr->getFillColor());
	rectShapePtr = rectShape;
}

ActionRectangleShape::~ActionRectangleShape() {
	delete rectShapePtr;
}

ActionObject* ActionRectangleShape::clone() {
	return new ActionRectangleShape(*this);
}

sf::IntRect ActionRectangleShape::getBounds() {
	return sf::IntRect(rectShapePtr->getGlobalBounds().left,
		rectShapePtr->getGlobalBounds().top,
		rectShapePtr->getGlobalBounds().width,
		rectShapePtr->getGlobalBounds().height);
}

sf::Drawable* ActionRectangleShape::getDrawable() {
	return rectShapePtr;
}
