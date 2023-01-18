#include <fstream>
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

	WYGRANE.setFont(ksztaltLiter);
	WYGRANE.setFillColor(sf::Color::Magenta);
	WYGRANE.setCharacterSize(45);
	WYGRANE.setPosition(950, 730);
	std::fstream plik2("wygrane.txt"); //czytanie z pliku
	plik2 >> wygrane;
	plik2.close();
	WYGRANE.setString("Ha vinto: " + std::to_string(wygrane));

	tlo5.loadFromFile("tlo2.jpg");
	tlo55.setTexture(tlo5);
	tlo55.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	tlo55.setPosition(0, 0);
}

void wygrana::draw(sf::RenderWindow& window) {
	window.draw(tlo55);
	window.draw(win);
	window.draw(WIN);
	window.draw(WYGRANE);
}
