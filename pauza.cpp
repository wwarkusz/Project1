#include "pauza.h"

pauza::pauza() {
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {
		std::cout << "literki sie popsuly\n";
	}

	stop.setFont(ksztaltLiter);
	stop.setFillColor(sf::Color::White);
	stop.setCharacterSize(60);
	stop.setString("Vuoi lasciare il gioco? \n    Continua - Enter\n      Menu - Space");
	stop.setPosition(270, 400);
	stop.setOutlineColor(sf::Color::Magenta); //kolor obramowania liter
	stop.setOutlineThickness(2); //szerokosc obramowania liter

	rectangle.setSize(sf::Vector2f(700, 250));
	rectangle.setPosition(250, 400);
	rectangle.setFillColor(sf::Color::Black);
}

void pauza::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
	window.draw(stop);
}