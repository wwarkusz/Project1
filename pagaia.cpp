#include <string>
#include<fstream>
#include "pagaia.h"

pagaia::pagaia() {
	teksturaPaletki.loadFromFile("aaa.png");
	paletka.setTexture(teksturaPaletki);
	paletka.setTextureRect(sf::IntRect(0, 0, 120, 45));
	paletka.setPosition(400, 700);

	teksturaPilki.loadFromFile("bbb.png");
	pilka.setTexture(teksturaPilki);
	pilka.setTextureRect(sf::IntRect(0, 0, 20, 20));
	pilka.setPosition(400, 500);

	tlo4.loadFromFile("tlo1.jpg");
	tlo44.setTexture(tlo4);
	tlo44.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	tlo44.setPosition(0, 0);

	std::fstream plik("przegrane.txt");
	plik >> przegrane;
	plik.close();

	std::fstream plik2("wygrane.txt");
	plik2 >> wygrane;
	plik2.close();

	teksturaKwadratow.loadFromFile("ccc.png");
	for (int i = 0; i < 68; i++) {
		kwadrat[i].setTexture(teksturaKwadratow);
		kwadrat[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
	} //ustawianie pozycji kwadratow
	for (int i = 0; i < 17; i++) {
		kwadrat[i].setPosition(i * 70+15, 50);
	}
	for (int i = 17; i < 34; i++) {
		kwadrat[i].setPosition((i - 17) * 70+15, 120);
	}
	for (int i = 34; i < 51; i++) {
		kwadrat[i].setPosition((i - 34) * 70+15, 190);
	}
	for (int i = 51; i < 68; i++) {
		kwadrat[i].setPosition((i - 51) * 70+15, 260);
	}

	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {//pamietac zeby zmienic nazwe liter
		std::cout << "literki sie popsuly\n";
	}

	punkty.setFont(ksztaltLiter);
	punkty.setFillColor(sf::Color::Magenta);
	punkty.setCharacterSize(45);
	punkty.setPosition(950, 730);
	p = 0;

	help.setFont(ksztaltLiter);
	help.setFillColor(sf::Color::White);
	help.setCharacterSize(15);
	help.setPosition(5, 15);
	help.setString("Space - Aiuto     Escape - Pauza/Menu");
}

void pagaia::draw(sf::RenderWindow& window) {
	window.draw(tlo44);
	window.draw(paletka);
	window.draw(pilka);
	window.draw(punkty);
	window.draw(help);
	for (int i = 0; i < 68; i++) {
		window.draw(kwadrat[i]);
	}
}

void pagaia::Prawo() { //poruszanie paletka w prawo
	if (paletka.getPosition().x < 1100) {
		paletka.move(1, 0);
	}
}

void pagaia::Lewo() { //poruszanie paletka w lewo
	if (paletka.getPosition().x > 0) {
		paletka.move(-1, 0);
	}
}

int pagaia::Ruch() {
	pilka.move(dx, dy);
	if (pilka.getPosition().x >= 1180) { //jak na x pilka dotknie 1180 to zmienia kierunek w x
		dx = -dx;
	}
	if (pilka.getPosition().x <= 0) { //jak na x pilka dotknie 0 to zmienia kierunek w x
		dx = -dx;
	}
	if (pilka.getPosition().y <= 20) { //jak na y pilka dotknie 20 to zmienia kierunek w y
		dy = -dy;
	}
	if (pilka.getPosition().y >= 900) { //jak na y pilka dotknie 900
		przegrane = przegrane + 1; //zmienna przegrane zwieksza sie o 1
		std::ofstream plik("przegrane.txt"); //zapisuje sie to do pliku
		plik << przegrane;
		plik.close();
		pilka.setPosition(400, 500); //pilka wraca do srodkowej pozycji
		return 9;
	}
	return 0;
}

int pagaia::odbijanie() {
	sf::IntRect niewidzialnaPilka(pilka.getPosition().x, pilka.getPosition().y, 20, 20); //tworze niewidzualna pilke o pozycji i wymiarach mojej pilki
	sf::IntRect niewidzialnaPaletka(paletka.getPosition().x, paletka.getPosition().y, 120, 45); //tak samo z paletka
	if (niewidzialnaPilka.intersects(niewidzialnaPaletka)) { //jak pilka dotknie paletki
		if (pilka.getPosition().y>680 && pilka.getPosition().y<682) { //to do zmiany kierunku pilki jak dotknie paletki
			dy = -dy;
		}
		else {
			dx = -dx;
		}
	}


	sf::IntRect niewidzialnaTablica[68]; //tak samo jak wyzwj robie z tablica
	for (int i = 0; i < 68; i++) {
		niewidzialnaTablica[i].left = kwadrat[i].getPosition().x;
		niewidzialnaTablica[i].top = kwadrat[i].getPosition().y;
		niewidzialnaTablica[i].height = 50;
		niewidzialnaTablica[i].width = 50;
	}
	for (int j = 0; j < 68; j++) {
		if (niewidzialnaTablica[j].intersects(niewidzialnaPilka)) {
			p = p + 1; //jak pilka dotknie kwadratu to punkty zwikekszaja sie o 1
			if (p == 3) {
				wygrane = wygrane + 1; //jak sie osiagnie jakas liczbe punktow p to wygrane zwiekszaja sie o1 
				std::ofstream plik2("wygrane.txt"); //zapisywanie do pliku
				plik2 << wygrane;
				plik2.close();
			}
			return j;
		}
	}
	return -1;
}

void pagaia::zabijanieKwadratow(int z) { 
	if (z != -1) {
		kwadrat[z].setPosition(2000, 2000); //jak pilka dotknie kwadratu to kwadrat rysuje sie poza gra
		if (pilka.getPosition().y > 270 && pilka.getPosition().y < 300) { //tu do tego jak pilka dotknie kwadratu to sie odbija
			dx = -dx;
		}
		else if (pilka.getPosition().y > 200 && pilka.getPosition().y < 230) {
			dx = -dx;
		}

		else if (pilka.getPosition().y > 130 && pilka.getPosition().y < 160) {
			dx = -dx;
		}
		else if (pilka.getPosition().y > 60 && pilka.getPosition().y < 90) {
			dx = -dx;
		}
		else {
			dy = -dy;
		}
	}
}

void pagaia::pisanie() {
	punkty.setString("Punti: " + std::to_string(p));
}