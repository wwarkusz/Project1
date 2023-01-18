#include "menu.h"

menu::menu() {
	//ustawianie czcionki
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {//pamietac zeby zmienic nazwe liter
		std::cout << "literki sie popsuly\n";
	}

	//wygl¹d menu
	pozycjeMenu[0].setFont(ksztaltLiter);
	pozycjeMenu[0].setFillColor(sf::Color::White);
	pozycjeMenu[0].setCharacterSize(75);
	pozycjeMenu[0].setString("Gioco");
	pozycjeMenu[0].setPosition(470, 200);

	pozycjeMenu[1].setFont(ksztaltLiter);
	pozycjeMenu[1].setFillColor(sf::Color::Magenta);
	pozycjeMenu[1].setCharacterSize(75);
	pozycjeMenu[1].setString("Aiuto");
	pozycjeMenu[1].setPosition(480, 300);

	pozycjeMenu[2].setFont(ksztaltLiter);
	pozycjeMenu[2].setFillColor(sf::Color::Magenta);
	pozycjeMenu[2].setCharacterSize(75);
	pozycjeMenu[2].setString("Arrivederci");
	pozycjeMenu[2].setPosition(380, 400);

	tlo2.loadFromFile("tlo1.jpg");
	tlo22.setTexture(tlo2);
	tlo22.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	tlo22.setPosition(0, 0);
}

//wyœwietlanie menu
void menu::draw(sf::RenderWindow& window) {
	window.draw(tlo22);
	window.draw(pozycjeMenu[0]);
	window.draw(pozycjeMenu[1]);
	window.draw(pozycjeMenu[2]);
}

void menu::Gora() { //do poruszania sie po menu w gore
	switch (menuChoosen) {
	case 0:
		menuChoosen = 2; //zmieniamy z pozycji 0 na 2 i pozycja 2 koloruje sie na bialo
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

void menu::Dol() { //to samo co wyzej tylko w dol
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