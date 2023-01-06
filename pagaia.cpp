#include "pagaia.h"

pagaia::pagaia() {
	paletka.setSize(sf::Vector2f(50, 20));
	paletka.setFillColor(sf::Color::Green);
	paletka.setPosition(400, 700);	
}

void pagaia::draw(sf::RenderWindow& window) {
	window.draw(paletka);
}
