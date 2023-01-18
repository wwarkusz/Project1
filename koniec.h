#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class koniec
{
public:
	koniec(); //konstruktor
	void draw(sf::RenderWindow& window); //funkcja do rysowania
	int przegrane; //zmienna przegrane do odczytywania z pliku
private:
	sf::Font ksztaltLiter; //do czcionki
	sf::Text end; //do robienia tekstu
	sf::Text END;
	sf::Text PRZEGRANE;

	sf::Texture tlo1; //tekstura
	sf::Sprite tlo11; //i sprite
};

