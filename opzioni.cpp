#include "opzioni.h"

opzioni::opzioni() {
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {//pamietac zeby zmienic nazwe liter
		std::cout << "literki sie popsuly\n";
	}

	Opcje[0].setFont(ksztaltLiter);
	Opcje[0].setFillColor(sf::Color::White);
	Opcje[0].setCharacterSize(75);
	Opcje[0].setString("Facile");
	Opcje[0].setPosition(400, 200);

	Opcje[1].setFont(ksztaltLiter);
	Opcje[1].setFillColor(sf::Color::Magenta);
	Opcje[1].setCharacterSize(75);
	Opcje[1].setString("Difficile");
	Opcje[1].setPosition(400, 300);
}

void opzioni::draw(sf::RenderWindow& window) {
	window.draw(Opcje[0]);
	window.draw(Opcje[1]);
}

void opzioni::Gora() {
	switch (opcjaChoosen) {
	case 0:
		opcjaChoosen = 1;
		Opcje[1].setFillColor(sf::Color::White);
		Opcje[0].setFillColor(sf::Color::Magenta);
		break;
	case 1:
		opcjaChoosen = 0;
		Opcje[0].setFillColor(sf::Color::White);
		Opcje[1].setFillColor(sf::Color::Magenta);
		break;
	}
}

void opzioni::Dol() {
	switch (opcjaChoosen) {
	case 0:
		opcjaChoosen = 1;
		Opcje[1].setFillColor(sf::Color::White);
		Opcje[0].setFillColor(sf::Color::Magenta);
		break;
	case 1:
		opcjaChoosen = 0;
		Opcje[0].setFillColor(sf::Color::White);
		Opcje[1].setFillColor(sf::Color::Magenta);
		break;
	}
}