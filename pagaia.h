#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class pagaia
{
public:
	pagaia(); //konstruktor
	void draw(sf::RenderWindow& window); //do rysowania
	void Prawo(); //do poruszania paletka w prawo
	void Lewo(); //i w lewo
	float dx, dy; //zmienna do ustawiania kierunku poruszania sie pilki
	int Ruch(); //funkcja do poruszania pilki
	int odbijanie(); //funkcja do odbijania
	void zabijanieKwadratow(int z); //do zbijania kwadratow
	void pisanie(); //pisanie zdobytych punktow
	int p; //do zliczania punktow
	int przegrane; //do zliczania przegranych
	int wygrane; //i wygranych

private:

	sf::Texture teksturaPaletki; //tekstura
	sf::Sprite paletka; //i sprite

	sf::Texture teksturaPilki;
	sf::Sprite pilka;

	sf::Texture teksturaKwadratow;
	sf::Sprite kwadrat[68];

	sf::Font ksztaltLiter; //do czcionki
	sf::Text punkty; //do tekstu

	sf::Text help;

	sf::Texture tlo4;
	sf::Sprite tlo44;
};