#include "menu.h"

menu::menu() {
	//ustawianie czcionki
	if (!ksztaltLiter.loadFromFile("czcionka.ttf")) {//pamietac zeby zmienic nazwe liter
		std::cout << "literki sie popsuly\n";
	}

	//wygl¹d menu
	pozycjeMenu[0].setFont(ksztaltLiter);
	pozycjeMenu[0].setFillColor(sf::Color::White);
	pozycjeMenu[0].setCharacterSize(75);
	pozycjeMenu[0].setString("Gioco");
	pozycjeMenu[0].setPosition(400, 200);

	pozycjeMenu[1].setFont(ksztaltLiter);
	pozycjeMenu[1].setFillColor(sf::Color::Magenta);
	pozycjeMenu[1].setCharacterSize(75);
	pozycjeMenu[1].setString("Aiuto");
	pozycjeMenu[1].setPosition(400, 300);

	pozycjeMenu[2].setFont(ksztaltLiter);
	pozycjeMenu[2].setFillColor(sf::Color::Magenta);
	pozycjeMenu[2].setCharacterSize(75);
	pozycjeMenu[2].setString("Arrivederci");
	pozycjeMenu[2].setPosition(400, 400);
}

//wyœwietlanie menu
void menu::draw(sf::RenderWindow& window) {
	window.draw(pozycjeMenu[0]);
	window.draw(pozycjeMenu[1]);
	window.draw(pozycjeMenu[2]);
}

void menu::Gora() {
	switch (menuChoosen) {
	case 0:
		menuChoosen = 2;
		pozycjeMenu[2].setFillColor(sf::Color::White);
		pozycjeMenu[0].setFillColor(sf::Color::Magenta);
		break;
	case 1:
		menuChoosen = 0;
		pozycjeMenu[0].setFillColor(sf::Color::White);
		pozycjeMenu[1].setFillColor(sf::Color::Magenta);
		break;
	case 2:
		menuChoosen = 1;
		pozycjeMenu[1].setFillColor(sf::Color::White);
		pozycjeMenu[2].setFillColor(sf::Color::Magenta);
		break;
	}
}

	void menu::Dol() {
		switch (menuChoosen) {
		case 0:
			menuChoosen = 1;
			pozycjeMenu[1].setFillColor(sf::Color::White);
			pozycjeMenu[0].setFillColor(sf::Color::Magenta);
			break;
		case 1:
			menuChoosen = 2;
			pozycjeMenu[2].setFillColor(sf::Color::White);
			pozycjeMenu[1].setFillColor(sf::Color::Magenta);
			break;
		case 2:
			menuChoosen = 0;
			pozycjeMenu[0].setFillColor(sf::Color::White);
			pozycjeMenu[2].setFillColor(sf::Color::Magenta);
			break;
		}
	}
