#include "wygrana.h"

wygrana::wygrana() {
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {
		std::cout << "literki sie popsuly\n";
	}

	win.setFont(ksztaltLiter);
	win.setFillColor(sf::Color::Magenta);
	win.setCharacterSize(80);
	win.setString("Vincita");
	win.setPosition(450, 200);

	WIN.setFont(ksztaltLiter);
	WIN.setFillColor(sf::Color::White);
	WIN.setCharacterSize(30);
	WIN.setString("Space - Menu");
	WIN.setPosition(490, 300);
}

void wygrana::draw(sf::RenderWindow& window) {
	window.draw(win);
	window.draw(WIN);
}