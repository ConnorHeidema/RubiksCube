#pragma once
#include "ActionObject.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
class ActionText : public ActionObject {
private:
protected:
	ActionText();
	sf::Text* textPtr;
	// getFontLocation is necessary because unlike texture it doesn't necessarily point to the 
	// correct location when it says its done. (ie to fix an internal bug that may or may
	// not be something that I have access to fix.
	virtual std::string getFontLocation();
public:
	ActionText(sf::Text* sprite);
	ActionText(const ActionText& other);
	virtual	~ActionText();
	virtual ActionObject* clone() override;
	virtual sf::IntRect getBounds() override;
	virtual sf::Drawable* getDrawable() override;
};

