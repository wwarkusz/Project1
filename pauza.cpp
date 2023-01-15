#include "pagaia.h"

pagaia::pagaia() {

	teksturaPaletki.loadFromFile("aaa.png");
	paletka.setTexture(teksturaPaletki);
	paletka.setTextureRect(sf::IntRect(0, 0, 120, 45));
	paletka.setPosition(400, 700);

	teksturaPilki.loadFromFile("bbb.png");
	pilka.setTexture(teksturaPilki);
	pilka.setTextureRect(sf::IntRect(0, 0, 50, 50));
	pilka.setPosition(400, 500);


	teksturaKwadratow.loadFromFile("ccc.png");
	for (int i = 0; i < 24; i++) {
		kwadrat[i].setTexture(teksturaKwadratow);
		kwadrat[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
	for (int i = 0; i < 7; i++) {
		kwadrat[i].setPosition(i * 70, 20);
	}
	for (int i = 7; i < 13; i++) {
		kwadrat[i].setPosition((i - 6) * 70, 90);
	}

}

void pagaia::draw(sf::RenderWindow& window) {
	window.draw(paletka);
	window.draw(pilka);
	for (int i = 0; i < 24; i++) {
		window.draw(kwadrat[i]);
	}
}

void pagaia::Prawo() {
	if (paletka.getPosition().x < 1000) {
		paletka.move(10, 0);
	}
}

void pagaia::Lewo() {
	if (paletka.getPosition().x > 0) {
		paletka.move(-10, 0);
	}
}

void pagaia::Ruch() {
	pilka.move(dx, dy);
	if (pilka.getPosition().x >= 1000) {
		dx = -dx;
	}
	if (pilka.getPosition().x <= 0) {
		dx = -dx;
	}
	if (pilka.getPosition().y <= 0) {
		dy = -dy;
	}
	if (pilka.getPosition().y >= 700) {
		dy = -dy;
	}
}

void pagaia::odbijanie() {
	sf::IntRect niewidzialneGowno(pilka.getPosition().x, pilka.getPosition().y, 50, 50);
	sf::IntRect niewidzialnyKwadrat(paletka.getPosition().x, paletka.getPosition().y, 120, 45);
	if (niewidzialneGowno.intersects(niewidzialnyKwadrat)) {
		dy = -dy;
	}
}