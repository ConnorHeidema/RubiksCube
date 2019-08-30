#include "..\inc\Util.hpp"

bool Util::isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle) {
	if (rectangle.getGlobalBounds().left < mouse.x && rectangle.getGlobalBounds().top < mouse.y &&
		rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width > mouse.x &&
		rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height > mouse.y) {
		return true;
	}
	return false;
}